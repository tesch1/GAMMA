###############################################################################
#                                                                             #
#               Makefile For GAMMA MSVC++ Dynamic Library Projects            #
#                      Copyright c 2002 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# =========================================================================== #
#                                                                             #
# Quick Info: 1.) GAMMA MSVC++ Project Directory For Dynamic Library.         #
#             2.) Handles Project Distributions, NOT COMPILATIONS.            #
#                                                                             #
# =========================================================================== #
#                                                                             #
# This Makefile serves ONLY to handle GAMMA distributions, specifically the   #
# distribution of MSVC++ workspace and projects to build and use a GAMMA      #
# dynamic library. It is the workspace using MSVC++ that build these projects #
# This makefile DOES NOT build any binaries at all. It only distributions the #
# MSVC++ files that allow users to do such builds.                            #
#                                                                             #
###############################################################################

###############################################################################
#                                                                             #
#                         Distribution Directories                            #
#                                                                             #
# MSVCDIR      - Name of the msvc makefiles subdirectory                      #
# THISDIR      - Name of the current directory (local)                        #
# DISTBASE     - Base distribution directory                                  #
# TARDIST      - Name of distribution directory (local)                       #
# DISTDIR      - Name of distribution directory (full)                        #
# PASSFLAGS    - Variables passed to recursive Makefiles                      #
#                                                                             #
# Note that PASSFLAGS contains DISTBASE set to this distributions directory.  #
# This is so that, during recursive distributions, the distribution directory #
# can be set to stem off of this directory.                                   #
#                                                                             #
###############################################################################

MSVCDIR       = msvc
THISDIR       = dynamic 
DISTGVER      = ${CURDIR}/$(GVERDIR)
DISTBASE      = ${DISTGVER}/${MSVCDIR}
TARDIR        = ./${GVERDIR}
DISTDIR       = ${DISTBASE}/${THISDIR}
PASSFLAGS     = "DISTBASE=${DISTDIR}"
DIRCONTENTS   = GAMMA DLL Build

###############################################################################
#                                                                             #
#                       Directories For Recursions                            #
#                                                                             #
# DISTSUBDIRS  - Directories recursed during a distribution                   #
# DOSCLEANDIRS - Directories recursed when removing DOS line endings          #
# CLEANSUBDIRS - Directories recursed when cleaning spurious files            #
# UPDATEDIRS   - Directories recursed when updating files to latest versions  #
# MAKESUBDIRS  - Directories which have their Makefiles updated               #
#                                                                             #
# The above variables are similar but often NOT the same. This is because one #
# would not wish a figures directory cleaned of DOS linefeeds (i.e. directory #
# figs part of DOSCLEANDIRS) but be part of the distribution (DISTSUBDIRS).   #
# Similarly many makefiles to not get updated (in MAKESUBDIRS) but they do    #
# get distributed (DISTSUBDIRS) and DOS cleaned (DOSCLEANDIRS)                #
#                                                                             #
###############################################################################

DISTSUBDIRS   =
DOSCLEANDIRS  = 
CLEANSUBDIRS  = 
UPDATEDIRS    =
MAKESUBDIRS   = 

###############################################################################
#                                                                             #
#                        Files Treated By Make Targets                        #
#                                                                             #
# HDRFILES      - Header files (in dist, source dist, header dist)            #
# CCFILES       - Source files (in dist, source dist)                         #
# HTMLFILES     - HTML doc files (in dist, source dist)                       #
# IMGFILES      - Image files (in dist, source dist)                          #
# INCFILES      - Other included files (in dist, source dist)                 #
# DISTFILES     - Files included in distributions                             #
# DOSCLEANFILES - Files that are to be DOS line endings cleaned               #
# UPDATEFILES   - Files that we attempt to update to newest versions.         #
#                                                                             #
###############################################################################

HDRFILES      = 
CCFILES       = 
HTMLFILES     = index.html
IMGFILES      = 
INCFILES      = Makefile clean.bat build.bat
MSVCFILES     = gamma.dsp gamma.dsw gamma.ncb gamma.opt \
                moduledemos.dsp moduletests.dsp gamma.mak 
