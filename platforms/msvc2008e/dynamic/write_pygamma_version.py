# Python modules
from __future__ import division
import os
import sys

"""
A utility script that writes the PyGAMMA version to a .py file during the
post-build event.
"""

version = open("..\\..\\..\\VERSION").read().strip()

version = "__version__ = '%s'" % version

open("..\\..\\..\\pygamma\\homemade\pygamma_version.py", "w").write(version)
