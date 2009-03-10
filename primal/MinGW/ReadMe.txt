                               GAMMA MinGW Binaries

                                  Version 4.1.0

This tar distribution contains GAMMA headers and binaries. The package should
produce a working version of GAMMA on any modern Windows based PC that has
the MinGW package installed (including GCC and MSys). Please note that
the DLL contained herein will NOT be compatible for use with other Windows based
compilers (e.g. MSVC++, Borland).

The file should be unzipped and uncompressed using command line options in a
MinGW/MSys supplied bash shell. Place the tarball into the root directory (/) then
from that directory issue the commands

                               gunzip gamma-4.1.0.tar.gz 
                               tar -xvf gamma-4.1.0.tar

This should place GAMMA binaries into /usr/local/bin and the GAMMA headers into
the /c/gamma/gamma-4.1.0/src (C:\gamma\gamma-4.1.0\src in Windows). The DLL
imports library, libgamma.dll.a, will also be placed into /usr/local/bin. If you
use a Windows GUI unzipping program such as WinZip it will not see the "Unix-like"
directory structure that MinGW/MSys uses.

This tarball originated from the GAMMA WWW site at:

        http://gamma.magnet.fsu.edu/download/binary/mingw/index.html


