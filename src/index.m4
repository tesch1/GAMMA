divert(-1)
define(_TITLE, `GAMMA Sources')
define(_DIRDIR, `../doc/directories')
define(_TOPFONTSIZE, 6)
define(_TOPNAME, Sources)
define(_CREATION,    `September 23 2002')
define(_CGIDOCNAME,  `srcdir')

define(_KEYWORDS,    ``
  <META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation"> '')

define(_DESCRIPTION, `<META name="description" content="GAMMA Sources.">')
define(_JAVASCRIPT, `')

define(_DIR, src)

define(_PAGEHTML,
      <TABLE border=0 valign="top">
         <TR>
           <TD colspan=2>
             &nbsp<BR>
             As one might expect`,' the source directory contains all the GAMMA source codes`,'
             including those required for PyGAMMA.  The sources contains C++ code files (*.cc)
             and C++ header files (*.h). With these files users may build GAMMA on a host
             system if there is a viable C++ compiler. Similarly`,' one can build PyGAMMA if
             there is a viable C++ compiler`,' Python`,' and Boost.Python on the system. 
             
             <P>
             If your intent is to build (Py)GAMMA from 
             scratch<SUP><A HREF="#BIN"><font color="blue">*</font></A></SUP> 
             then you should have the full set of source codes. If simply using a pre-built
             (Py)GAMMA library then the headers will suffice. That is`,' once you have a (Py)GAMMA
             library you no longer need the C++ code files (*.cc) but you do need the header
             files (*.h).<BR>&nbsp;
           </TD>
         </TR>
         <TR>
           <TD>
             <IMG SRC="_FIGDIR/src401.gif" WIDTH=122 HEIGHT="384">
           </TD>
           <TD valign="top" align="top">
             The figure shows the files and sub-directories produced when the GAMMA source 
             distribution for gamma-4.1.0 is uncompressed from the base directory <EM>gamma</EM>.
             When uncompressed the directory gamma-4.1.0 is produced as well as the files and 
             sub-directories therein. One of these directories in <EM>src</EM>`,' the one which
             we are currently describing.
             <P>
             During a (non-IDE) GAMMA build you will change into the version directory (gamma-4.1.0)
             and run the configure program in order to produde a viable makefile`,' <EM>Makefile</EM>`,' 
             and gamma script`,' <EM>gamma</EM>. 
             <P>
             You MUST have a C++ compiler installed.  If you do not have a compiler you should first
             install one`,'  a subject also also discussed in the <A HREF="../doc/install/index.html">Installation</A> 
             link to your left.  The actual GAMMA source codes will be in module directories under GAMMAVER/src.
             The two ReadMe files provide basic information on how to build GAMMA`,' albeit not as detailed 
             as that found under <A HREF="../doc/install/index.html">Installation</A>.  The README.html can server
             as the starting page for all GAMMA documentation. 
             <P>
           </TD>
         </TR>
         <TR>
           <TD colspan=2>
             <font size="-1">
             The latest source code package distributon will always be on the <font face="symbol">G</font>
             WWW site under <STRONG><EM>ftp/gamma/src/latest.tar.gz</EM></STRONG>. Here are direct
             links to download the latest one (if this fails try another WWW site):
             </font>
           </TD>
         </TR>
         <TR>
           <TD align="center" colspan=2>
             <TABLE>
               <TR> 
                 <TH>Unix Gnuzip</TH>
                 <TH>&nbsp;</TH>
                 <TH>Windows Zip</TH>
               </TR>
               <TR> 
                 <TD align=center><A HREF="http://_FTPSERVER/ftp/src/latest.tar.gz"><FONT color="blue">latest.tar.gz</FONT></A></TD>
                 <TD>&nbsp;</TD>
                 <TD align=center><A HREF="http://_FTPSERVER/ftp/src/latest.zip"><FONT color="blue">latest.zip</FONT></A></TD>
               </TR>
             </TABLE>
           </TD>
         </TR>
         <TR>
           <TD colspan=2>
             <font size="-1">
             Directions for installing and building GAMMA from sources can be found under
             the <EM><A HREF = "../doc/install/index.html"><font color="blue">Installation</font></A></EM>
             link to your left. The source package FTP directory may be accessed directly at
             &nbsp;<STRONG><EM><A HREF="http://_FTPSERVER/ftp/src/"><FONT color="blue">/ftp/src</FONT></A>
             </EM></STRONG> or indirectly (with a description) on 
             &nbsp;<STRONG><EM><A HREF="http://_FTPSERVER/ftp/src/ReadMe.html"><FONT color="blue">/ftp/src/ReadMe.html</FONT></A></EM></STRONG>. 
             </font>
             <BR>&nbsp;
           </TD>
         </TR>
         <TR>
           <TD colspan=2>
             <CENTER><STRONG><A NAME="BIN">Precompiled GAMMA and PyGAMMA Libraries</A></STRONG></CENTER>
             <P>
             <A NAME="BIN">Pre</A>-compiled GAMMA and PyGAMMA libraries are available for a select few
             OS/Compiler combinations. This may be the most convenient way of getting GAMMA and PyGAMMA
             running on Windows based PC systems since it is an easy platform to support in this manner.
             Users of one of the many Unix based systems are encouraged to do the build using the GAMMA
             Makefile. This has worked well in the past for SGI Irix`,' Sun SPARC`,' Linux`,' and OSX. 
             It also works fine on PC systems using CygWin or MinGW`,' but typically prebuilt libraries
             are available for these. As for users of MSVC++ under Windows`,' prebuilt libraries are
             also usually available`,' but Workspaces are provided to simplify any (Py)GAMMA builds.
           </TD>
         </TR>
       </TABLE>
      )  

include(_DIRDIR/base.m4)
include(_BASEDIR/base.m4)
include(_COREDIR/gamma.m4)
divert(0)

_GAMMAPAGE(_TITLE, _BGIMAGE)