DISTFILES     = ${HDRFILES} ${CCFILES} ${HTMLFILES} ${INCFILES} ${IMGFILES} ${MSVCFILES}
DOSCLEANFILES = index.html Makefile
UPDATEFILES   = index.html
#MSVCFILES     = gamma.def moduledemos.dsp moduletests.dsp moduletests.dsw moduletests.ncb moduletests.opt

###############################################################################
#                                                                             #
#               Included Makefile Directory Location (Relative)               #
#                                                                             #
# MAINMAKEDIR - Where the Main GAMMA Makefile Directory Is Located.           #
#                                                                             #
###############################################################################

MAINMAKEDIR   = ../../make

###############################################################################
#                                                                             #
#                          GAMMA Related Variables                            #
#                                                                             #
# The next included file supplies this Makefile with serveral variables that  #
# are related to GAMMA itself as well as variables that are generically used  #
# in most GAMMA makefiles.                                                    #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
# none                                                                        #   
#                                                                             #
# Supplied Variables                                                          #
# ==================                                                          #
#                                                                             #
# PACKAGE   = Name of GAMMA package (gamma)                                   #
# GVERSION  = Current GAMMA version number (e.g. 4.1.0)                       #
# GVERDIR   = Current GAMMA version base directory (e.g. gamma-4.1.0)         #
# MSVCDIR = Name of msvc makefiles directory (msvc)                           #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# none                                                                        #   
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/MakeGam

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
#   help:   Print message to screen.                                          #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# force:         Required target for use of this makefile                     #
#                                                                             #
###############################################################################

help:
	@echo
	@echo "      MSVC++ Projects Dynamic Library SubDirectory Makefile"
	@echo
	@echo " This Makefile serves the purpose of distributing the files in this"
	@echo " directory whenever required by GAMMA distributions. It is normally"
	@echo " run recursively by Makefiles earlier in the GAMMA directory hierarchy."
	@echo " There are few, if any, make targets worthy of running directly from"
	@echo " this directory. If you insist:"
	@echo
	@echo " make            Display this message."
	@echo " make help       Display this message."
	@echo " make cleandir   Remove any spurious files from this directory."
	@echo " make killdos    Remove any DOS line returns from Makefiles"
	@echo " make lib        Build GAMMA DLL from the command line"
	@echo
	@echo " Of course, Makefiles need a make program in order to work. So if you"
	@echo " are totally Microsoft, you may not have a make program and this file"
	@echo " will be of no use to you at all. Both make and a nice command shell"
	@echo " come with Cygwin and MinGW/MSys which is how I use these in a Windows"
	@echo " environment."
	@echo

###############################################################################
#                                                                             #
#                            Directory Cleaning                               #
#                         (May Be Called Directly)                            #
#                                                                             #
# This included Makefile contains a target that will remove of any spurious   #
# files that might have gotten into this directory and any of the sub-        #
# directories specified in CLEANSUBDIRS. Spurious files can be left behind    #
# during test builds (.o, .exe, .out, .a, .so files left behind), or maybe    #
# editing (~ files left), or running programs that leave output files (.asc,  #
# .gnu, .log). Whatever their cause, this target should be used to remove     #
# them. The target will recurse through the subdirectories listed in variable #
# CLEANSUBDIR. What files are cleaned in any particular subdirectory must be  #
# specified by the target cleanfiles. Note that this is NOT the same as the   #
# common GNU targets "make clean" or "make distclean". They function quite    #
# differently.                                                                #
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
# cleanfiles:    Target which does the cleaning locally                       #
# force:         Required target for use of this makefile                     #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/CleanDir

cleanfiles: force
	@rm -rf *.~
	@rm -rf *.~*
	@if (test -d $(TARDIR)) \
	then \
	  echo " * Removing directory ${TARDIR}"; \
	  rm -rf ${TARDIR}; \
	fi

makemake:

showvars:

force:

lib: MAKE_MODE=WIN32
lib: SHELL=cmd.exe
lib:
	@echo ${SHELL}
	build.bat
#lib:
#	cmd.exe /c build.bat


