divert(-1)
define(_TITLE, `GAMMA Builds Using OSX')
define(_PRIMALDIR, `..')

define(_DOCDIR, `../../doc')
define(_DIRDIR, `../../doc/directories')

define(_TOPFONTSIZE, 5)
define(_TOPNAME, OSX<BR>Builds & Targets)
define(_CREATION,    `September 23 2002')
define(_CGIDOCNAME,  `osx')
define(_KEYWORDS,    ``
  <META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation">'')
define(_DESCRIPTION, `
  <META name="description" content="GAMMA Builds Using OSX.">')
define(_JAVASCRIPT, `')
define(_SUBDIR, osx)

define(_EXSUFF, out)

define(_PAGEHTML,
      <TABLE border=0 valign="top">
        <TR>
          <TD valign=top>
            &nbsp;<BR>This directory contains a hand-built Makefile for the build of Apple based
            GAMMA libraries (static, shared, PyGAMMA shared) using the <A HREF="_OSX">OSX</A>
            operating system. You MUST have <A HREF="_OSX">OSX</A> as well as the 
            <A HREF="_MACTOOLS">Developer Tools</A> (GCC, make, etc.) running on your
            computer system (PC) before these files will be of any direct use to you. Furthermore`,'
            for PyGAMMA you must have both <A HREF="_PYTHON">Python</A> and 
            <A HREF="_BOOST_PYTHON">Boost.Python</A> on the system. 
            More information of <A HREF = "_DOCDIR/pygamma/python/osx/index.html">Setting Up Python</A> and
            <A HREF = "_DOCDIR/pygamma/boost/osx/index.html">Setting Up Boost.Python</A> for OSX is available
            in local GAMMA documentation if needed. 

            <P>
            Why does this Makefile exist? There may be times when the main GAMMA Makefile fails`,'
            either because it has a bug`,' it is not up to date with the latest GNU software`,' or
            it is not supported on a particular OS/compiler combination. This makefile is a vastly
            simplified version of the main GAMMA makefile. If it does not work`,' at least it can
            be used as a guide to build a working Makefile. The Makefile was tested with OSX.2. At
            the time this page was written`,' the current version of GCC ported to OSX.2 is 
            GCC 3.1 20020420.  Builds of GAMMA using this OSX primal Makefile were successfully 
            accomplished using it. This port does not match the GNU release of 3.1 and is behind their
            current version (3.2). Additionally there are know problems with the OSX.2 port`,' hopefully
            all of these troubles do not influence anything critical. They are supposed to be solved
            when their port of 3.2 is ready. According to Apple the compiler with this OSX.2 is
            <EM>Apple Computer`,' Inc. GCC version 1161</EM>.

            <P>
	    Some documentation regarding the Makefile and how builds are done under OSX may be found
	    at <A HREF="http://fink.sourceforge.net/doc/porting/shared.php">SourceForge OSX Porting</A>.

            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">Quick Build Instructions</FONT>
                    <BR>
                    <FONT SIZE="+1">(Assumes GAMMA Sources Installed)</FONT>
            </CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <TABLE align="CENTER">
              <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>1.`)' Open a shell: Provided with OSX</TD></TR>
              <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>2.`)' Change into this directory: <EM>cd GAMMAVER/primal/OSX</EM></TD></TR>
              <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>3.`)' Run make to clean previous files: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>4.`)' Run make to build static & shared libraries: <EM>make</EM></TD></TR>
            <TR><TH colspan=2>Optional Final Cleanup`,' Demos`,' & Testing<TH></TR>
            <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>5.`)' Run make to clean: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>6.`)' Run make to build demo program <EM>make demo</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/osx.gif"></TD><TD>7.`)' Run make to build test program <EM>make test</EM></TD></TR>
            <TR><TD valign="top"><IMG SRC="../figs/osx.gif"></TD><TD>8.`)' Run make to clean: <EM>make clean</EM><BR>&nbsp;</TD></TR>
            <TR><TH colspan=2>Optional Installation<TH></TR>
            <TR><TD valign="top"><IMG SRC="../figs/osx.gif"></TD><TD>9.`)' Run make to install: <EM>make install</EM><BR>&nbsp;</TD></TR>
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
            The main target <EM>make</EM> will attempt to build GAMMA as both a static library 
            <EM>libgamma.a</EM> and a shared library <EM>libgamma.dylib</EM>.  It will also try to 
            build a PyGAMMA shared library used for running GAMMA interactively under Python.
            These libraries will automatically placed into a OSX binaries directory within the GAMMA
            directory hierarchy`,' <EM>../../powerpc-mac-darwin</EM>. As the GAMMA code files (*.cc) are 
            compiled into object files (*.o or *.soo or *.po) they will also be placed into this same binaries
            directory. The OSX binaries directory is the same one which the main GAMMA Makefile
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
            <EM>../../test</EM> respectively`,' preferentially linking to the GAMMA shared library built 
            in the main target (make all). The builds will produce executable programs in this directory`,'
            DemoGAMMA._EXSUFF and TestGAMMA._EXSUFF`,' the run them so the user can see the results. Alternative
            targets <EM>make demostatic</EM> and <EM>make teststatic</EM> will do the same but will insure
            linking is done to the GAMMA static library.  You should notice an increased executable file 
            size in DemoGAMMA._EXSUFF and TestGAMMA._EXSUFF (or any GAMMA program) when static linkage is done.
            When shared library linking is done the system must be told where to find the GAMMA library.
            This is done using the <EM>DYLD_LIBRARY_PATH</EM> environment variable. You can see what that is
            set to using the command (in a bash shell) <EM>echo $DYLD_LIBRARY_PATH</EM>. Often this will not
            be defined. If it has not been defined you can set it using the two commands (in a bash shell)
            <OL>
              <LI>DYLD_LIBRARY_PATH=/pathtoBINDIR
              <LI>export DYLD_LIBRARY_PATH
            </OL>
            where the path to the binaries directory is something like 
            <EM>/gamma/gamma-4.1.0/powerpc-mac-darwin</EM>. Alternatively`,'
            if there is already a <EM>DYLD_LIBRARY_PATH</EM> variable set`,' you should add the GAMMA OSX
            binaries directory to it using the command
            <OL>
              <LI>DYLD_LIBRARY_PATH=/pathtoBINDIR:${DYLD_LIBRARY_PATH}
              <LI>export DYLD_LIBRARY_PATH
            </OL>
    


            <P> 
            <STRONG><FONT SIZE="-1">
              Note that if the OSX generated GAMMA shared library is present in <EM>../../powerpc-mac-darwin</EM>
              it will be used preferentially over the static library when running the tests and demos.
              If you wish to insure that the static library is used rather than the shared library when running 
              them`,' use the targets <EM>make demostatic</EM> and <EM>make teststatic</EM>
              rather than their counterparts.
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
            The PyGAMMA library build is closely related to the build of the GAMMA shared object library`,'
            but it demands that
            <OL>
              <LI>Python for OSX is installed on the system.
              <LI>Boost.Python for OSX is installed on the system.
              <LI>Linking includes Python and Boost.Python libraries.
              <LI>The flag _PYGAMMA is set during compilations.
            </OL>
            As a consequence`,' a different target <EM>pygamma</EM> is used to build the PyGAMMA shared library.
            Similarly`,' the GAMMA module demo and test programs are not compiled under PyGAMMA but
            exists as Python scripts which must be run in a Python window. Hence`,' the targets to
            run these are different as well.
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            You can remove any shared library related files from <EM>../../powerpc-mac-darwin</EM> by using the target
            <EM>make soclean</EM>. Two additional targets allow one to insure there will be a build of the
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
