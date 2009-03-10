
###############################################################################
#                                                                             #
#                                 G A M M A                                   #
#                                                                             #
#                Makefile for the GAMMA MR Simulation Project                 #
#                      Copyright � 2000 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32307-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# Users are free to copy this file for personal use but may NOT give out      #
# modifications with or without the GAMMA platform. This is the main GAMMA    #
# makefile and is typically packaged with the full GAMMA source distribution. #
# The full src distrubution as well as documentation, binaries, etc. may be   #
# obtained from the GAMMA WWW site above or any of its mirrors. This makefile #
# includes (and relys upon) additional makefiles found in the "make"          #
# subdirectory.                                                               #
#                                                                             #
#                 It Needs GNU Make In Order To Work Properly!                #
#  (That is provided with CygWin & Linux and available on most Unix systems)  #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
#    all       : Compiles GAMMA to produce libraries for linking (default).   #
#    profile   : Compiles GAMMA to produce libraries for profiling.           #
#    variables : Print out the variables used in running make                 #
#    check     : Test GAMMA using DejaGNU framework & GAMMA testsuite         #
#    testsuite : Make GAMMA testsuite source distribution                     #
#    check     : Test GAMMA using DejaGNU framework                           #
#    tsuitevars: Output variables used in running the testsuite (check)       #
#                                                                             #
# Notes: We Still Need GNU Make For This To Work.                             #
#                                                                             #
###############################################################################

###############################################################################
#                                                                             #
#                       Include make/MakeMods                                 #
#                       =====================                                 #
#                            (VARIABLES)                                      #
#                                                                             #
# The file MakeMods sets up variables for individual modules and variables    #
# that span all of GAMMA. These variables deal exclusively with module names  #
# and module files. If any new files or new modules are added into the GAMMA  #
# sources then they must be appropriately added in MakeMods. This is where    #
# things are set so that we know what files & directories make targets are to #
# contend with.                                                               #
#                                                                             #
###############################################################################

include make/MakeMods

###############################################################################
#                                                                             #
#                        Include make/MakeGen                                 #
#                        ====================                                 #
#                            (VARIABLES)                                      #
#                                                                             #
# The file MakeGen  sets up variables that are the typical GNU boiler-plate   #
# definitions (srcdir, prefix, bindir, libdir, infodir, mandir, host,....).   #
# This will also set up standard SUFFIXES and the SHELL variable as well as   #
# compiler and linker flags. Basically everything that is dependent upon the  #
# system archetecture/compiler/os is set here. Since MakeGen is produced      #
# during the configuration step, the variables it provides are adjusted to    #
# fit the current system.                                                     #
#                                                                             #
# These variables provided here are as follows:                               #
#                                                                             #
# .SUFFIXES  - Clears out any implicit make rules that might be present       #
# .SUFFIXES  - Adds back in implicit make rules that we might want to use     #
# SHELL      - Don't want SHELL variable inherited from environment (want sh) #
# srcdir     - Where the source for this Makefile resides                     #
# top_srcdir - Relative srcdir pushed to recursive Makefiles                  #
# libdir     - Where to put the GAMMA libraries                               #
# infodir    - Where to put the GAMMA info files                              #
# mandir     - Where to put the GAMMA man pages                               #
# host       - Unique name (architecture specific) for platform dependents..  #
# CXX        - The C++ Compiler To Be Used                                    #
# CXXFLAGS   - The C++ Compiler Flags To Be Used                              #
# RANLIB     - The ranlib program to use.  Set as RANLIB = : if not required. #
# GCXXFLAGS  - Additonal C++ Compiler Flags That GAMMA Uses                   #
#                                                                             #
# Edit this file only if some auto-configurable variables are absent and/or   #
# there are compiler flags that need defining or alteration.                  #
#                                                                             #
###############################################################################

include make/MakeGen

