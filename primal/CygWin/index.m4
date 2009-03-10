divert(-1)
define(_TITLE, `GAMMA Builds Using Cygwin')
define(_PRIMALDIR, `..')

define(_DOCDIR, `../../doc')
define(_DIRDIR, `../../doc/directories')

define(_TOPFONTSIZE, 5)
define(_TOPNAME, Cygwin<BR>Builds & Targets)
define(_CREATION,    `September 23 2002')
define(_CGIDOCNAME,  `cygwin')
define(_KEYWORDS,    ``
  <META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation">'')
define(_DESCRIPTION, `
  <META name="description" content="GAMMA Builds Using The Cygwin Environment.">')
define(_JAVASCRIPT, `')
define(_SUBDIR, cygwin)


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
            use to you. Furthermore`,' to build and use <A HREF="_DOCDIR/pygamma/index.html">PyGAMMA</A> 
            you must have both <A HREF="_PYTHON">Python</A> 
            and <A HREF="_BOOST_PYTHON">Boost.Python</A> on the system. The Python must be Cygwin
            supplied (not the Windows flavor) and Boost.Python should have been built with Cygwin.
            More information of <A HREF = "_DOCDIR/pygamma/python/cygwin/index.html">Setting Up Python</A>
            and <A HREF = "_DOCDIR/pygamma/boost/cygwin/index.html">Setting Up Boost.Python</A> for Cygwin 
            is available in local GAMMA documentation if needed. 

            <P>
            Why does this Makefile exist? There may be times where the main GAMMA Makefile fails`,'
            either because it has a bug`,' it is not up to date with the latest GNU software`,' or
            it is not supported on a particular OS/compiler combination. This makefile is a vastly
            simplified version of the main GAMMA makefile. If it does not work`,' at least it can
            be used as a guide to build a working Makefile. At the time this page was written`,'
            the current version of CygWin contains both GCC 3.2-1 (default) as well as 
            GCC 2.95.3-10 (gcc2). Builds of GAMMA using this Cygwin primal Makefile were successfully
            accomplished using either of the two.<BR>&nbsp;

            <CENTER><FONT SIZE="+2">Quick Build Instructions</FONT>
                    <BR>
                    <FONT SIZE="+1">(Assumes GAMMA Sources & Cygwin Installed)</FONT><BR>&nbsp;
            </CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <TABLE align="CENTER" BORDER=1><TR><TD>
            <TABLE align="CENTER">
              <TR><TD><IMG SRC="../figs/win.gif"></TD><TD>1.`)' Open a bash shell: Provided with Cygwin</TD></TR>
              <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>2.`)' Change into this directory: <EM>cd GAMMAVER/primal/CygWin</EM></TD></TR>
              <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>3.`)' Run make to clean previous files: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>4.`)' Run make to build static lib. & DLLs: <EM>make</EM></TD></TR>
            <TR><TD valign="top"><IMG SRC="../figs/cyg.gif"></TD><TD>5.`)' Run <EM>make install</EM> to use this build as your GAMMA<BR>&nbsp;</TD></TR>
            <TR><TH colspan=2>Optional Final Cleanup`,' Demos`,' & Testing<TH></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>6.`)' Run make to clean: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>7.`)' Run make to build demo program <EM>make demo</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/cyg.gif"></TD><TD>8.`)' Run make to build test program <EM>make test</EM></TD></TR>
            <TR><TD valign="top"><IMG SRC="../figs/cyg.gif"></TD><TD>9.`)' Run make to clean: <EM>make clean</EM><BR>&nbsp;</TD></TR>
            </TABLE>
            </TD></TR></TABLE><BR>&nbsp;
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
            &nbsp;<BR>
            The main target <EM>make</EM> will attempt to build GAMMA as both a static library and a DLL. 
            It will also try to build a PyGAMMA DLL used for running GAMMA interactively under Python.
            These libraries will automatically placed into a Cygwin binaries directory within the GAMMA
            directory hierarchy`,' <EM>../../i686-pc-cygwin</EM>. As the GAMMA code files (*.cc) are 
            compiled into object files (*.o or *.po) they will also be placed into this same binaries
            directory. The Cygwin binaries directory is the same one which the main GAMMA Makefile
            would use if properly configured`,' run`,' and working. The object files may be safely removed
            after the build using <EM>make clean</EM>`,' as they may take up valuable disk space.
          </TD>
        </TR>
        <TR>
          <TD>
            <TABLE align=center>
              <TR>
                <TH>Sources</TH>
                <TH>&nbsp;</TH>
                <TH>CygWin Dir.</TH>
                <TH>&nbsp;</TH>
                <TH>CygWin Dir.</TH>
              </TR>
              <TR>
                <TH><FONT SIZE="-1">(GV/src)</FONT></TH>
                <TH>&nbsp;</TH>
                <TH><FONT SIZE="-1">(GV/i686-pc-cygwin)</FONT></TH>
                <TH>&nbsp;</TH>
                <TH><FONT SIZE="-1">(GV/i686-pc-cygwin)</FONT></TH>
              </TR>
              <TR>
                <TD align=center>
                Basics/*.cc<BR>
                Basics/*.h<BR>
                Matrix/*.cc<BR>
                Matrix/*.h<BR>
                .......
                </TD>
                <TD valign=center>
                  <EM>&nbsp;make&nbsp;</EM><BR>
                  <STRONG>&nbsp;====>&nbsp;</STRONG>
                </TD>
                <TD align=center>
                *.o<BR>
                *.po<BR>
                *.a<BR>
                *.dll<BR>
                </TD>
                <TD valign=center>
                  <EM>&nbsp;make&nbsp;</EM><BR>
                  <STRONG>&nbsp;=====>&nbsp;</STRONG><BR>
                  <EM>&nbsp;clean&nbsp;</EM>
                </TD>
                <TD align=center>
                libgamma.a<BR>
                gamma.dll<BR>
                libgamma.dll.a<BR>
                pygamma.dll<BR>
                </TD>
              </TR>
            </TABLE>
	    In the above diagram <EM>GV</EM> is used to inicate the base GAMMA version
            directory. For example this is C:/gamma/gamma-4.1.0 on my current system.
            Use of <EM>make clean</EM> can significantly reduce disk space usage`,' yet
            leaves the GAMMA libraries intact.
            <BR>&nbsp;
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
            target (make all). The builds will produce object files and executable programs in this directory`,'
            DemoGAMMA.exe and TestGAMMA.exe`,' then run them so the user can see their results. Alternative
            targets <EM>make demostatic</EM> and <EM>make teststatic</EM> will do the same but will insure linking
            is done to the GAMMA static library.  These will have the names DemoGAMMA.static.exe and 
            TestGAMMA.static.exe. You should notice an increased executable file size in 
            DemoGAMMA.static.exe and TestGAMMA.static.exe (or any GAMMA program) using static library linking
            when compared to the same executable that links to the DLL.  Note that when dynamic linking is done 
            the system must be told where to find the GAMMA DLL when the executables are run outside of the makefile.
            That can be accomplished by moving the DLL into a known PATH directory. Finally note that all executables
            are NOT stripped. If you wish to shrink the executable file sizes then might run <EM>strip</EM> on them.
            For example`,' <EM>strip DemoGAMMA.exe</EM> and <EM>strip DemoGAMMA.static.exe</EM> will make a
            significant reduction in the sizes of these two files.

            <P> 
            <STRONG><FONT SIZE="-1">
                    Note that if the CygWin generated GAMMA DLL is present in <EM>../../i686-pc-cygwin</EM>
                    it will be used preferentially over the static library when running the tests and demos.
                    If you wish to insure that the static library is used rather than the DLL when running 
                    them`,' use the targets <EM>make demostatic</EM> and <EM>make teststatic</EM>
                    rather their counterparts.
            </FONT></STRONG>

            <P>
            Lastly`,' although the executables produced by linking to the GAMMA DLL or GAMMA static library
            are relocatable`,' they do rely on the associated GAMMA library as well as the CygWin DLL.
            Hopefully you have the CygWin DLL on your system or you should not be using this Makefile.
            As for the GAMMA libraries`,' during program compilation using the GAMMA script it is 
            specified that these reside in <EM>../../i686-pc-cygwin</EM> so the executable inherently 
            knows to look in that directory for the <STRONG>static</STRONG> libraries`,' 
            <EM>i.e. libgamma.a</EM> and <EM>libgamma.dll.a</EM>. But the executable will NOT know where
            to find the GAMMA DLL. This is not of consequence if linking is done to the static library`,'
            but if linking is done to the DLL (default) then the executable must be able to find the DLL.
            The makefile solves this by simply copying the DLL into this directory`,' that is one of the 
            first directories looked for when searching for a DLL. 

            <P>
            To be able to run any (DLL linked) GAMMA executable program the GAMMA DLL must first be
            placed into a directory where it can be easily found. This can be the dirctory containing
            the executable (as is done in the Makefile) or it can be any directory in the PATH. To see what
            the path is`,' use the command <EM>env</EM> in the Cygwin provided bash shell . Probably the best
            choice of where to put <EM>gamma.dll</EM> is in directory <EM>/usr/local/bin</EM> or maybe even
            <EM>/bin</EM>. Cygwin puts these two in the PATH automatically.  Where these reside on
            your system depends upon where you installed CygWin. Note that the Makefile command
            <EM>make install</EM> will copy the GAMMA dll <EM>gamma.dll</EM> into <EM>/usr/local/bin</EM>.
            Of course`,' if you wish to be able to just click on the Windows icon to run a program then the
            DLL must be in the Windows path....<BR>&nbsp; 
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><H3>About The Installation</H3></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            Normally GAMMA is built and installed with the usual GNU configure-make process done
            in the main GAMMA version directory using the main Makefile.  The purpose of this <EM>primal</EM>
            Makefile is to demonstrate how GAMMA and PyGAMMA libraries are built on a relatively simplistic
            level`,' by-passing the complexities buried in the main Makefile. But this build is somewhat
            specific in that it <STRONG>assumes the user is working with CygWin</STRONG>. Consequently it
            keeps all binaries in a CygWin specific directory. 
            <P>
            If the build and programs work nicely`,' the user may wish to use this build as their default GAMMA.
            What does that mean? Quite simply it means that you wish to use the libraries produced by this
            build as your GAMMA libraries. There are two aspects to this: 1.`)' The GAMMA script (gamma)`,'
            and 2.`)' The GAMMA DLL (gamma.dll`,' pygamma.dll).  The script must be adjusted and then it`,'
            and the DLLs must be placed in an appropriate directory.
            <P>
            <TABLE align=center BORDER=1><TR><TD>
            <TABLE align=center>
              <TR>
                <TH>Initial File</TD>
                <TH align=center><EM>make install</EM></TH>
                <TH>Final File</TH>
              </TR>
              <TR>
                <TD>./gamma.in</TD>
                <TD align=center>&nbsp;==>&nbsp;</TD>
                <TD>INSTALLDIR/gamma</TD>
              </TR>
              <TR>
                <TD>BINDIR/gamma.dll</TD>
                <TD align=center>&nbsp;==>&nbsp;</TD>
                <TD>INSTALLDIR/gamma.dll</TD>
              </TR>
              <TR>
                <TD>BINDIR/libgamma.dll.a</TD>
                <TD align=center>&nbsp;==>&nbsp;</TD>
                <TD>BINDIR/libgamma.dll.a</TD>
              </TR>
              <TR>
                <TD>BINDIR/libgamma.a</TD>
                <TD align=center>&nbsp;==>&nbsp;</TD>
                <TD>BINDIR/libgamma.a</TD>
              </TR>
              <TR>
                <TD>BINDIR/pygamma.dll</TD>
                <TD align=center>&nbsp;==>&nbsp;</TD>
                <TD>PYDLLDIR/pygamma.dll</TD>
              </TR>
            </TABLE>
            </TD></TR></TABLE>
            <P>
            The Makefile contains the variable BINDIR which will be set to ../../i686-pc-cygwin.
            Similarly it contains the variable INSTALLDIR which will be set to /usr/local/bin`,'
            and the variable PYDLLDIR which is set by the user to the point where the Python
            DLL directory is. This directory on my machine is /lib/python2.2/lib-dynload.
            <P>
            The gamma script is simply a set of commands that will invoke the C++ compiler and automatically
            link to the GAMMA library whenever a GAMMA program is compiled. This script should inherently know
            where the GAMMA headers are on your system (../../src)`,' where the GAMMA CygWin binaries are
            (../../i686-pc-cygwin)`,' and available for all users on the system.  When you invoke 
            <EM>make install</EM> the file <EM>gamma.in</EM> is converted into <EM>gamma</EM> and placed
            into /usr/local/bin. The conversion is necessary to tell the script where GAMMA is on your
            system and the move is to a directory typically in the PATH of each user so that when he/she
            type in "gamma" at the command line it will invoke that script.  The script is set to link to
            a single library named <EM>gamma</EM>`,' which is the name of the library this makefile builds.

            <P>
            As for the GAMMA library`,' there may be four of them produced. The first is a static GAMMA 
            library`,' <EM>libgamma.a</EM>. This is built in the directory (../../i686-pc-cygwin) and will
            stay there even after <EM>make install</EM>. The <EM>gamma</EM> script can find it because it
            will know that directory ../../i686-pc-cygwin contains GAMMA CygWin binaries. The second and
            third libraries deal with the GAMMA DLL`,' these are the DLL itself <EM>gamma.dll</EM> and its
            associated input library <EM>libgamma.dll.a</EM>. The latter is similar to the static library
            and will remain in ../../i686-pc-cygwin. But the former must be placed into a directory known
            by the system. Hence`,' <EM>make install</EM> will move <EM>gamma.dll</EM> into the a directory
            commonly used by Cygwin for libraries.  Note that when GAMMA C++ programs are they will 
            preferentially link to the libgamma.dll.a (and hence use the DLL). Only when the DLL is not
            present or special build flags are set will the static library be used. The fourth and final
            GAMMA library is the DLL for PyGAMMA`,' <EM>pygamma.dll</EM>. This library must be known to
            Python`,' so the <EM>make install</EM> will move this DLL into the Python DLL directory. 
            for the CygWin build and moved into a location known by the system.
            <P>
            To summarize`,' it copies the GAMMA DLL <EM>gamma.dll</EM> into <EM>/usr/local/bin</EM>`,'
            and it copies the PyGAMMA DLL <EM>pygamma.dll</EM> into the Python DLL directory.  Since the
            directory <EM>/usr/local/bin</EM> will typically be in the users PATH in a Cygwin Bash shell`,'
            all users should have access to GAMMA. Since Python always looks in its own DLL directory`,'
            all users should have access to PyGAMMA. <BR>&nbsp;

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
            The PyGAMMA library build is closely related to the build of the GAMMA DLL`,' but it demands that
            <OL>
              <LI>Cygwin Python is installed on the system.
              <LI>Boost.Python for Cygwin is installed on the system.
              <LI>Linking includes Python and Boost.Python libraries.
              <LI>The flag PYGAMMA (-DPYGAMMA=1) is set during compilations.
            </OL>
            As a consequence`,' a different target <EM>pygamma</EM> is used to build the PyGAMMA DLL.
            Similarly`,' the GAMMA module demo and test programs are not compiled under PyGAMMA but
            exists as Python scripts which must be run in a Python window. Hence`,' the targets to
            run these are different as well.<BR>&nbsp;
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About The Makefile</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            Although primitive`,' the provided Makefile in this directory does have several targets.
            These and their intended function are shown in the following table. 

            <P>
            <TABLE align=center BORDER=1><TR><TD>
            <TABLE align=center>
              <TR>
                <TH align=center>Target</TH>
                <TH align=center>Purpose</TH>
              </TR>
              <TR>
                <TD align=left>all</TD>
                <TD>Same As <EM>make</EM>. Builds Libraries libgamma.a`,' gamma.dll`,'....</TD>
              </TR>
              <TR>
                <TD align=left>lib</TD>
                <TD>Builds only the static library libgamma.a</TD>
              </TR>
              <TR>
                <TD align=left>dll</TD>
                <TD>Builds only the DLL (gamma.dll`,' libgamma.dll.a)</TD>
              </TR>
              <TR>
                <TD align=left>pyg</TD>
                <TD>Builds only the PyGAMMA DLL (pygamma.dll)</TD>
              </TR>
              <TR>
                <TD align=left>demo</TD>
                <TD>Builds and Runs the module demos (using DLL)</TD>
              </TR>
              <TR>
                <TD align=left>demostatic</TD>
                <TD>Builds and Runs the module demos (using static library)</TD>
              </TR>
              <TR>
                <TD align=left>clean</TD>
                <TD>Cleans out all object files from any builds</TD>
              </TR>
              <TR>
                <TD align=left>install</TD>
                <TD>Installs GAMMA script and libraries</TD>
              </TR>
            </TABLE>
            </TD></TR></TABLE><P>&nbsp;
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">Additional Notes</FONT>
            </CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <P>
            At the time of this writing`,' the CygWin build of the GAMMA DLL failed and produced the following
            error:
            <BLOCKQUOTE>collect2: ld terminated with signal 11 [Segmentation fault]</BLOCKQUOTE>
            This problem (not due to GAMMA) and the fix has been discussed on the CygWin mailing 
            list as summarized below:
            <BLOCKQUOTE>
            This has come up a few times in the past.
            It has been figured out that increasing <EM>heap_chunk_in_mb</EM> helps.<BR>
            The Cygwin default is 128MB`,'  try to set it to 512MB or 1GB.<BR>
            I have 512MB RAM at home and linking succeeds with a 1GB setting. That is a DWORD value 400.
            <P>
            <FONT SIZE="-1"><STRONG>
            REGEDIT4<P>

            [HKEY_CURRENT_USER\Software\Cygnus Solutions\Cygwin]<BR>
            "heap_chunk_in_mb"=dword:00000400<P>
            </STRONG> </FONT>

            Paste this into a file with suffix .reg`,' a doubleclick on the file
            will write it in the registry.  May need a reboot too.
            </BLOCKQUOTE>

            I have included the file <EM>CygWinHeap.reg</EM> in this directory which contains the
            above alteration to the Windows registry. By clicking on it with the mouse the changes
            within will be entered into the registry. If you are experiencing this secmentation fault
            error please apply the registry patch. I did not have to reboot my machine to have it take
            effect but I did have to close all CygWin bash windows.
            <P>
            Two additional targets allow one to insure there will be a build of the
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
