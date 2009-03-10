###############################################################################
#                                                                             #
#              Macros For The GAMMA WWW Site Information Documentation        #
#                     Copyright (C) 1999 Scott A. Smith                       #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# These macros are used with the m4 program in generating a GAMMA WWW site.   #
# You may NOT give this file away nor modify it in any way without permission #
# from S.A. Smith.  GAMMA WWW site mirrors are forbidden without permission   #
# from S.A. Smith.  The Macro Definitions Herein Should Apply To ALL GAMMA    #
# HTML Pages That Are Available For Local Copies Of Info Documentation.       #
#                                                                             #
###############################################################################

define(_BORLAND,      http://www.borland.com/)
define(_CYGWIN,       http://www.cygwin.com/)
define(_MINGW,        http://www.mingw.org/)
define(_PYTHON,       http://www.python.org/)
define(_BOOST_PYTHON, http://www.boost.org/libs/python/doc/)
define(_LINUX,        http://www.linux.org/)

define(_PYG_, `<FONT FACE=symbol>pG</FONT>')
define(_PRIMALDIR, `.')

define(_PRIMALCYGWINDIR, _PRIMALDIR/CygWin/index.html)
ifelse(_SUBDIR, cygwin, `define(_PRIMALCYGWINCOLOR, _HLCOLOR)',
                        `define(_PRIMALCYGWINCOLOR, _ULCOLOR)')
define(_PRIMALCYGWINLINKS,   _SUBSUBLINKURL(_PRIMALCYGWINDIR, _PRIMALCYGWINCOLOR, CygWin))

define(_PRIMALCYGMINDIR, _PRIMALDIR/CygMin/index.html)
ifelse(_SUBDIR, cygmin, `define(_PRIMALCYGMINCOLOR, _HLCOLOR)',
                        `define(_PRIMALCYGMINCOLOR, _ULCOLOR)')
define(_PRIMALCYGMINLINKS,   _SUBSUBLINKURL(_PRIMALCYGMINDIR, _PRIMALCYGMINCOLOR, CygMin))


define(_PRIMALMINGWDIR, _PRIMALDIR/MinGW/index.html)
ifelse(_SUBDIR, mingw, `define(_PRIMALMINGWCOLOR, _HLCOLOR)',
                       `define(_PRIMALMINGWCOLOR, _ULCOLOR)')
define(_PRIMALMINGWLINKS,   _SUBSUBLINKURL(_PRIMALMINGWDIR, _PRIMALMINGWCOLOR, MinGW))

define(_PRIMALIRIXDIR, _PRIMALDIR/Irix/index.html)
ifelse(_SUBDIR, irix, `define(_PRIMALIRIXCOLOR, _HLCOLOR)',
                      `define(_PRIMALIRIXCOLOR, _ULCOLOR)')
define(_PRIMALIRIXLINKS,   _SUBSUBLINKURL(_PRIMALIRIXDIR, _PRIMALIRIXCOLOR, Irix))

define(_PRIMALLINUXDIR, _PRIMALDIR/Linux/index.html)
ifelse(_SUBDIR, linux, `define(_PRIMALLINUXCOLOR, _HLCOLOR)',
                       `define(_PRIMALLINUXCOLOR, _ULCOLOR)')
define(_PRIMALLINUXLINKS,   _SUBSUBLINKURL(_PRIMALLINUXDIR, _PRIMALLINUXCOLOR, Linux))

define(_PRIMALOSXDIR, _PRIMALDIR/OSX/index.html)
ifelse(_SUBDIR, osx, `define(_PRIMALOSXCOLOR, _HLCOLOR)',
                     `define(_PRIMALOSXCOLOR, _ULCOLOR)')
define(_PRIMALOSXLINKS,   _SUBSUBLINKURL(_PRIMALOSXDIR, _PRIMALOSXCOLOR, OSX))

define(_PRIMALBORLANDDIR, _PRIMALDIR/Borland/index.html)
ifelse(_SUBDIR, borland, `define(_PRIMALBORLANDCOLOR, _HLCOLOR)',
                         `define(_PRIMALBORLANDCOLOR, _ULCOLOR)')
define(_PRIMALBORLANDLINKS,  _SUBSUBLINKURL(_PRIMALBORLANDDIR, _PRIMALBORLANDCOLOR, Borland))


################################################################################
# Redefine _PRIMALDIRLINKS (Directories Definition) So Highlighted & SubSections #
################################################################################

define(_PRIMALDIRLINKS,
       <FONT size=-2><STRONG>
       <BR><A HREF="_PRIMALDIR/index.html" TARGET="_top"><FONT color="_HLCOLOR">&nbsp;&nbsp;&middot;&nbsp;Primal Makefiles</FONT></A>
       _PRIMALCYGWINLINKS
       _PRIMALMINGWLINKS
       _PRIMALCYGMINLINKS
       _PRIMALLINUXLINKS
       _PRIMALIRIXLINKS
       _PRIMALOSXLINKS
       _PRIMALBORLANDLINKS
       </STRONG></FONT> )