###############################################################################
#                                                                             #
#                        Include make/MakeGam                                 #
#                        ====================                                 #
#                            (VARIABLES)                                      #
#                                                                             #
# Here we will include a multitude of GAMMA variables. These are specific to  #
# GAMMA, its particular directory structure, and build.
# are based on the following variables which MUST BE declared prior to having #
# the next include statement. They are in here because they change more often #
# than the ones that we are about to include.                                 #
#                                                                             #
# SHOULD BE DEFINED IN THIS FILE                                              #
# ==============================                                              #
#                                                                             #
# GBASEVER      - The GAMMA base version number (e.g. 4.0)                    #
# GSUBVER       - The GAMMA sub-version number  (e.g. 7)                      #
# PROJECTPATH   - This Directory, Main GAMMA Directory This Version           #
#                                                                             #
# Now, the variables (included below) are relatively static. That is, they    #
# are not values that change very often. Some of these variables are purely   #
# cosmetic since I like to spit out information to the screen when running    #
# Makefiles. Others are critical to GAMMA distriubtions but the 99% of GAMMA  #
# users will NOT want to change anything in there.                            #
#                                                                             #
# Defined in Imported Makefile                                                #
# ============================                                                #
#                                                                             #
# GBASEVERUL - The GAMMA base version number underlining (e.g. ---)           #
# GSUBVER    - The GAMMA sub-version number underlining (e.g. --)             #
# GVERSION   - The current GAMMA version (e.g. 4.0.7)                        #
# GVERSUL    - The current GAMMA verison underlining (e.g. ------)            #
# LABEL      - Cosmetic variable strictly for output (e.g. GAMMA-4.0.7)      #
# LABUN      - Cosmetic variable strictly for output (e.g. ------------)      #
# SRCNAME    - Base name of source distribution file (e.g. GamSrc4.0.7)      #
# SRCTAR     - Source distribution tar file name (e.g. GamSrc4.0.7.tar)      #
# SRCZIP     - Source distribution zip file name (e.g. GamSrc4.0.7.tar.gz)   #
# BIN        - Where Architecture Specific GAMMA Binaries Are Found           #
# LIB        - Where Architecture Specific GAMMA Libraries Are Found          #
# SRC        - Where GAMMA Source Codes Are Found (Not Computer Specific)     #
# RCS        - Where Main GAMMA Files Are Found (Tracked By RCS)              #
# TSUITE     - Where GAMMA TestSuite is Located                               #
# TST        - Where GAMMA Test Programs Are Located                          #
# GAMDIST    - Relative Temp Dir Used For GAMMA Package Distributions         #
# SRCDIST    - Relative Temp Dir Used For GAMMA Source Distributions          #
# BINDIST    - Relative Temp Dir Used For GAMMA Binary Distributions          #
# LIBDIST    - Relative Temp Dir Used For GAMMA Library Distributions         #
# TSUITEDIST - Relative Temp Dir Used For GAMMA Test Suite Distributions      #
# TSTDIST    - Relative Temp Dir Used For GAMMA Testing Distributions         #
# COPYGAM    - Absolute Temp Dir Used For GAMMA Package Distributions         #
# COPYSRC    - Absolute Temp Dir Used For GAMMA Source Distributions          #
# COPYBIN    - Absolute Temp Dir Used For GAMMA Binary Distributions          #
# COPYLIB    - Absolute Temp Dir Used For GAMMA Library Distributions         #
# COPYTSUITE - Absolute Temp Dir Used For GAMMA Test Suite Distributions      #
# COPYTST    - Absolute Temp Dir Used For GAMMA Testing Distributions         #
#                                                                             #
###############################################################################

GBASEVER        = 4.0
GSUBVER         = 7
PGMNAME         = gamma
#PROJECTPATH = $(shell pwd)
#PROJECTPATH=c:/gamma/gamma-4.1.0

include make/MakeGam

###############################################################################
#                                                                             #
#                           GAMMA Module Variables                            #
#                                                                             #
# These variables/values dictate how GAMMA modules are treated.  GAMMA is     #
# broken up into individual modules which are compiled/linked/tested as a     #
# unit.  Users may which to not include some modules in these processes.  For #
# example, one may never wish to use Floquet operators so it can be "turned   #
# off" so that the Floquet module will not be compiled, linked to in GAMMA    #
# programs, nor tested during a runthrough of the GAMMA testsuite. To remove  #
# a module from GAMMA just remove its name from the SUBDIRS variable. Note    #
# that subdirectories lower in the name list are used by modules with names   #
# higher in this list.  That is, if you remove Basics not much in GAMMA will  #
# be happy but if you remove MultiSys nothing else will care.                 #
#                                                                             #
# NOTSOLO  - Flag Indicating Makefile (NOT) Being Run Recursively. DONT TOUCH #
# MODLIBS  - Flag Whether To Build GAMMA As Modular Libraries.                #
# STATLIB  - Flag Whether To Build GAMMA As A Single Static Library.          #
# SUBDIRS  - The Sub-directores (Modules) To Consider During Recursive Makes. #
# PASSFLGS - Variables Passed To Recursive Makes                              #
# Bsubdirs - Flags Indicating Whether To Build/Link A Particular Module       #
# BLDFLGS  - All Flags For Module Builds Collectively                         #
# Lsubdirs - Base Names of Modules Libraries To Build                         #
#                                                                             #
###############################################################################

NOTSOLO         = "1"
MODLIBS         = "1"
STATLIB         = "1"
SUBDIRS         = Basics Matrix GamIO Level1 HSLib LSLib Level2 Bloch WBR \
                  IntRank2 Floquet Testing Deprecated Pulses MultiSys \
                  ESRLib Gradients WWW

BBasics         = yes                   # Set GAMMA Basics Module to build
BMatrix         = yes                   # Set Matrix Module to build
BGamIO          = yes                   # Set Format IO Module to build
BLevel1	        = yes                   # Set Level 1 Module to build
BHSLib          = yes                   # Set Hilbert Space Lib to build
BLSLib          = yes                   # Set Liouville Space Lib to build
BLevel2	        = yes                   # Set Level 2 Module to build
BBloch	        = yes                   # Set Bloch Module to build
BWBR            = yes                   # Set WBR Module to build
BIntRank2       = yes                   # Set Rank 2 Interactions to build
BFloquet        = yes                   # Set Floquet Module to build
BTesting        = yes                   # Set GAMMA Testing Module to build
BDeprecated 	= yes                   # Set Deprecated Module to build
BPulses         = yes                   # Set Pulse Module to build
BMultiSys    	= yes                   # Set MultiSystems to build
BWWW            = no                    # Set WWW Module to build
BESR            = no                    # Set ESR Module to build
BGradients      = yes	                # Set Gradients Module to build

