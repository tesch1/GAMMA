# Python modules
from __future__ import division
import distutils.core
import sys
import os
import tempfile
import shutil
####################   About adding imports   ####################
# Since Python 2.4 is still fairly prevalent (thanks in part to RHEL and
# CentOS), it seems likely that people will try to run this under Python
# 2.4 or maybe even 2.3. We can inform them gracefully when we detect an
# inadequate Python. However, if we attempt any imports here that assume the
# Python 2.5 standard lib is available, Python will raise an ImportError and
# the code will die here before we can warn them gracefully. So don't do that!
#
# Python 2.2 is really old; we don't need to worry about it.
#
# There's only a few modules/packages in 2.5 that aren't in 2.3/2.4 that
# you're likely to want to use here. If you need one, avoid importing it
# here; do so later in the code once we've verified Python >= 2.5. Here's
# a list of modules that were new in Python 2.5 --
#   - The ctypes package
#   - The ElementTree package
#   - The hashlib package
#   - The sqlite3 package

# Also note that if you include Python syntax that's 2.5-specific, older
# Pythons will fail gracelessly when they try to run this. The three things
# that you'd be most likely to tempted to use here which aren't in
# Python <= 2.5 are --
#   - The Set type
#   - The Decimal type
#   - The ternary if statement, e.g. --
#           beverage = "tea" if (meal == "breakfast") else "beer"

# Check Python version ASAP
major, minor = sys.version_info[0:2]

if (major < 2) or (minor < 5):
    msg = "Sorry, this is Python %d.%d " % (major, minor)
    msg += "and PyGAMMA requires Python >= 2.5."
    print msg
    sys.exit(-1)

# OK, now I know we're running Python >= 2.5 so now I can do my imports
# that are Python 2.5-specific.

cleanup = None

# The VERSION file will be in the current dir if this is being run from an
# expanded tarball/ZIP file (i.e. a normal end user distro) or in the parent
# dir if this is being run from an SVN tree. The latter is not just a 
# developer-only thing. End users will need to use it if they're compiling
# their own binaries.
version_path = "VERSION"
if not os.path.exists(version_path):
    version_path = os.path.join("..", version_path)

version = open(version_path, "rb").read().strip()

NAME = "pygamma"
DESCRIPTION = "The Pythonized version of the GAMMA C++ Library."
LONG_DESCRIPTION = ""
MAINTAINER = "David Todd"
MAINTAINER_EMAIL = "david.todd@va.gov"
URL = "http://scion.duhs.duke.edu/svn/gamma/"
DOWNLOAD_URL = "https://scion.duhs.duke.edu/vespa/gamma/wiki/PyGamma"
PY_MODULES = ["pygamma"]
# http://pypi.python.org/pypi?:action=list_classifiers
CLASSIFIERS = [ 'Development Status :: 4 - Beta',
                'Intended Audience :: Science/Research',
                "License :: OSI Approved :: BSD License",
                "Operating System :: MacOS :: MacOS X",
                "Operating System :: POSIX :: Linux",
                "Operating System :: POSIX :: SunOS/Solaris",
                "Operating System :: Microsoft :: Windows",
                "Operating System :: Unix",
                ]
LICENSE = "http://creativecommons.org/licenses/BSD/"
KEYWORDS = "GAMMA pygamma MRI MR Spectroscopy"


def list_files(path, ignore_dot_py=False):
    """Given a path, returns a list of the files found there. The files
    returned are just names; they're not fully qualified.

    Directories, files that start with '.' and .pyc files are always excluded.
    If ignore_dot_py is True, .py files are also excluded.

    This function doesn't travel into subdirectories.
    """
    filenames = [ ]

    checks = [ ]

    # I implement the checks as a series of functions. Implementing them 
    # as an if statement when one of them was optional (an iffy if) was 
    # complicated.
    checks.append(lambda filename: os.path.isfile(os.path.join(path, filename)))
    checks.append(lambda filename: not filename.startswith("."))
    checks.append(lambda filename: not filename.endswith(".pyc"))
    if ignore_dot_py:
        checks.append(lambda filename: not filename.endswith(".py"))

    all_checks = lambda filename: all([check(filename) for check in checks])

    for filename in os.listdir(path):
        if all_checks(filename):
            filenames.append(filename)

    return filenames


