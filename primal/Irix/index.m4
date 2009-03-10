divert(-1)
define(_TITLE, `GAMMA Builds Using Irix')
define(_PRIMALDIR, `..')

define(_DOCDIR, `../../doc')
define(_DIRDIR, `../../doc/directories')

define(_TOPFONTSIZE, 5)
define(_TOPNAME, Irix<BR>Builds & Targets)
define(_CREATION,    `September 23 2002')
define(_CGIDOCNAME,  `irix')
define(_KEYWORDS,    ``
  <META name="keywords" content="NMR, ESR, EMR, MRI, FID, resonance, science, education, simulation">'')
define(_DESCRIPTION, `
  <META name="description" content="GAMMA Builds Using Irix.">')
define(_JAVASCRIPT, `')
define(_SUBDIR, irix)


define(_PAGEHTML,
      <TABLE border=0 valign="top">
        <TR>
          <TD valign=top>
            &nbsp;<BR>This directory contains a hand-built Makefile for the build of
            GAMMA libraries (static, shared, PyGAMMA shared) using the <A HREF="_LINUX">Irix</A>
            operating system. You MUST have <A HREF="_LINUX">Irix</A> running on your
            computer system (SGI) before these files will be of any direct use to you. 
            <P>
            If the user wishes to also build <A HREF="_DOCDIR/PyGAMMA/index.html">PyGAMMA</A> both 
            <A HREF="_PYTHON">Python</A> and <A HREF="_BOOST_PYTHON">Boost.Python</A> must be
            installed on the system.  More information on 
            <A HREF = "_DOCDIR/pygamma/python/irix/index.html">Setting Up Python</A> and
            <A HREF = "_DOCDIR/pygamma/boost/irix/index.html">Setting Up Boost.Python</A> for 
            Irix is available in local GAMMA documentation if needed. 

            <P>
            Why does this Makefile exist? There may be times where the main GAMMA Makefile fails`,'
            either because it has a bug`,' it is not up to date with the latest GNU software`,' or
            it is not supported on a particular OS/compiler combination. This makefile is a vastly
            simplified version of the main GAMMA makefile. If it does not work`,' at least it can
            be used as a guide to build a working Makefile. The Makefile was tested with SGI Irix.
            At the time this page was written`,' the current version of Irix is 8.0 and it
            contains both GCC 3.2.x.  Builds of GAMMA using this Irix
            primal Makefile were successfully accomplished using it.

            <P>
            <CENTER><FONT SIZE="+2">Quick Build Instructions</FONT>
                    <BR>
                    <FONT SIZE="+1">(Assumes GAMMA Sources Installed)</FONT>
            </CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <TABLE align="CENTER" BORDER=1><TR><TD>
            <TABLE align="CENTER">
              <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>1.`)' Open a bash shell: Provided with Irix</TD></TR>
              <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>2.`)' Change into this directory: <EM>cd GAMMAVER/primal/Irix</EM></TD></TR>
              <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>3.`)' Run make to clean previous files: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>4.`)' Run make to build static & shared libraries: <EM>make</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>5.`)' Run make to install: <EM>make install</EM></TD></TR>
            <TR><TH colspan=2>Optional Final Cleanup`,' Demos`,' & Testing<TH></TR>
            <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>6.`)' Run make to clean: <EM>make clean</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>7.`)' Run make to build demo program <EM>make demo</EM></TD></TR>
            <TR><TD><IMG SRC="../figs/irix.gif"></TD><TD>8.`)' Run make to build test program <EM>make test</EM></TD></TR>
            <TR><TD valign="top"><IMG SRC="../figs/irix.gif"></TD><TD>9.`)' Run make to clean: <EM>make clean</EM><BR>&nbsp;</TD></TR>
            </TABLE>
            </TD></TR></TABLE>
          </TD>
        </TR>
        <TR>
          <TD>
            &nbsp;<P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About The Build</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            The main target <EM>make</EM> will attempt to build GAMMA as both a static library 
            <EM>libgamma.a</EM> and a shared library <EM>gamma.so</EM>.  It will also try to 
            build a PyGAMMA shared library used for running GAMMA interactively under Python.
            These libraries will automatically placed into a Irix binaries directory within the GAMMA
            directory hierarchy`,' <EM>../../i686-pc-irix-gnu</EM>. As the GAMMA code files (*.cc) are 
            compiled into object files (*.o or *.soo or *.po) they will also be placed into this same binaries
            directory. The Irix binaries directory is the same one which the main GAMMA Makefile
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
            DemoGAMMA.exe and TestGAMMA.exe`,' the run them so the user can see the results. Alternative
            targets <EM>make demostatic</EM> and <EM>make teststatic</EM> will do the same but will insure
            linking is done to the GAMMA static library.  You should notice an increased executable file 
            size in DemoGAMMA.exe and TestGAMMA.exe (or any GAMMA program) when static linkage is done.
            When shared library linking is done the system must be told where to find the GAMMA library.
            This is done using the <EM>LD_LIBRARY_PATH</EM> environment variable. You can see what that is
            set to using the command (in a bash shell) <EM>echo $LD_LIBRARY_PATH</EM>. Often this will not
            be defined. If it has not been defined you can set it using the two commands (in a bash shell)
            <OL>
              <LI>LD_LIBRARY_PATH=/pathtoBINDIR
              <LI>export LD_LIBRARY_PATH
            </OL>
            where the path to the binaries directory is something like 
            <EM>/gamma/gamma-4.1.0/i686-pc-irix-gnu</EM>. Alternatively`,'
            if there is already a <EM>LD_LIBRARY_PATH</EM> variable set`,' you should add the GAMMA Irix
            binaries directory to it using the command
            <OL>
              <LI>LD_LIBRARY_PATH=/pathtoBINDIR:${LD_LIBRARY_PATH}
              <LI>export LD_LIBRARY_PATH
            </OL>
    


            <P> 
            <STRONG><FONT SIZE="-1">
              Note that if the Irix generated GAMMA shared library is present in <EM>../../i686-pc-irix-gnu</EM>
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
              <LI>Python for Irix is installed on the system.
              <LI>Boost.Python for Irix is installed on the system.
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
            You can remove any shared library related files from <EM>../../i686-pc-irix-gnu</EM> by using the target
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
        <TR>
          <TD>
            <P>
            <HR>
            <P>
            <CENTER><FONT SIZE="+2">About Shared Libraries On Irix</FONT></CENTER>
          </TD>
        </TR>
        <TR>
          <TD>
            <H3>Versioning</H3>
            <P>
            As any other program`,' libraries tend to have bugs which get fixed over
            time. They also may introduce new features`,' change the effect of
            existing ones`,' or remove old ones. This could be a problem for
            programs using them; what if it was depending on that old feature?
   
            <P>
            So`,' we introduce library versioning. We categorise the changes that
            might be made to a library as <EM>minor</EM> or <EM>major</EM>`,' and we rule that a
            <EM>minor</EM> change is not allowed to break old programs that are using the
            library. You can tell the version of a library by looking at its
            filename (actually`,' this is`,' strictly speaking`,' a lie for ELF; keep
            reading to find out why) : libfoo.so.1.2 has major version 1`,' minor
            version 2. The minor version number can be more or less anything ---
            libc puts a `patchlevel' in it`,' giving library names like
            libc.so.5.2.18`,' and it's also reasonable to put letters`,' underscores`,'
            or more or less any printable ASCII in it.

            <H3>Compiling</H3>
            <P>
            Under Irix`,' the command for creating shared libraries is:<P>

            <CENTER>gcc -shared -Wl`,'-soname`,'libfoo.so.1 -o libfoo.so.1.0 foo`*'.o</CENTER>

            <P>
            To build libfoo.so as a shared library`,' the basic steps look like
            this:
   
            <UL>
            <LI>`$' gcc -fPIC -c *.c
            <LI>`$' gcc -shared -Wl`,'-soname`,'libfoo.so.1 -o libfoo.so.1.0 `*'.o
            <LI>`$' ln -s libfoo.so.1.0 libfoo.so.1
            <LI>`$' ln -s libfoo.so.1 libfoo.so
            <LI>`$' LD_LIBRARY_PATH="pwd"`:'$LD_LIBRARY_PATH `;' export LD_LIBRARY_PATH
            </UL>
   
            When you are happpy that the library works`,' you will have to move it to`,'
            say`,' /usr/local/lib`,' and recreate the appropriate links. The link from
            libfoo.so.1 to libfoo.so.1.0 is kept up to date by ldconfig`,' which on
            most systems is run as part of the boot process. The libfoo.so link
            must be updated manually. If you are scrupulous about upgrading all
            the parts of a library (e.g. the header files) at the same time`,' the
            simplest thing to do is make libfoo.so -> libfoo.so.1`,' so that
            ldconfig will keep both links current for you. If you are not`,' you
            are setting yourself up to have all kinds of weird things happen at a
            later date. Do not say you were not warned.
   
            <P>
            <UL>
            <LI>$ su
            <LI># cp libfoo.so.1.0 /usr/local/lib
            <LI># /sbin/ldconfig
            <LI># ( cd /usr/local/lib ; ln -s libfoo.so.1 libfoo.so )
            </UL>

            <H3>Library soname & Symbolic Links</H3>
            <P>
            Each library has a <EM>soname</EM>. When the linker finds one of these in a
            library it is searching`,' it embeds the <EM>soname</EM> into the binary instead
            of the actual filename it is looking at. At runtime`,' the dynamic
            loader will then search for a file with the name of the <EM>soname</EM>`,' 
            <STRONG>not the library filename</STRONG>. Thus a library called libfoo.so could 
            have a soname libbar.so`,' and all programs linked to it would look for libbar.so 
            instead when they started.

            <P>
            This sounds like a pointless feature`,' but it is key to understanding
            how multiple versions of the same library can coexist on a system. The
            de facto naming standard for libraries in Irix is to call the
            library`,' say`,' libfoo.so.1.2`,' and give it a soname of libfoo.so.1. If
            it is added to a "standard" library directory (e.g. /usr/lib)`,' ldconfig
            will create a symlink libfoo.so.1 -> libfoo.so.1.2 so that the
            appropriate image is found at runtime. You also need a link libfoo.so
            -> libfoo.so.1 so that ld will find the right soname to use at link
            time.

            <P>
            So`,' when you fix bugs in the library`,' or add new functions `('any
            changes that will not adversely affect existing programs`)'`,' you rebuild
            it`,' keeping the soname as it was`,' and changing the filename. When you
            make changes to the library that would break existing binaries`,' you
            simply increment the number in the soname --- in this case`,' call the
            new version libfoo.so.2.0`,' and give it a soname of libfoo.so.2. Now
            switch the libfoo.so link to point to the new version and all is well
            with the world again.

            <P>
            Note that you do not have to name libraries this way`,' but it is a good
            convention. ELF gives you the flexibility to name libraries in ways
            that will confuse the pants off people`,' but that does not mean you have
            to use it.

            <P>
            Supposing that you observe the tradition that major upgrades may break 
            compatibility but that minor upgrades may not. Then link with

            <P><CENTER>
            gcc -shared -Wl`,'-soname`,'libfoo.so.major -o libfoo.so.major.minor
            </CENTER>

            <P>
            and everything will be all right.

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