###############################################################################
###############################################################################
############  GAMMA Primal Makefile Makefiles Distribution Targets ############
###############################################################################
###############################################################################
##                                                                           ##
## This section of the Makefile handles all GAMMA distributions of msvc    ##
## makefiles make subdirectory. Normally, distribtions are accomplised using ##
## Makefiles earlier in the GAMMA directory hierarchy, so it should be RARE  ##
## that any of these targets are called directly. In contrast, these targets ##
## are critically importatnt for GAMMA distributions. As such, below are     ##
## listed targets & variables that this section should supply as well as any ##
## targets & variables that are required at this point in the Makefile.      ##
##                                                                           ##
## Supplied Targets                                                          ##
## ================                                                          ##
## dist:        GNU standard target for distributions                (below) ##
## distribute:  Make a GAMMA distribution [gz & zip]           (MAINMAKEDIR) ##
## distributeg: Make a GAMMA distribution [gz only]            (MAINMAKEDIR) ##
## distributez: Make a GAMMA distribution [zip only]           (MAINMAKEDIR) ##
## makedirs:    Make new distribution directories [solo]        (SRCMAKEDIR) ##
## newdistdir:  Make new directory for distribution [recurse]  (MAINMAKEDIR) ##
## update:      Update files to latest version                 (MAINMAKEDIR) ##
## killdos:     Clean files from DOS line returns              (MAINMAKEDIR) ##
## copyall:     Copy all files specified for distribution      (MAINMAKEDIR) ##
## deleteall:   Delete all files copyied for distribution      (MAINMAKEDIR) ##
## showcopy:    Show how copying is to be performed            (MAINMAKEDIR) ##
## tardir:      Produce tar file                               (MAINMAKEDIR) ##
## gziptar:     Product gz file from tar file                  (MAINMAKEDIR) ##
## zipdir:      Produce zip file                               (MAINMAKEDIR) ##
##                                                                           ##
## Required Variables                                                        ##
## ==================                                                        ##
## MAKE:          Make program being used                        (automatic) ##
## NPD:           Print dir. directive [--no-print-directory]      (MakeGam) ##
## UPDATEFILES:   Files that should be updated.            (above => update) ##
## UPDATEDIRS:    Subdirectories which should be recursed. (above => update) ##
## PASSFLAGS:     Variables passed to recursed Makefiles. (above => various) ##
## MODLABEL       Cosmetic label for the source module.  (above => cleandir) ##
## MODULEDIR      Directory name of the source module.   (above => cleandir) ##
## DISTFILES:     Files in this directory to copy.        (above => copydir) ##
## DISTBASE:      Base directory for distribution.       (above => makedirs) ##
## DISTSRC:       Directory of source distribution.      (above => makedirs) ##
## DISTDIR:       Directory name where copies are put.   (above => multiple) ##
## DOSCLEANFILES: All files that are DOS cleaned.         (above => killdos) ##
## TARDIR         Directory to archive               (below => {tar,zip}dir) ##
## TARPGM         Tar program to use.                           (Distribute) ##
## TARFLGS        Tar program flags to use.                     (Distribute) ##
## TARFILE        Tar file to make.                             (Distribute) ##
## GZIPPGM        Unix compression program [gzip]               (Distribute) ##
## GZIPFLGS       Unix compression program flags []             (Distribute) ##
## GZIPILE        Zip (gz) file name                      (below => gziptar) ##
## ZIPPGM         PC compression program [zip,pkzip]            (Distribute) ##
## ZIPFLGS        PC compression program flags [-p -r]          (Distribute) ##
## ZIPILE         Zip (zip) file name                      (below => zipdir) ##
## CURDIR:        Directory containing files to copy             (automatic) ##
##                                                                           ##
## Required Targets                                                          ##
## ================                                                          ##
## force:         Dummy target to force target execution.                    ##
##                                                                           ##
###############################################################################
###############################################################################
###############################################################################

dist: distribute

distdir:
        ifeq (0,${MAKELEVEL})
	  @${MAKE} $(NPD) distdirsolo;
        else
	  @${MAKE} $(NPD) newdistdir;
        endif

distdirsolo:
	@echo ""
	@echo "    Making GAMMA MSVC++ Dynamic Library Workspace Distribution";
	@echo "    ------0---------------------------------------------------";
	@echo ""
	@echo "   Sorry. Distributions of Just the GAMMA Dynamic Workspace Files"
	@echo "   Is Not Allowed. There Is No Reason That I Can Think Of For"
	@echo "   Needing These Makefiles Without The Other Associated Projects"
	@echo "   Akin To Them. Please Run Distribution Targets From (At Least)"
	@echo "   One Level Back In The GAMMA Directory Hierarchy."
	@echo