BUILDFLGS  = \
             "BBasics=$(BBasics)"       "BMatrix=$(BMatrix)" \
             "BGamIO=$(BGamIO)"         "BLevel1=$(BLevel1)" \
             "BHSLib=$(BHSLib)"         "BLSLib=$(BLSLib)" \
             "BLevel2=$(BLevel2)"       "BWBR=$(BWBR)" \
             "BIntRank2=$(BIntRank2)"   "BFloquet=$(BFloquet)" \
             "BTesting=$(BTesting)"     "BDeprecated=$(BDeprecated)" \
             "BPulses=$(BPulses)"       "BMultiSys=$(BMultiSys)" \
             "BWWW=$(BWWW)"             "BESR=$(BESR)" \
             "BGradients=$(BGradients)" "BBloch=$(BBloch)"
 
PASSFLGS   = \
             "NOTSOLO=$(NOTSOLO)" "MODLIBS=$(MODLIBS)" "STATLIB=$(STATLIB)"\
             "LOCMIRRORBASE=$(PROJECTPATH)/$(GAMDIST)" \
             "COPY2BASE=$(PROJECTPATH)/$(GAMDIST)" \
             "CC=$(CC)" \
             "CFLAGS=$(CFLAGS)" \
             "LDFLAGS=$(LDFLAGS)" \
             "C++=$(CXX)" \
             "C++FLAGS=$(C++FLAGS)" \
             "ARCH=$(host)" \
             "PROJECTPATH=$(PROJECTPATH)" \
             "MAKE=$(MAKE)"
 
 
###############################################################################
###############################################################################
#                                                                             #
#              GAMMA MAKEFILE COMPILATION PATTERNS & TARGETS                  #
#                                                                             #
# The patterns and targets in this section are they that involve compilation  #
# of the GAMMA source codes into GAMMA module libraries.  This main makefile  #
# will recursively loop through the source code sub-directories. Each sub-    #
# directory contains a GAMMA "module" which will produce it's own library.    #
# Users can turn on/off the compilation of any library and/or it's inclusion  #
# during linking while building GAMMA programs.                               #
#                                                                             #
###############################################################################
###############################################################################

###############################################################################
#                                                                             #
#                   VARIABLES SPECIFIC TO THIS SECTION                        #
#                                                                             #
# These don't much matter in the current GAMMA makefile, the are deprecated   #
# because compilation now is recursive into the source code subdirectories.   #
#                                                                             #
# FILES  - All the GAMMA source code (file.cc) files                          #
# OBJ    - All the GAMMA object files (file.o) files                          #
# OBJP   - Same as OBJ but with profiling built in                            #
# LNAME  - The GAMMA library name 					      #
# LPNAME - The GAMMA library name made with profiling 		              #
#                                                                             #
###############################################################################

FILES           = 
OBJ             =
OBJP            =
LNAME           = libgamma.a
LPNAME          = libgamma_p.a


###############################################################################
#                                                                             #
# The makefile included below handles the default GAMMA build (all) in terms  #
# of binary libraries.  It also has a target to  build the libraries under    #
# profiling and targets to build GAMMA modules individually.                  #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
#    all       : Compiles GAMMA to produce libraries for linking.             #
#    profile   : Compiles GAMMA to produce libraries for profiling.           #
#    Basics    : Compiles the GAMMA Basics module                             #
#                       GAMMA MAKEFILE GNU STANDARD TARGETS                   #
#                                                                             #
# The targets in this section are those I haven't explictly done for GAMMA in #
# other sections.  The target names and performance are those suggested to be #
# present by the GNU Coding Standards.                                        #
#                                                                             #
# install:  Copies all GAMMA files of importance to specified location        #
# dist:     This just make a tar/gz file of GAMMA sources (= srcdist)         #
# fulldist: Makes many tar/gz files of various GAMMA packages                 #
# clean:    Cleans out all object files remaining after compilation           #
#                                                                             #
# Other GNU standard targets that are defined in other sections:              #
#                                                                             #
# all:   Compile GAMMA sources into GAMMA libraries                           #
# check: Perform self tests                                                   #
# clean: Remove all object files associated with GAMMA library build(s).      #
# distclean: Perform clean and remove library(s) for current distrubution.    #
#                                                                             #
###############################################################################


include make/MakeTargs
ALLFILESX =
allfiles: force
	@for i in $(SUBDIRS); do \
	  echo "In Subdirectory $${i} - Adding $${i}/MakeFiles" ; \
	  echo "Variable ALLFILES Is $(ALLFILES)"; \
      if [ -d ./$$i ] ; then \
		if (rootme=`pwd`/ ; export rootme ; \
		  include $$i/Makefiles; \
		  echo "$(ALLFILESX)"; \
          ALLFILESX += FILES) ; then true ; \
             else echo "exit 1"; exit 1 ; fi ; \
	  else echo "exit true"; true ; \
	  fi ; \
	done

###############################################################################
###############################################################################
#                                                                             #
#                       GAMMA MAKEFILE GNU STANDARD TARGETS                   #
#                                                                             #
# The targets in this section are those I haven't explictly done for GAMMA in #
# other sections.  The target names and performance are those suggested to be #
# present by the GNU Coding Standards.                                        #
#                                                                             #
# install:  Copies all GAMMA files of importance to specified location        #
# dist:     This just make a tar/gz file of GAMMA sources (= srcdist)         #
# fulldist: Makes many tar/gz files of various GAMMA packages                 #
# clean:    Cleans out all object files remaining after compilation           #
#                                                                             #
# Other GNU standard targets that are defined in other sections:              #
#                                                                             #
# all:   Compile GAMMA sources into GAMMA libraries                           #
# check: Perform self tests                                                   #
# force: Target that is never satisified soas to force another target to run. #
#                                                                             #
###############################################################################
###############################################################################



