from __future__ import division

import distutils.sysconfig

"""A utility script that writes Python's include directory into a compiler
/I switch. That is then written to a file and that file is passed by MSVC
to cl.exe via the @ option.

MSVC runs this script as a pre-build step.
"""

path = distutils.sysconfig.get_python_inc()

path = '/I "%s"' % path 

open("python_include_path.rsp", "w").write(path)

# This script is useful because it means the user doesn't have to set the 
# Python include path manually. We'd like to do the same for the path to 
# python2x.lib but unfortunately that's surprisingly difficult. Three things
# that almost worked --
# 
# The @ option (to pass a compiler response file) is supported for link.exe.
# It would be trivial to use code similar to that above to write a file 
# like "python_lib_path.rsp" that contains /LIBPATH:c:\python25\libs. However, 
# the doc clearly states that the @ option for link.exe doesn't work within
# MSVC.
# ref: http://msdn.microsoft.com/en-us/library/4xdcbak7.aspx
# 
# The cl.exe /link option can pass options to link.exe, and the @ option works
# for cl.exe in MSVC. So theoretically we could add to the
# python_include_path.rsp file that's passed to cl.exe something like this:
#    /link /LIBPATH:c:\python25\libs
#    
# But MSVC executes cl.exe with the /c option (== compile only). link.exe is
# executed explicitly by MSVC, so cl.exe never gets the opportunity to pass 
# the contents of the /link option to link.exe.
# 
# Finally, one can alter the build config on the fly via macros, but macros 
# are not supported in MSVC 2008 Express Edition which we and (we expect) 
# many of our users use.