###############################################################################
#                                                                             #
#                             Distributions                                   #
#                         (May Be Called Directly)                            #
#                                                                             #
# This included Makefile contains targets for creating a GAMMA distribution.  #
# This is normally invoked by the Main GAMMA Makefile, but it can be run from #
# this Makefile as well. When run in from the main Makefile it will add all   #
# files to be distributed into what the main Makefile is planning to to. If   #
# run directly, only GAMMA source directory files can be distributed.         #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   distribute:  Make a GAMMA distribution (Both Unix gz and PC zip files)    #
#   distributeg: Make a GAMMA distribution (Unix gz file only)                #
#   distributez: Make a GAMMA distribution (PC zip file only)                 #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# MAKE:          Make program being used (automatic)                          #
# NPD:           No print directory directive (--no-print-directory)          #
# SUBDIRS:       Subdirectories which should be recursed                      #
# PASSFLAGS:     Variable settings that are passed to recursed Makefiles      #
# MAKELEVEL:     Level of Makefile being run (automatic)                      #
# CURDIR:        Current Makefile directory (automatic)                       #
# DISTDIR:       Temporary directory for file copies & distribution.          #
# TARDIR:        Same as DISTDIR but set relative to 1st Makefile directory.  #
# force:         Required target for use of this makefile                     #
# distdir:       Target that sets up temp dir. DISTDIR & cosmetic output      #
# killdos:       Target that removes DOS line feeds from files in DISTFILES   #
# copyall:       Target which copies files DISTFILES to temp dir. DISTDIR.    #
# distzip:       Target that makes a PC zip file from temp. directory TARDIR. #
# disttar:       Target which makes a tar file from temp. directory TARDIR.   #
#                (TARPGM=tar pgm, TARFLGS=tar pgm flags, TARFILE=tar file)    #
# distgzip:      Target which makes a gz file from tar file.                  #
# deleteall:     Target which deletes temp. directory DISTDIR & all its files #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/Distribute

###############################################################################
#                                                                             #
#                               File Updates                                  #
#                         (May Be Called Directly)                            #
#                                                                             #
# This included Makefile contains targets that will update all files in this  #
# directory and all of its subdirectoris. The files that will be updated are  #
# UPDATEFILES and the subdirectories recuresed are DISTSUBDIRS. Any targets,  #
# patterns, rules that update individual files or file types must be          #
# specified elsewhere.                                                        #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   update: Update all files in UPDATEFILES & recurse makefiles in            #
#           DISTSUBDIRS.                                                      #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# MAKE:          Make program being used (automatic)                          #
# NPD:           No print directory directive (--no-print-directory)          #
# UPDATEFILES:   Files that should be updated                                 #
# DISTSUBDIRS:   Subdirectories which should be recursed                      #
# PASSFLAGS:     Variable settings that are passed to recursed Makefiles      #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/Update

###############################################################################
#                                                                             #
#                         DOS LineEnding Adjustment                           #
#                         (May Be Called Directly)                            #
#                                                                             #
# This included Makefile contains targets for removing ^M from all files      #
# specified. This is normally invoked when any files from the source module   #
# are distributed. It will clean all files in variable DISTFILES in the       #
# directory that the Makefile is invoked in (CURDIR)                          #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   killdos:    Clean all files defined in MODDISTFILES                       #
#                                                                             #
# * Target killdos is the target one should typically use.                    #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# DISTFILES:  All files that will be distributed with the module.             #
# force:      Required target for use of this makefile                        #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/DieDOSDie

###############################################################################
#                                                                             #
#                               File Copying                                  #
#                       (Should NOT Be Called Directly)                       #
#                                                                             #
# This included Makefile contains targets for copying distributed files from  #
# one location to another. The files to be copied are listed in the variable  #
# DISTFILES & assumed in the current directory CURDIR. They will be copied to #
# the directory specified by DISTDIR. Additionally, there is a target for     #
# removing the directory DISTDIR and all files it contains. Note that the     #
# targets copyall and showcopy DO NOT RECURSE at all, but deleteall DOES.     #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   copyall:    Copy all files in DISTFILES in CURDIR to directory DISTDIR    #
#   deleteall:  Delete all files from DISTDIR (recursively, remove DISTDIR)   #
#   showcopy:   Show how copying is to be performed (but take no action)      #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# CURDIR:        Directory containing files to be copied.                     #
# DISTFILES:     Files in this directory to copy.                             #
# DISTDIR:       Directory name where copies will be put                      #
# force:         Required target for use of this makefile                     #
#                                                                             #
# Note: The Directory DISTDIR MUST EXIST prior to calling target copyall.     #
#       The task of producing this directory is usually done by whatever      #
#       target is producing a GAMMA distribution.                             #
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/CopyDelDir