install: force
	@echo " "
	@echo "       Installing GAMMA Script In $(bindir) As $(PGMNAME)"
	@echo " "
	$(INSTALL) gamma $(bindir)/$(PGMNAME)

#dist: srcdist

fulldist: srcdist testsuite

###############################################################################
#                                                                             #
#           Source Compilation To Binary Object Files And Libraries           #
#                                                                             #
# The patterns and targets in this section are they that involve compilation  #
# of GAMMA sources codes and library production.                              #
#                                                                             #
# Note that this Makefile has NO DECLARED VARIABLES. All variables it uses    #
# stem from this file, either from explicitly being declared or from it       #
# having been declared in another included makefile.                          #
#                                                                             #
# Primary Targets:                                                            #
#                                                                             #
# buildvars: Output all variables relevant to using this makefile to screen.  #
#            This is done in a nicely formatted manner and useful in Makefile #
#            debugging. Most GAMMA users will not wish to use this.           #
#                                                                             #
###############################################################################

include make/MakeBuild

###############################################################################
#                                                                             #
#                     Base Demos and Base Demos Distribution                  #
#                                                                             #
# The patterns and targets in this section are they that involve compilation  #
# & running of GAMMA demo programs as well as targets to distribute the demo  #
# programs.                                                                   #
#                                                                             #
# Note that this Makefile has NO DECLARED VARIABLES. All variables it uses    #
# stem from this file, either from explicitly being declared or from it       #
# having been declared in another included makefile.                          #
#                                                                             #
# Primary Targets:                                                            #
#                                                                             #
# demo:     Runs the base demos. All base demos will be run and output sent   #
#           to the screen.                                                    #
# demodist: Makes a base demo distribution. Both tar.gz and zip are made      #
#           unless the flags DEMOUNIX and DEMOWINDOWS are set empty.          #
# demovars: Output all variables relevant to using this makefile to screen.   #
#                                                                             #
# Variables:                                                                  #
#                                                                             #
#                                                                             #
# GVERSION    - Current GAMMA version, set in Makefile MakeGam (e.g. 4.0.7)  #
# GAMDIST     - Name of demo distribution mock directory. This will be used   #
#               in issuing the tar or zip command. This variable will be      #  
#               defined in  the Makefile MakeGam                              #  
# PROJECTPATH - Directory where the tar command is issued from. Hopefully     #  
#               this is also where the mock directory $GAMMA/demo/ resides    #
#               containing copied demo distribution files. This variable will #
#               be defined in the main GAMMA Makefile.                        #  
# NPD         - Makefile --no-print-directory directive.                      #
# GAMPGMSCR   - GAMMA program script name. For example, gamma.                #  
# GAMWEBDEM   - Web URL where GAMMA demos may be downloaded.                  #  
# GAMWEBBUG   - Web URL where GAMMA bugs may be reported.                     #  
# GAMWEBINST  - Web URL where GAMMA installation instructions are.            #  
# DEMOUNIX    - Flag if Unix-like distribution is to be made (demopkg.tar.gz) #
# DEMOWINDOWS - Flag if Windows-like distribution is to be made (demopkg.zip) #
# DEMODIR     - GAMMA demo directory name. For example, demo.                 #  
# DEMODIST    - GAMMA demo dist. directory name, e.g. ./$GAMMAVER/demo.       #  
# DEMOFILES   - Name of all base demo files that will be released in a base   #
#               demo distribution. Relative to demo directory, e.g. demo1.cc  #
# DEMORELEASE - Name of all base demo files that will be released in a base   #
#               demo distribution. Relative to GAMMAVER directory, for        #  
#               example ./demo/demo1.cc                                       #
# DEMOTAR     - Name of the demo distribution tar file to be created.         #  
#               This will be defined in the Makefile MakeGam                  #  
# GZIPPGM     - Name of program that will compress tar files (tar->tar.gz)    #
# GZIPFLGS    - Flags for the compression program GZIPPGM (usually none)      #  
# DEMOGZIP    - Name of the demo distribution gz file to be created from the  #
#               Unix type compression of the demo tar file, DEMOTAR.          #  
#               This variable will be defined in the Makefile MakeGam.        #  
# ZIPPGM      - Program that compresses distribution directory (pkzip or zip) #
# ZIPFLGS     - Flags for the compression program ZIPPGM (usually -p -r)      #  
# DEMOZIP     - Name of the demo distribution zip file to be created from the #
#               Windows type compression of demo distrib. directory, GAMDIST. #
#                                                                             #
###############################################################################

NPD          = --no-print-directory
DEMOFILES    = RunDemos index.html demo.txt plot.html Makefile\
               demo1.cc demo1.html demo2.cc demo2.html \
               demo3.cc demo3.html demo3.gif demo3.sys \
               demo4.cc demo4.html demo4.gif demo4.dsys demo4aux.cc 
DEMOUNIX     = "1"
DEMOWINDOWS  = "1"
GAMPGMSCR    = gamma
GAMWEBDEM    = http://gamma2.magnet.fsu.edu/download/demo/
GAMWEBBUG    = http://gamma2.magnet.fsu.edu/info/bugrep/
GAMWEBINST   = http://gamma2.magnet.fsu.edu/install/

include make/MakeDemo

