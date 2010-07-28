# Python modules
from __future__ import division
import distutils.core
import distutils.command.install
import sys
import os
import platform
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

# FIXME - metadata is incomplete or wrong

VERSION = "4.2.0"
NAME = "pygamma"
DESCRIPTION = "The Pythonized version of the GAMMA C++ Library."
LONG_DESCRIPTION = ""
MAINTAINER = "David Todd"
MAINTAINER_EMAIL = "david.todd@va.gov"
URL = "http://scion.duhs.duke.edu/svn/gamma/"
DOWNLOAD_URL = "https://scion.duhs.duke.edu/vespa/gamma/wiki/PygammaDownload/pygamma-%s.tar.gz" % VERSION
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

# Set up the data that's to be passed to distutils.core.setup().

packages = [ "pygamma" ]

package_dir = { "pygamma" : "homemade" }


# package_data tells setup about files other than .py that I want copied.
# At present all three platforms (OSX, Linux & Windows) need just one of
# these: _pygamma.dll on Windows and _pygamma.so elsewhere.
# Rather than hardcode the name and limit myself to just one file (even
# though there probably never will be more than one), I just grab everything 
# in the bin directory that's not a .py file and stuff it into package_data. 
package_data = [ ]

bin_path = os.path.join(os.getcwd(), "homemade")

for filename in os.listdir(bin_path):
    # Exclude non-files, files that start with a dot, and Python files
    if os.path.isfile(os.path.join(bin_path, filename))     and \
       not filename.startswith(".")                         and \
       not filename.endswith(".py")                         and \
       not filename.endswith(".pyc"):
        package_data.append(filename)
        
# FIXME -- need to add code that squawks if package_data is empty. That 
# means they haven't run make yet.
        
package_data = { "pygamma" : package_data }



distutils.core.setup(name=NAME,
                     version=VERSION,
                     package_dir=package_dir,
                     packages=packages,
                     package_data=package_data,
                     url=URL,
                     maintainer=MAINTAINER,
                     maintainer_email=MAINTAINER_EMAIL,
                     )
