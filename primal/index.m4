divert(-1)
define(_TITLE, `GAMMA Primal Makefiles')
define(_PRIMALDIR,     `.')
define(_DIRDIR, `../doc/directories')
define(_TOPFONTSIZE,  6)
define(_TOPNAME,      Primal<BR>Makefiles)
define(_CREATION,    `October 10 2002')
define(_CGIDOCNAME,  `primal')
define(_KEYWORDS,   ``<META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation">'')
define(_DESCRIPTION, `<META name="description" content="GAMMA Builds Using Primal Makefiles.">')
define(_JAVASCRIPT, `')
define(_DIR, primal)


define(_PAGEHTML,
      <TABLE border=0 valign="top">
		 <TR>
           <TD valign=top>
             &nbsp;<BR>
             This directory exists to support a fundamental understanding of how building
             GAMMA and GAMMA based programs is accomplished in Unix-like fashion. The builds
             are done using <EM>primal</EM> Makefiles run in a command shell and the C++ compiler
             will be GCC. We refrain from using any IDE (Dev-C++`,' MSVC++`,' Builder) 
             although information on such builds may be found on other pages branching 
             from the main GAMMA version directory. 

             <P>
             These <EM>primal</EM> makefiles do specific builds of GAMMA without all of the
             additional complexities found in the main GAMMA makefile. Without a doubt`,' the 
             main GAMMA makefiles should be used to build GAMMA in most cases. However`,' there
             may be instances when the GNU configuration process simply fails to do the job on
             a particular OS `-' GAMMA version `-' build combination. When that happens`,' 
             users may opt to create a simple Makefile that does the job. These Makefiles do
             direct builds of specific GAMMA computer targets. However`,' if the user has trouble
             building any part of GAMMA`,' hopefully these <EM>primal</EM> Makefiles can be used
             or easily modified to accomplish the desired build.<BR>&nbsp;

             <P>
             <STRONG>GCC</STRONG> is a freely available C++ compiler which runs on most computer
             systems`,' including Windows.  There are two <EM>flavors</EM> of windows GCC`,' one 
             which comes with the <A HREF="_CYGWIN">Cygwin Development Environment (Cygwin)</A>
             and one which is supplied with <A HREF="_MINGW">Minimalist GNU for Windows (MinGW)</A>.
             The <EM>flavor</EM> stems from the fact that Cygwin sets the GCC compiler up to build
             applications which depend upon their own Windows API`,' the DLL cygwin1.dll`,' while
             MinGW sets GCC to use the native MS Windows API. While use of Cygwin is easier
             in many aspects`,' anything built under it can only run on systems that have the
             Cygwin DLL available. It is possible to use the MinGW compiler with the rest of
             the Cygwin enviroment (I call that CygMin).
           </TD>
         </TR>
         <TR>
           <TD>
             <TABLE BORDER=0 CELLSPACING=0 CELLPADDING=0>
               <TR>
                 <TD>
                   The figure at the left below depicts a GAMMA directory structure`,' the directories
                   of importance to the Primal Makefiles ++ are highlighted in blue.
                   (Your directory structure may vary somewhat.)<BR>&nbsp;
                   <TABLE BORDER=0 CELLSPACING=0 CELLPADDING=0>
                     <TR>
		       <TD align="left" valign="top"><IMG SRC="figs/primaldir.gif" HEIGHT=254 WIDTH=120></TD>
                       <TD>
                         <P>
                         There are 3 different types of compiler options supported:
                         <OL>
                          <LI>Using Cygwin GCC (Directories CygWin*)
                          <LI>Using Cygwin + MinGW GCC (Directories CygMin*)
                          <LI>Using MinGW GCC (Directories MinGW*)
                         </OL>
                         And there are different GAMMA library builds:
                         <OL>
                          <LI>Building and Using A Static Library (Directories *Lib)
                          <LI>Building and Using A DLL (Directories *DLL)
                          <LI>Building and Using A PyGAMMA (Directories *PyG)
                         </OL>
                       </TD>
                     </TR>
                   </TABLE>

                  &nbsp;<BR>
                  This accounts for 9 of the primal directories shown.  Each of these 9 directories
                  will contain makefiles for building the (Py)GAMMA library`,' building and
                  running test programs using the library`,' and building and running demonstration
                  programs using the library.  The <EM>figs</EM> directory simply contains figures
                  used in these HTML documentation pages.
                  <P>
                  When one of the primal makefiles is used to produce a GAMMA library it will place it into a binaries
                  directory that indicates the compiler and OS under which the library was built.
                  These are <EM>i686-pc-cygwin32</EM> when the CygWin supplied GCC compiler is used`,'
                  <EM>i686-pc-cygmin32</EM> when the CygWin GCC compiler with MinGW options are used`,'
                  and <EM>i686-pc-mingw32</EM> when the MinGW GCC compiler is used.
                  <P>
                  Why these three compiler options? Mostly because I am currentrly using a PC to do
                  makefile testing. There are three Unix-like flavors of the GCC compiler I like. 
                  The first is provided with the MinGW package. It is nice to use because the binaries
                  produced are <EM>standalone</EM>`,' that is they do not depend on any non-Windows 
                  libraries and can be readily moved from PC to PC. Alternatively`,' Cygwin supplies
                  not only the compiler but a whole Unix
                  environment for the PC. That is a nice thing to have`,' but any binaries produced
                  using its GCC will depend on the Cygwin DLL. Sadly`,' these cannot be moved to
                  and other PC unless that PC also has the Cygwin DLL available. Lastly`,' there is a
                  way to tweak the Cygwin compiler and add in MinGW stuff so that Cygwin has the
                  capabilities of producing <EM>standalone</EM> binaries too. That is a little more
                  work but some may prefer this. I tried all three.
                  <P>
                  Probably the builds with MinGW and CygMin are the best to do since these will
                  enable one to make standalone libraries and GAMMA based programs.
                  <P>
                  The directory <EM>src</EM> is where the GAMMA source codes are kept for a particular
                  version (version 4.1.0 in the figure). It is important that both the GAMMA .cc and .h
                  files are in that directory if you plan to build any GAMMA libraries
                  If you will use a pre-built library to build GAMMA based programs`,' or already have
                  the library built`,' then one needs only the header (.h) files.
                  <P>
                 </TD>
               </TR>
             </TABLE>
           </TD>
         </TR>
		 <TR>
           <TD colspan=2 align=left><STRONG><EM>
		   &nbsp;<BR>
           <FONT SIZE=-1><SUP>*</SUP>&nbsp;PyGAMMA also uses directories that are
                         part of Python & Boost`,' not part of GAMMA. Additionally`,' there are projects
			 which compile and/or run example programs found in the demo and test directories.
           </EM></STRONG></FONT>
         </TD>
         </TR>

       </TABLE>
      )  

include(base.m4)
include(_DIRDIR/base.m4)
include(_BASEDIR/base.m4)
include(_COREDIR/gamma.m4)
divert(0)


_GAMMAPAGE(_TITLE, _BGIMAGE)