###############################################################################
#                                                                             #
#                          Testing And Test Distribution                      #
#                                                                             #
# The patterns and targets in this section are they that involve testing of   #
# GAMMA performance and distribution of test source codes. For the tests      #
# herein to work 1.) GAMMA must be installed, 2.) A vaild C++ compiler must   #
# be operational, and 3.) The test programs should reside in $GAMMA/test.     #
# The first two are fundamental before GAMMA will work and the latter is what #
# is provided in the GAMMA test distribution.                                 #
#                                                                             #
# Note that this Makefile has NO DECLARED VARIABLES. All variables it uses    #
# stem from this file, either from explicitly being declared or from it       #
# having been declared in another included makefile.                          #
#                                                                             #
# Primary Targets:                                                            #
#                                                                             #
# test     : Test the GAMMA platform.  This will compile an overall test      #
#            program then run it, sending the test results to screen.         #
#            Unlike other GAMMA testing (testsuite) this does not demand use  #
#            of the DejaGnu test framework (expect, tcl, etc..)               #
# testdist : Creates a distribution file of GAMMA test programs.  A           #
#            similar testdist is run recursively in GAMMA module makefiles.   #
# testvars : Output all variables relevant to using this makefile to screen.  #
#            This is done in a nicely formatted manner and useful in Makefile #
#            debugging. Most GAMMA users will not wish to use this.           #
#                                                                             #
# Variables:                                                                  #
#                                                                             #
# GAMMAPGM   : GAMMA program command, in MakeGam, Makefile included (gamma4)  #
# GVERSION   : Current GAMMA version, in MakeGam, Makefile included (4.0.7)  #
# MAKE:      : The makefile being worked with. Set when invoking Make         #
# SUBDIRS    : Subdirectories with recursive Makefiles for the distribution   #
#              This will be declared in the main GAMMA makefile.              #
# PASSFLGS   : The flags that will be passed to the recursed makefiles. This  #
#              variable will be specified in the main GAMMA makefile.         #
# PROJECTPATH: Directory where the tar command is issued from. Hopefully      #
#              this is also where the mock directory $GAMMA/test/ resides     #
#              containing copied test distribution files. This variable will  #
#              be defined in the main GAMMA Makefile.                         #
# GAMDIST    : Name of test distribution mock directory. This will be used    #
#              as the based directory where copied files are sent. This       #
#              variable will be defined in  the Makefile MakeGam              #
# MAKEDIST     Name of test distribution mock make directory. This will be    #
#               the location where GAMMA test related make files are copied   #
#                                                                             #
#                  Imported From MakeGam, Test Section                        #
#                                                                             #
# TESTDIR    - GAMMA testing directory name (test)                            #
# TESTDIST   - Relative Temp Dir Used For GAMMA Testing Distributions         #
# TESTNAME   - Base name of test source distribution file (GamTstSrc4.0.7)   #
# TESTTAR    - Test source distribution tar file name (GamTst4.0.7.tar)      #
# TESTZIP    - Test source distribution zip file name (GamTst4.0.7.tar.gz)   #
# TESTPGM    - Test program run when "make test" is invoked (source name)     #
# TESTBIN    - Test program run when "make test" is invoked (binary name)     #
# TESTDIRF   - Test distribution files in the test (not module) directory     #
# TMAKEDIRF  - Test distribution files in the make (not module) directory     #
# TESTDIRFF  - Like TESTDIRF but relative to the GAMMA main directory         #
# TMAKEDIRFF - Like TMAKEDIRF but relative to the GAMMA main directory        #
#                                                                             #
###############################################################################

include make/MakeTest

###############################################################################
#                                                                             #
#                          Source Code Distribution                           #
#                                                                             #
# The makefile included below exclusively handles the GAMMA source code       #
# distributions.                                                              #
#                                                                             #
# Note that this Makefile has NO DECLARED VARIABLES. All variables it uses    #
# stem from this file, either from explicitly being declared or from it       #
# having been declared in another included makefile.                          #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
#    srcdist   : Creates a distribution file of GAMMA sources.                #
#                A similar srcdist is run recursively in GAMMA makefiles.     #
#    srcvars   : Outputs a list of variables used by make during source       #
#                code distributions.                                          #
#    srcclean  : Removes any temporary sources from an earlier distribution   #
#                                                                             #
# Variables:                                                                  #
#                                                                             #
# GVERSION   : Current GAMMA version, in MakeGam, Makefile included (4.0.7)  #
# MAKE       : The makefile being worked with. Set when invoking Make         #
# SUBDIRS    : Subdirectories with recursive Makefiles for the distribution   #
#              This will be declared in the main GAMMA makefile.              #
# PASSFLGS   : The flags that will be passed to the recursed makefiles. This  #
#              variable will be specified in the main GAMMA makefile.         #
# PROJECTPATH: Directory where the tar command is issued from. Hopefully      #
#              this is also where the mock directory $GAMMA/src/ resides      #
#              containing copied source distribution files. This variable will#
#              be defined in the main GAMMA Makefile.                         #
# GAMDIST    : Name of source distribution mock directory. This will be used  #
#              as the based directory where copied files are sent. This       #
#              variable will be defined in  the Makefile MakeGam              #
# MAKEDIST   : Name of source distribution mock make directory. This will be  #
#              the location where GAMMA source related make files are copied  #
#              to. The variable will be defined in the Makefile MakeGam       #
# MAKEDIR    : Name of the makefile direcotry (e.g. make)                     #
#                                                                             #
#             Imported From MakeGam, Source Distribution Section              #
#                                                                             #
# SRCDIR     - GAMMA source directory name (src)                              #
# SRCDIST    - Relative Temp Dir Used For GAMMA Source Distributions          #
# SRCNAME    - Base name of source distribution file (e.g. GamSrc4.0.7)      #
# SRCTAR     - Source distribution tar file name (e.g. GamSrc4.0.7.tar)      #
# SRCZIP     - Source distribution zip file name (e.g. GamSrc4.0.7.tar.gz)   #
# SRCDIRF    - Source distribution files in source (not module) directory     #
# SRCDIRFF   - Like SRCDIRF but relative to the GAMMA main directory          #
# SMAKEMAINF - Source distribution files in the make (not module) directory   #
# SMAKEMODF  - Source distribution files in the make (not module) directory   #
# SMAKEDIRF  - Source distribution files in the make (not module) directory   #
# SMAKEDIRFF - Like SMAKEDIRF but relatvie to the GAMMA main directory        #
# MAINFILES  - Source distribution files in the main GAMMA directory          #
#                                                                             #
###############################################################################