class PlatformSniffer(object):
    """A class to sniff out three pieces of platform data that are
    important to me. The class does nothing other than to examine the
    platform during __init__() and then summarize its findings when
    converted to a string.

    The three pieces of data that I care about are the platform name
    (normalized to "osx", "linux" or "win"), whether or not Python is compiled
    in 32 or 64 bit mode, and the major & minor Python version numbers.
    """
    def __init__(self):
        # Python version is easy to get
        self.python_version = "%d%d" % sys.version_info[:2]

        # Get 32/64 bit mode info.
        #
        # There's no official way to do this but the canonical way appears
        # to be to test the value of sys.maxint and see whether or not it
        # is a 32- or 64-bit long.
        # ref: http://stackoverflow.com/questions/1405913/how-do-i-determine-if-my-python-shell-is-executing-in-32bit-or-64bit-mode
        # Don't succumb to the temptation to use a ternary if statement here;
        # see comment at the top.
        if sys.maxint == 2147483647:
            self.bits = 32
        else:
            self.bits = 64

        # Get & normalize the platform name
        self.platform = sys.platform.lower()

        # In the list of elifs below, the check for "darwin" has to go before
        # the check for "win" (because darwin contains "win").
        if "linux" in self.platform:
            self.platform = "linux"
        elif "darwin" in self.platform:
            self.platform = "osx"
        elif "win" in self.platform:
            self.platform = "win"
        #else:
            # This is some other platform which we don't support, so it 
            # doesn't need to be normalized.


    def __str__(self):
        """Formats platform info to match the style of the prebuilt
        directory names.
        """
        return "%s-%s-py%s" % (self.platform, self.bits, self.python_version)


########################     Main  starts  here   #####################

# This install requires some file shuffling. The shuffling is driven by 
# distutils' requirement that everything that I want installed in a package 
# must be in the same directory when I called distutils.core.setup().

# Unfortunately, the files I want to install come from several different 
# locations which I can only determine at runtime. (See the comments and code
# below for details.) So I figure out which files I need and then copy them 
# all into a temp directory and pass that directory to distutils.core.setup(). 

# The first decision I need to make at runtime is which PyGAMMA binaries to
# install. We provide binaries for common platforms in the prebuilt directory,
# but we won't satisfy everyone and those users will have to build their own.
# In addition, some may prefer their own version to the prebuilt ones we 
# offer.

# Binaries built by the user always land in the homemade directory, and if we
# find binaries there we always prefer them to prebuilt ones.

# Another wrinkle is that homemade binaries come with a pygamma_version.py
# file whereas the prebuilt binaries don't. This code, therefore, needs to 
# write that file if it doesn't exist.

# Last but not least, both homemade and prebuilt binaries have to have an
# __init__.py installed alongside them to make pygamma a proper package.
# Many __init__.py files are blank; this one is not. In order to manage the
# source code somewhat sanely, I put the code in a file called init.py and
# copy it to temp_dir/__init__.py during this setup. That way the file is
# under source code management but no one will think that it's meant to make
# the setup.py directory a package.




# cwd = current working directory
cwd = os.getcwd()

# See if there's useful homemade files 
bin_path = os.path.join(cwd, "homemade")

filenames = list_files(bin_path)

use_homemade_binary = \
            any([filename.startswith("_pygamma") for filename in filenames])

if use_homemade_binary:
    # Found homemade files; install can continue
    print "Using homemade binaries..."
else:
    # No homemade files. See if there's anything useful in prebuilt. This
    # code will only use a prebuilt directory if (a) the directory name 
    # matches the current platform and (b) the directory is not empty.

    # platform will be something like "osx-32-py25"
    platform = str(PlatformSniffer())
    
    bin_path = os.path.join(cwd, "prebuilt", platform)

    if os.path.exists(bin_path):
        filenames = list_files(bin_path)
        if filenames:
            # Bingo! The path exists and is not empty.
            print "Using prebuilt binaries from %s..." % platform
            filenames = list_files(bin_path)
    else:
        # No prebuilt binaries were found. The install will fail.
        filenames = [ ]


if filenames:
    temp_dir = tempfile.mkdtemp()
    
    if not use_homemade_binary:
        # When using prebuilt binaries, I have to write the pygamma_version.py
        # file.
        s = "__version__ = '%s'" % version
        open(os.path.join(temp_dir, "pygamma_version.py"), "w").write(s)

    # Copy everything in filenames to the temp directory
    for filename in filenames:
        shutil.copy(os.path.join(bin_path, filename), temp_dir)
    
    # Copy & rename init.py ==> __init__.py
    shutil.copy("init.py", os.path.join(temp_dir, "__init__.py"))
else:
    # No binary files. We can't continue.
    print """
Sorry, setup doesn't have binaries for your platform and Python version.
You'll have to make them yourself by following the instructions here:
http://scion.duhs.duke.edu/vespa/gamma/wiki/PyGamma
"""
    sys.exit(-1)


# package_data tells setup about files other than .py that I want copied.
# I grab everything in the bin directory that's not a .py file and stuff it
# into package_data.

package_dir = { "pygamma" : temp_dir }

package_data = { "pygamma" : list_files(temp_dir, True) }

packages = [ "pygamma" ]

distutils.core.setup(name=NAME,
                     version=version,
                     package_dir=package_dir,
                     packages=packages,
                     package_data=package_data,
                     url=URL,
                     maintainer=MAINTAINER,
                     maintainer_email=MAINTAINER_EMAIL,
                     )

# Clean up.
for filename in os.listdir(temp_dir):
    os.remove(os.path.join(temp_dir, filename))
os.rmdir(temp_dir)
