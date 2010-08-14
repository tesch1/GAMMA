# Python modules
from __future__ import division
import os
import tarfile
import zipfile as zipfile_module
import hashlib

"""A developer tool that builds bundles (a tarballs and a ZIP file) and
hash files suitable for distribution to end users.

This works by examining the list of prebuilt directories on the fly combining
them into an all-in-one mega bundle that contains the binaries for all
platforms.

It might be nicer to create platform-specific bundles rather than cramming
all of them into one, and it wouldn't be difficult code to write. I chose
one mega binary because it's simpler code here and (more importantly) simpler
for the user.

Python's distutils package has some support for this kind of packaging via
the sdist command. I tried to use it, and shoehorning it into PyGAMMA's
setup.py alongside the install command was more trouble than it was worth.
"""

# TARGET_DIR is where the bundles & hash files get created.
TARGET_DIR = "dist"

VERSION = open(os.path.join("..", "VERSION")).read().strip()

BUNDLE_DIR = "pygamma-%s" % VERSION

# standard files are included regardless of what platform the bundle is
# being built for.
STANDARD = ["setup.py",
            "init.py",
            "homemade",
            os.path.join("..", "LICENSE"),
            os.path.join("..", "README"),
            os.path.join("..", "VERSION"),
            ]


def list_files(path):
    """Given a path, returns a list of the files found there. The files
    returned are just names; they're not fully qualified.

    Directories, files that start with '.' and .pyc files are excluded.

    This function doesn't travel into subdirectories.
    """
    filenames = [ ]

    for filename in os.listdir(path):
        # Exclude non-files, files that start with a dot, and compiled Python
        # files
        if os.path.isfile(os.path.join(path, filename))     and \
           not filename.startswith(".")                     and \
           not filename.endswith(".pyc"):
            filenames.append(filename)

    return filenames


def build_bundles(target_path, filenames):
    """Given a target filename and a list of files, builds a tarball & ZIP
    file containing the files named in the filenames param. Also creates
    MD5 and SHA1 hash files for each tarball & ZIP file.

    target_path should be the path (fully qualified or relative) and name of
    the tarball/ZIP file minus the extension, e.g. "pygamma-4.2.0",
    "dist/pygamma-4.2.0.linux-32-py25" or "pygamma-4.2.0.all".

    The filenames in files must be relative to the current working directory.
    """
    print "Building the tarball and ZIP file..."

    tarball_name = target_path + ".tar.gz"
    zipfile_name = target_path + ".zip"

    # Clean up old stuff to ensure that I don't append to an existing
    # tarball or zip file.
    if os.path.exists(tarball_name):
        os.remove(tarball_name)
    if os.path.exists(zipfile_name):
        os.remove(zipfile_name)

    zipfile = zipfile_module.ZipFile(zipfile_name, "w",
                                     zipfile_module.ZIP_DEFLATED)
    tarball = tarfile.open(tarball_name, "w:gz")

    for filename in filenames:
        print "Adding %s..." % filename

        # Note that both ZIP files and tarballs support giving the file a
        # different name in the bundle. Most of our files don't need to change
        # name, but a few do.
        # Specifically, of our files come from the directory above current,
        # and neither tar nor zip support unbundling files above the
        # current directory.
        bundle_name = filename

        if bundle_name.startswith(".."):
            # This is ../VERSION or one of its siblings. Once in the bundle,
            # these should be in the root so I trim the reference to "../".
            bundle_name = bundle_name[3:]
            
        bundle_name = os.path.join(BUNDLE_DIR, bundle_name)

        tarball.add(filename, bundle_name, False)

        # ZIP files are a little more difficult.
        if os.path.isdir(filename):
            # Trouble here. Either the ZIP format or Python's interface
            # to it doesn't really support empty directories. The
            # workaround is to add a trailing path separator to the
            # filename and write it as an empty string.
            # ref: http://bytes.com/topic/python/answers/19053-add-empty-directory-using-zipfile
            zipfile.writestr(bundle_name + os.sep, "")
        else:
            zipfile.writestr(bundle_name, open(filename).read())

    zipfile.close()
    tarball.close()

    # Generate the MD5 & SHA1 hashes
    print "Generating hashes..."

    for bundle_name in (tarball_name, zipfile_name):
        s = open(bundle_name).read()
        md5 = hashlib.md5(s).hexdigest()
        sha1 = hashlib.sha1(s).hexdigest()

        open(bundle_name + ".md5.txt", "wb").write(md5)
        open(bundle_name + ".sha1.txt", "wb").write(sha1)


#########################    Main  starts  here   #########################


cwd = os.getcwd()

# Ensure the TARGET_DIR exists because that's what I write to.
dist_dir = os.path.join(cwd, TARGET_DIR)
if not os.path.exists(dist_dir):
    os.mkdir(dist_dir)

# Enumerate the platforms for which I have prebuilt binaries.
prebuilt_dir = os.path.join(cwd, "prebuilt")

prebuilts = os.listdir(prebuilt_dir)

# This function determines whether or not a path in prebuilt looks
# like one of my "special" directories. It has to have two dashes
# in the name, e.g. linux-32-py25
f = lambda path: os.path.isdir(path) and (path.count("-") == 2)

prebuilts = [path for path in prebuilts if f(os.path.join(prebuilt_dir, path))]

prebuilts.sort()

# Building the mega-distribution that bundles all binaries into one is
# quite similar to the above.
print "\nBuilding mega-distribution..."
files = STANDARD
for prebuilt in prebuilts:
    print "Processing %s..." % prebuilt

    path = os.path.join(cwd, "prebuilt", prebuilt)

    files += [os.path.join("prebuilt", prebuilt, file_) for file_ in \
                                                            list_files(path)]

files.sort()

bundle_name = "pygamma-%s" % VERSION

bundle_name = os.path.join("dist", bundle_name)

build_bundles(bundle_name, files)

print '\nDone! The bundles are in the "%s" directory.' % TARGET_DIR