include make/MakeSrc

###############################################################################
#                                                                             #
# The makefile included below exclusively handles the GAMMA binary (library)  #
# distributions.                                                              #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
#   bindist  - Builds a GAMMA binary distrubution (single file) for release.  #
#   bindistd - Same as above but only does a dry run to show what will occur. #
#                                                                             #
# Dependencies:                                                               #
#                                                                             #
# SUBDIRB     - Subdirectories with Makefiles handling binary distributions.  #
# MAINBFILES  - Main directory files added to binary distribution             #
# GVERSION    - GAMMA version being worked with.                              #
# host        - Target host for build (ala GNU conformance)                   #
# MAKE        - The make program being used                                   #
# PASSFLGS    - Flags passed to recursive makefiles.                          #
# PROJECTPATH - The base GAMMA directory for this version.                    #
# GAMDIST     - Directory where binary distribution will be created.          #
# HOSTDIST    - Directory where distribution for this host will be.           #
# LIBDIST     - Directory where library files will be copied.                 #
# BINDIST     - Directory where library files will be copied.                 #
# SRCDIST     - Directory where source files will be copied.                  #
# SRC         - Directory where source files reside.                          #
# LIB         - Directory where library binary files reside.                  #
# BINTAR      - Binary distribution tar file.                                 #
# BINZIP      - Binary distribution zipped file.                              #
#                                                                             #
###############################################################################

SUBDIRB    = Basics Matrix GamIO Level1 HSLib LSLib Level2 WBR \
             IntRank2 Floquet Deprecated Pulses
MAINBFILES = Makefile README README.html gamma

include make/MakeBin

###############################################################################
#                                                                             #
#                    Microsoft Visual C++ Related Distributions               #
#                                                                             #
# The makefile included below exclusively handles the GAMMA distributions     #
# viable for use with Microsoft Visual C++.                                   #
#                                                                             #
# Note that this Makefile has NO DECLARED VARIABLES. All variables it uses    #
# stem from this file, either from explicitly being declared or from it       #
# having been declared in another included makefile.                          #
#                                                                             #
# Included Targets                                                            #
#                                                                             #
# msvcstatic:     Creates a distribution file of the GAMMA MSVC++ workspace   #
#                 and projects which build static libraries.                  #
# msvcdynamic:    Creates a distribution file of the GAMMA MSVC++ workspace   #
#                 and projects which build dynamic (DLL) libraries.           #
# msvctest:       Creates a distribution file of the GAMMA MSVC++ workspace   #
#                 and projects which build GAMMA testing programs.            #
# msvcexample:    Creates a distribution file of the GAMMA MSVC++ workspace   #
#                 and projects which build GAMMA example programs.            #
# msvcstaticlib:  Creates a distribution file of the GAMMA MSVC++ built static#
#                 single library.                                             #
# msvcdynamiclib: Creates a distribution file of the GAMMA MSVC++ built       #
#                 dynamic single library.                                     #
# msvcstaticlibs: Creates a distribution file of the GAMMA MSVC++ built static#
#                 multiple module libraries.                                  #
# msvcdynamiclibs:Creates a distribution file of the GAMMA MSVC++ built       #
#                 dynamic multiple module libraries.                          #
# msvcinstalldoc: Creates a distribution file of the GAMMA MSVC++ related     #
#                 html installation documentation.                            #
#                                                                             #
# Required Variables                                                          #
#                                                                             #
# GVERLEV0:       GAMMA base version level (e.g. 4 of 4.0.3B)                 #
# GVERLEV1:       GAMMA secondary version level (e.g. 0 of 4.0.3B)            #
# GSUBVER:        GAMMA sub-version level (e.g. 3B of 4.0.3B)                 #
# GVERSION:       Current GAMMA version (e.g. 4.0.7)                         #
# MAKE:           Current Makefile (e.g. gmake or make)                       #
# NPD:            No print directory command (--no-print-directory)           #
# PROJECTPATH:    This Directory, Main GAMMA Directory This Version           #
# GAMDIST:        Relative Temp Dir Used For GAMMA Package Distributions      #
# ZIPPGM:         Name of (windoze) program which does the compression.       #
# ZIPFLGS:        Program flags to use with (windows) compression execution.  #
# MSVCSTATICDIR:  Name of the Visual C++ static project directory (static)    #
# MSVCDYNAMICDIR: Name of the Visual C++ dynamic project directory (dynamic)  #
# MSVCLIBDIR:     Name of the Visual C++ library directory (i786-pc-msvc)     #
# MSVCTESTDIR:    Name of the Visual C++ test project directory (test)        #
# MSVCDEMODIR:    Name of the Visual C++ demo project directory (demo)        #
# MSVCEXAMPLEDIR: Name of the Visual C++ example project directory (example)  #
#                                                                             #
###############################################################################

