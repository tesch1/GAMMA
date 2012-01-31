from __future__ import division

import shutil
import struct
import sys
import os

"""A utility script that handles the post-build events for the PyGAMMA 
library. It performs several tasks --

1) Copies the PyGAMMA binary (_pygamma.pyd) and the SWIG shell (pygamma.py)
to gamma/pygamma/homemade
2) Copies those same files to the appropriate prebuilt directory
3) Writes pygamma_version.py to gamma/pygamma/homemade
4) Cleans up (deletes) the pythonxx.lib copy created by clean_python_lib.py

MSVC runs this script as a post-build step.
"""

# Method of determining Python 32/64-bit mode from here:
# http://stackoverflow.com/questions/1405913/how-do-i-determine-if-my-python-shell-is-executing-in-32bit-or-64bit-mode
bitiness = 8 * struct.calcsize("P")

prebuilt_dir = "win-%d-py%d%d" % (bitiness, sys.version_info[0], 
                                            sys.version_info[1])

copy_these = ( ("../../../i686-pc-msvc/_pygamma.pyd", 
                "../../../pygamma/homemade/_pygamma.pyd"),
               ("../../../i686-pc-msvc/pygamma.py", 
                "../../../pygamma/homemade/pygamma.py"),
               ("../../../i686-pc-msvc/_pygamma.pyd", 
                "../../../pygamma/prebuilt/%s/_pygamma.pyd" % prebuilt_dir),
               ("../../../i686-pc-msvc/pygamma.py", 
                "../../../pygamma/prebuilt/%s/pygamma.py" % prebuilt_dir),
             )

for source, destination in copy_these:
    print "Copying %s to %s..." % (source, destination) 
    shutil.copyfile(source, destination)


version = open("../../../VERSION").read().strip()

version = "__version__ = '%s'" % version

open("../../../pygamma/homemade/pygamma_version.py", "wb").write(version)


# Clean up the pythonxx.lib copy created by clean_python_lib.py.
major, minor = sys.version_info[:2]

lib_filename = "python%d%d.lib" % (major, minor)

lib_filename = os.path.join(os.getcwd(), "temp_python_lib", lib_filename)

if os.path.exists(lib_filename):
    os.remove(lib_filename)
