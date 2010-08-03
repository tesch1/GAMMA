# Python modules
from __future__ import division
import os
import sys

"""
A utility script that cleans up the copy performed in clean_python_lib.py.
"""

major, minor = sys.version_info[:2]

lib_filename = "python%d%d.lib" % (major, minor)

lib_filename = os.path.join(os.getcwd(), "temp_python_lib", lib_filename)

if os.path.exists(lib_filename):
    os.remove(lib_filename)