include make/MakeMSVC

###############################################################################
#                            Target: variables                                #
#                                                                             #
# This include Makefile contains targets for looking at variables defined in  #
# the makefile itself. This is used only to debug the Makefile.               #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
# variables - Print out the variables used in this & recursed Makefiles       #
#                                                                             #
###############################################################################

include make/MakeVars

###############################################################################
#                    These Targets Deal With The GAMMA Tests 		      #
#                                                                             #

# The Target "dist-tape" Is Intended To Produce a Tar File Which Contains All
# Distrubuted GAMMA Files.  These Will Be ALL Files Found In The GAMMA base
# Subdirectory (sources in $GAMMA/SRC, tests in $GAMMA/tests, ....), & Includes
# The GAMMA Makefile And Binaries For The Current Computer Architecture
 
dist-tape: $(files)
	tar cvf gamma.$(GVERSION).tar GNUmakefile bin src\
		applic tests

# The Target "src-tar" Is Intended To Produce a Tar File Which Contains All
# Platform Independent GAMMA Files.  This Will Contain ALL Files Found In The
# GAMMA "src" Subdirectory And The ASCII Files In The Main Directory
# (GNUmakefile, GAMMA Script, README's, ....)
 
src-tar:
	@echo
	@echo "Making A Source Distribution, GAMMA Version $(GVERSION)"
	@echo
	tar cvf gamma.$(GVERSION).tar $(addprefix ./src/, $(lfiles))\
	./src/gamma4.h $(addprefix ./, $(asc)) ./examples
	gzip gamma.$(GVERSION).tar
 
#
# The Target "full-tape" Is Intended To Produce a Tar File Which Contains All
# GAMMA Files.  These Will Be ALL Files Found In Subdirectories "bin" and
# "src" As Well As The GAMMA Makefile.  Unlike Target "dist-tape", This Is
# A Means For A Full GAMMA Backup, Including Any Local Programs and Experimental
# Files If The User Keeps Them in "bin" And "src".
 
full-tape:
	tar cvf gamma.full.tar GNUmakefile bin src

#
# The Target "bindist" Takes the Systems Current GAMMA Library and Sources And
# Produces a Single File Which is A Binary Distribution Which Is Architecture
# Dependent.  The Resulting File Will Be Tarred and Compressed and Will Contain
# Only the Code Headers, Isotope List, System Specific Compiled Library, The
# Script Which Executes GAMMA, And Some Other Notes.  Currently, This Just Runs
# As A Simple Script, It Will NOT Update GAMMA - It Uses the Current State.

tmpdir		= $(PROJECTPATH)/$(host)/gammax
#BINDIST		= $(tmpdir)/gamma-$(GVERSION)
binadd		= $(PROJECTPATH)/bininc

#bindist: 	
#	@echo
#	@echo "Making A Binary Distribution, GAMMA Version $(GVERSION) For $(host)"
#	@echo
#	-mkdir $(tmpdir)
#	-chmod ug+w $(tmpdir)
#	-mkdir $(BINDIST)
#	-chmod ug+w $(BINDIST)
#	-mkdir $(BINDIST)/$(host)
#	-chmod ug+w $(BINDIST)/$(host)
#	-mkdir $(BINDIST)/$(host)/lib
#	-chmod ug+w $(BINDIST)/$(host)/lib
#	-cp $(LIB)/* $(BINDIST)/$(host)/lib
#	-rm -rf $(BINDIST)/$(host)/lib/*.o
#	-mkdir $(BINDIST)/src
#	-chmod ug+w $(BINDIST)/src
#	-cp $(src)/* $(BINDIST)/src
#	-cp $(binadd)/demo/* $(BINDIST)
#	-cp $(binadd)/$(host)/* $(BINDIST)
#	-rm -rf $(BINDIST)/src/*.cc
#	-rm -rf $(BINDIST)/src/*.gz
#	-rm -rf $(BINDIST)/src/*.tar
#	(cd $(tmpdir); tar cvf gambin.$(host).$(GVERSION).tar ./gamma-$(GVERSION))
#	(cd $(tmpdir); gzip gambin.$(host).$(GVERSION).tar)
#	-mv $(tmpdir)/gambin.$(host).$(GVERSION).tar.gz $(PROJECTPATH)
#	rm -rf $(tmpdir)
 
###############################################################################
#                              Generic Targets                                #
###############################################################################
  
############################################################################### 
#                             Target: subdir_do                               #
#                                                                             #
# This is used to push the make target to Makefiles in all subdirectories     #
# listed in the variable $SUBDIRS.  Note that the make target name is in the  #
# variable $DO and that any flags required by subsequent makes must be placed #
# into the variable $PASSFLGS.                                                #
#                                                                             #
############################################################################### 
 