###############################################################################
#                                                                             #
#                              File Archiving                                 #
#                       (Should NOT Be Called Directly)                       #
#                                                                             #
# These targets are involved with making a compressed file from a specified   #
# directory.                                                                  #
#                                                                             #
# Supplied Targets                                                            #
# ================                                                            #
#                                                                             #
#   tardir:    Produce tar file TARFILE of directory TARDIR using TARPGM      #
#   gziptar:   Product gz file from TARFILE using GZIPPGM                     #
#   zipdir:    Produce zip file ZIPFILE of directory TARDIR using ZIPPGM      #
#                                                                             #
# Supplied Variables                                                          #
# ==================                                                          #
#                                                                             #
# TARPGM        Program used to tar up directory TARDIR (tar)                 #
# TARFLGS       Flags used in conjunction with program TAR (cf)               #
# GZIPPGM       Program used to compress TARFILE (gzip)                       #
# GZIPFLGS      Flags used in conjunction with program GZIPPGM (none)         #
# ZIPPGM        Program used to zip up directory TARDIR (zip)                 #
# ZIPFLGS       Flags used in conjunctionwith program ZIPPGM (-r -q)          #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# TARDIR         Directory to archive with tar (or zip on DOS).               #
# TARPGM         Tar program to use.                                          #
# TARFLGS        Tar program flags to use.                                    #
# TARFILE        Tar file to make.                                            #
# GZIPPGM        Unix compression program (usually gzip)                      #
# GZIPFLGS       Unix compression program flags (usually nothing)             #
# GZIPILE        Zip (gz) file name                                           #
# ZIPPGM         PC compression program (zip in unix or pkzip in windows)     #
# ZIPFLGS        PC compression program flags (-p -r for pkzip)               #
# ZIPILE         Zip (zip) file name                                          #
# CURDIR:        Directory containing files to be copied.                     #
# force:         Required target for use of this makefile                     #
#                                                                             #
# Note that TARDIR should be a local name (Makefile relative) of the temp.    #
# distribution directory DISTDIR. This is so that any untar or unzip commands #
# will output files beginnng a the base directory of a GAMMA version, not the #
# base directory of where GAMMA is stored on the system running the make      #
# commands. In constrast, DISTDIR likely contains a full path directory name. #
#                                                                             #
###############################################################################

disttar: TARFILE = ${GVERDIR}.msvcmakedist.tar
disttar: tardir 
srctar:  TARFILE = ${GVERDIR}.msvcmakesrc.tar
srctar:  tardir 
hdrtar:  TARFILE = ${GVERDIR}.msvcmakehdr.tar
hdrtar:  tardir 

distgzip: TARFILE  = ${GVERDIR}.msvcmakedist.tar
distgzip: GZIPFILE = ${GVERDIR}.msvcmakedist.tar.gz
distgzip: gziptar
srcgzip:  TARFILE  = ${GVERDIR}.msvcmakesrc.tar
srcgzip:  GZIPFILE = ${GVERDIR}.msvcmakesrc.tar.gz
srcgzip:  gziptar
hdrgzip:  TARFILE  = ${GVERDIR}.msvcmakehdr.tar
hdrgzip:  GZIPFILE = ${GVERDIR}.msvcmakehdr.tar.gz
hdrgzip:  gziptar

distzip: ZIPFILE = ${GVERDIR}.msvcmakedist.zip
distzip: zipdir
srczip:  ZIPFILE = ${GVERDIR}.msvcmakesrc.zip
srczip:  zipdir
hdrzip:  ZIPFILE = ${GVERDIR}.msvcmakehdr.zip
hdrzip:  zipdir

include ${MAINMAKEDIR}/TarZipDir

