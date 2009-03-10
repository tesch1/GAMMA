divert(-1)
define(_TITLE, `GAMMA Builds Using Cygwin With MinGW')
define(_PRIMALDIR, `..')

define(_DOCDIR, `../../doc')
define(_DIRDIR, `../../doc/directories')

define(_TOPFONTSIZE, 5)
define(_TOPNAME, Cygwin + MinGW<BR>Builds & Targets)
define(_CREATION,    `September 23 2002')
define(_CGIDOCNAME,  `cygmin')
define(_KEYWORDS,    ``
  <META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation">'')
define(_DESCRIPTION, `
  <META name="description" content="GAMMA Builds Using The Cygwin Environment + MinGW.">')
define(_JAVASCRIPT, `')
define(_SUBDIR, cygmin)


define(_PAGEHTML,
      <TABLE border=0 valign="top">
        <TR>
          <TD valign=top>
            <BLOCKQUOTE><STRONG><FONT SIZE="-1">
            GAMMA libraries & progams produced by this Makefile will depend upon Cygwin. That is`,'
            they will not be viable unless the Cygwin DLL (cygwin1.dll) is on the system.
            Effectively`,' one must have Cygwin installed in order to use any GAMMA library or
            program built herein. Cygwin provides a Unix-like environment to Windows based PCs`,'
            including bash shells`,' make`,' and GCC.
            </FONT></STRONG></BLOCKQUOTE>

            This directory contains a hand-built Makefile for the build of Windows based
            GAMMA libraries (static, DLL, PyGAMMA DLL) using the <A HREF="_CYGWIN">Cygwin</A>
            development environment. You MUST have the <A HREF="_CYGWIN">Cygwin</A> development
            environment on your computer system (PC) before these files will be of any direct
            use to you. Furthermore`,' for PyGAMMA you must have both <A HREF="_PYTHON">Python</A> 
            and <A HREF="_BOOST_PYTHON">Boost.Python</A> on the system. The Python must be Cygwin
            supplied (not the Windows flavor) and Boost.Python should have been built with Cygwin.
            More information of <A HREF = "_DOCDIR/pygamma/python/cygwin/index.html">Setting Up Python</A> and
            <A HREF = "_DOCDIR/pygamma/boost/cygwin/index.html">Setting Up Boost.Python</A> for Cygwin is available
            in local GAMMA documentation if needed.

            <P>
            Why does this Makefile exist? There may be times where the main GAMMA Makefile fails`,'
            either because it has a bug`,' it is not up to date with the latest GNU software`,' or
            it is not supported on a particular OS/compiler combination. This makefile is a vastly
            simplified version of the main GAMMA makefile. If it does not work`,' at least it can
            be used as a guide to build a working Makefile. At the time this page was written`,'
            the current version of CygWin contains both GCC 3.2-1 (default) as well as 
            GCC 2.95.3-10 (gcc2). Builds of GAMMA using this Cygwin primal Makefile were successfully
            accomplished using either of the two.

            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">Quick Build Instructions</FONT>
                    <BR>
                    <FONT SIZE="+1">(Assumes GAMMA Sources & Cygwin Installed)</FONT>
            </CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <TABLE align="CENTER">
              <TR><TD><IMG SRC="../figs/win.gif"></TD><TD>1.`)' Open a bash shell: Provided with Cygwin</TD></TR>
              <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>2.`)' Change into this directory: <EM>cd GAMMAVER/primal/CygWin</EM></TD></TR>
              <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>3.`)' Run make to clean previous files: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>4.`)' Run make to build static lib. & DLLs: <EM>make</EM></TD></TR>
            <TR><TH colspan=2>Optional Final Cleanup`,' Demos`,' & Testing<TH></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>5.`)' Run make to clean: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>6.`)' Run make to build demo program <EM>make demo</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>7.`)' Run make to build test program <EM>make test</EM></TD></TR>
            <TR><TD valign="top"><IMG SRC="../figs/cyg.gif"></TD><TD>8.`)' Run make to clean: <EM>make clean</EM><BR>&nbsp;</TD></TR>
            </TABLE>
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About The Build</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            The main target <EM>make</EM> will attempt to build GAMMA as both a static library and a DLL. 
            It will also try to build a PyGAMMA DLL used for running GAMMA interactively under Python.
            These libraries will automatically placed into a Cygwin binaries directory within the GAMMA
            directory hierarchy`,' <EM>../../i686-pc-cygwin</EM>. As the GAMMA code files (*.cc) are 
            compiled into object files (*.o or *.po) they will also be placed into this same binaries
            directory. The Cygwin binaries directory is the same one which the main GAMMA Makefile
            would use if properly configured`,' run`,' and working. The object files may be safely removed
            after the build using <EM>make clean</EM>`,' as they may take up valuable disk space.<BR>&nbsp;
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About The Demos and Tests</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            The targets <EM>make demo</EM> and <EM>make test</EM> will build and run GAMMA module demo and
            test programs. They will compile the C++ programs found in <EM>../../demo/modules</EM> and
            <EM>../../test</EM> respectively`,' preferentially linking to the GAMMA DLL build in the main
            target (make all). The builds will produce executable programs in this directory`,'
            DemoGAMMA.exe and TestGAMMA.exe`,' the run them so the user can see the results. Alternative targets
            <EM>make demostatic</EM> and <EM>make teststatic</EM> will do the same but will insure linking
            is done to the GAMMA static library.  You should notice an increased executable file size in 
            DemoGAMMA.exe and TestGAMMA.exe (or any GAMMA program) when static linkage is done.
            When dynamic linking is done the system must be told where to find the GAMMA DLL when the
            executables are run outside of the makefile.

            <P> 
            <STRONG><FONT SIZE="-1">
                    Note that if the CygWin generated GAMMA DLL is present in <EM>../../i686-pc-cygwin</EM>
                    it will be used preferentially over the static library when running the tests and demos.
                    If you wish to insure that the static library is used rather than the DLL when running 
                    them`,' use the targets <EM>make demostatic</EM> and <EM>make teststatic</EM>
                    rather their counterparts.
            </FONT></STRONG>
            <BR>&nbsp;
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About PyGAMMA</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            The PyGAMMA library build related to the build of the GAMMA DLL`,' but it demands that
            <OL>
              <LI>Cygwin Python is installed on the system.
              <LI>Boost.Python for Cygwin is installed on the system.
              <LI>Linking includes Python and Boost.Python libraries.
              <LI>The flag _PYGAMMA is set during compilations.
            </OL>
            As a consequence`,' a different target <EM>pygamma</EM> is used to build the PyGAMMA DLL.
            Similarly`,' the GAMMA module demo and test programs are not compiled under PyGAMMA but
            exists as Python scripts which must be run in a Python window. Hence`,' the targets to
            run these are different as well.
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            You can remove any DLL related files from <EM>../../i686-pc-cygwin</EM> by using the target
            <EM>make dllclean</EM>. Two additional targets allow one to insure there will be a build of the
            demo and test programs. These are <EM>make democlean</EM> and <EM>make testclean</EM> respectively.
            These do not remove any object files from the GAMMA library build. The target <EM>make demo</EM>
            will build an run a program which demonstrates what the GAMMA modules do. They do not demonstrate
            how to build any MR simulation programs currently. After running the demo or test targets one should
            run <EM>make clean</EM> to remove any files produced during the execution of those programs. Any
            clutter files left in this directory can be removed with the script <EM>cleanup</EM> by issuing
            the command <EM>./cleanup</EM> from a bash shell as needed.
          </TD>
        </TR>
      </TABLE>
      )  

include(_PRIMALDIR/base.m4)
include(_DIRDIR/base.m4)
include(_BASEDIR/base.m4)
include(_COREDIR/gamma.m4)
divert(0)

_GAMMAPAGE(_TITLE, _BGIMAGE)