# sosi
subdir_do: force
	@echo "In subdir do with $(SUBDIRS)"
        @for i in $(SUBDIRS); do \
           echo "Making $(DO) in $${i}..." ; \
           if [ -d ./$$i ] ; then \
             if (rootme=`pwd`/ ; export rootme ; \
               rootsrc=`cd $(srcdir); pwd`/ ; export rootsrc ; \
               cd ./$$i; \
               $(MAKE) $(PASSFLGS) $(DO)) ; then true ; \
             else echo "exit 1"; exit 1 ; fi ; \
           else echo "exit true"; true ; fi ; \
	   echo "finished up with subdir_do";\
        done
 

MAINMAKEDIR   = make
DOSCLEANFILES = gamma.in

###############################################################################
###############################################################################
########################### GAMMA Auxiliary Targets ###########################
###############################################################################
###############################################################################

###############################################################################
#                                                                             #
#                           Help On Makefile Use                              #
#                         (May Be Called Directly)                            #
#                                                                             #
# This included Makefile contains a target that prints information regarding  #
# the Makefile and it usage.                                                  #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
# help:   Print message to screen.                                            #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# force:         Required target for use of this makefile                     #
#                                                                             #
###############################################################################

help:
	@echo
	@echo "	                    GAMMA Makefile Usage"
	@echo "	                    ===================="
	@echo
	@echo "	This is the main Makefile for GAMMA. It serves the purpose of building"
	@echo "	GAMMA libraries, making GAMMA distributions, and running GAMMA demo"
	@echo "	and test programs. This Makefile will recurse through various sub-"
	@echo "	directories branching off of this location, making use of Makefiles"
	@echo "	found in those directories as well as those found in the directory make"
	@echo "	stemming from this directory. Note that this Makefile MUST be configured"
	@echo "	prior to its use. In an command shell use "./configure" to perform the"
	@echo "	configuration to make the Makefile suitable for your computer/OS. Main"
	@echo "	Makefile targets are listed below:"
	@echo
	@echo "	make      - Build GAMMA library (binaries)"
	@echo "	make all  - Build GAMMA library (binaries)"
	@echo "	make dist - Make a GAMMA distribution (tar.gz & zip)"
	@echo "	make help - Diplay the message you are reading now."
	@echo
	@echo "	make cleandir - Remove any non-GAMMA files (recursive)"
	@echo "	make killdos  - Remove any DOS linefeeds   (recursive)"
	@echo

###############################################################################
#                                                                             #
#                             Directory Cleaning                              #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   cleandir:   Remove spurious files for directory                           #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# MAKELEVEL:     Level of recursed makefile (automatic)                       #
# CLEANCONTENTS: Contents of directory (cosmetic)                             #
# CLEANSUBDIRS:  Directories to recuse in cleaning.                           #
# MAKE:          Make program being used (automatic)                          #
# NPD:           No print directory directive (--no-print-directory)          #
# PASSFLAGS:     Variables to pass to recursive make files.                   #
# CURDIR:        Current directory name (automatic)                           #
# cleanfiles:    Target which does the cleaning locally                       #
# force:         Required target for use of this makefile                     #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/CleanDir

cleanfiles: force
	@echo " * Cleaning Files In ${CURDIR}"
	@rm -rf *.zip
	@rm -rf *.tar
	@rm -rf *.gz
	@rm -rf ${TARDIR}
	@echo " * Finished With This Cleaning"


###############################################################################
###############################################################################
######################### GAMMA Source Distributions ##########################
###############################################################################
###############################################################################
#                                                                             #
# The included files below supply targets and variables that are primarly     #
# concerned with GAMMA source distributions. They DO NOT deal with any source #
# code compilations nor distribution of any binary files.                     #
#                                                                             #
###############################################################################

###############################################################################
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
# dist    Make a GAMMA distribution                                (MainDist) #
# killdos Clean all files defined in MODDISTFILES                  (MainDist) #
# update  Update all files in UPDATEFILES, recurse DISTSUBDIRS.    (MainDist) #
#                                                                             #
# Supplied Variables                                                          #
# ==================                                                          #
# none                                                                        #
#                                                                             #
# Required Targets                                                            #
# ================                                                            #
# distribute    Make a source distribution                      (MAINMAKEDIR) #
# newdistdir    Make temp source distribution directory         (MAINMAKEDIR) #
#                                                                             #
# Required Variables                                                          #
# ==================                                                          #
# MAKELEVEL:     Makefile recursion level                         (automatic) #
# MAKE:          Make program being used                          (automatic) #
# NPD:           Print directory directive (--no-print-directory)             #
# DISTDIR:       Temp. distribution directory name.                   (above) #
# DISTBASE:      Temp. distribution directory base name.              (above) #
# UPDATEFILES:   Files that should be updated                                 #
# UPDATEDIRS:    Subdirectories which should be recursed                      #
# DOSCLEANDIRS:  Directories to be recursed during cleaning (above)           #
# DOSCLEANFILES: All files that will be cleaned of DOS line ends.             #
# force:         Required target for use of this makefile                     #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/MainDist

###############################################################################
###############################################################################
########################## GAMMA Source Dependencies ##########################
###############################################################################
###############################################################################
#                                                                             #
# The following target is intended to deduce all dependencies between the     #
# GAMMA source codes. It will write the dependencies into the GAMMA Makefile  #
# "Makefile" (i.e. at the end of this file!).                                 #
#                                                                             #
###############################################################################

depend:
	makedepend $(addsuffix .cc,$(addprefix $(SRC)/, $(modules))) -fGNUmakefile

# DO NOT DELETE THIS LINE -- make depend depends on it.

