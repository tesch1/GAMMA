###############################################################################
#                                                                             #
#             Macros For The GAMMA WWW Site & Local Documentation             #
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
# HTML Pages That Are Available For Local Copies Of GAMMA Documentation.      #
#                                                                             #
###############################################################################
 
###############################################################################
#                                                                             #
# The definitions file are intended to be used by ALL GAMMA pages farther     #
# down in the hierarchy.  That is, all subdirectories from here (except core  #
# and figs) will ultimately include this file & know these macro definitions. #
# This is why it is important NOT to define anything herein that will not     #
# apply to all pages from this directory on down.                             #
#                                                                             #
# _LOCAL      - Indicates whether local documentation or WWW site {yes,no}    #
# _WWWSERVER  - Base of served pages -> http://"_WWWSERVER" + /pagename       #
# _USEFOOTER  - Output A Footer (Server May Do This By Itself)                #
# _USEMODDAT  - Output Last Modification Date in Footer                       #
# _USECOUNTER - Output Page Access Count in Footer                            #
#                                                                             #
###############################################################################

###############################################################################
#                SAMPLE MACROS USED IF LOCAL DOCUMENTATION                    #
###############################################################################

define(_LOCAL,       yes) 
define(_WWWSERVER,   gamma.magnet.fsu.edu)
define(_CGISERVER,   gamma.magnet.fsu.edu)
define(_FTPSERVER,   gamma.magnet.fsu.edu)
define(_GAMMALOCAL, "http://`_WWWSERVER'/")
define(_GAMMALOCNAME, Osaka)
define(_MAILLOCAL,  "gamma@magnet.fsu.edu")
define(_MAILLOCNAME, )
define(_USEFOOTER,   yes)
define(_USEMODDATE,  yes)
define(_USECOUNTER,  no)
define(_CGICOUNTER, `/cgi/counter.cgi');
define(_WWWSITE,     `USA G2')
ifelse(_MIR, `mir', 
   `define(_AREA, `mirrors')',
   `ifelse(_LOCAL, no, `define(_AREA, home)', `define(_AREA, local)')')

###############################################################################
#                    MACROS USED FOR LOCAL VS WWW SITES                       #
###############################################################################

ifelse(_GAMMALOCAL, `', `define(_LINK2LOCAL, `')',
                        `define(_LINK2LOCAL, <A HREF=_GAMMALOCAL>_GLOCALSITE</A>)')

ifelse(_MAILLOCAL, `', `define(_LOCALMAIL, `')',
                       `define(_LOCALMAIL, gamma@magnet.fsu.edu)')

ifelse(_LINK2LOCAL, `', `define(_LILOCGLINK, _NIL)',
                        `define(_LILOCGLINK, <TR>
                                             <TD><LI>_GSYMSTRONG Local WWW:</TD>
                                             <TD><font color="blue"><A HREF=_GAMMALOCAL>_GAMMALOCNAME</A></font></TD>
                                             </TR>)')

ifelse(_LOCALMAIL, `', `define(_LILOCGMLINK, _NIL)',
                       `define(_LILOCGMLINK, <TR>
                                            <TD><LI>_GSYMSTRONG Local Mail:</TD>
                                            <TD><font color="blue"><A HREF="mailto:_MAILLOCAL">_MAILOCNAME</A></font></TD>
                                            </TR>)')


###############################################################################
#                          MACROS USED IN ALL CASES                           #
###############################################################################

define(_COREDIR,     `_BASEDIR/doc/core')
define(_FIGDIR,      `_BASEDIR/doc/figs')
define(_BGIMAGE,     `_FIGDIR/bkground.gif')
define(_NSIGN4,  ````#'''')
define(_NSIGN3,  ```#''')
define(_NSIGN2,  ``#'')
define(_NSIGN1,  `#')
define(_GSYMSTRONG,  &`'_NSIGN4`'915;)
define(_GAMMA, &`'_NSIGN3`'915;)
define(_BETA,  &`'_NSIGN4`'946;)
define(_NU,    &`'#`'957;)
define(_GVERSION,     4.1.0)
define(_GVERLEV0, 4)
define(_GVERLEV1, 0)
define(_GSUBVER,  6)
#define(_GSYMSTRONG,   <FONT face="symbol">G</FONT>)
#define(_GVERSION,     4.0.4 <FONT face="symbol">b</FONT>)
