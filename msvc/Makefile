###############################################################################
#                                                                             #
#                 Makefile For GAMMA MSVC++ Projects Directory                #
#                      Copyright c 2002 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# =========================================================================== #
#                                                                             #
# Quick Info: 1.) GAMMA MSVC++ Directory Makefile.                            #
#             2.) Handles MSVC++ Project Distributions.                       #
#             3.) Recursively calls Makefiles in msvc subdirectories.         #
#                                                                             #
###############################################################################


###############################################################################
#                                                                             #
#                         Distribution Directories                            #
#                                                                             #
# MSVCDIR      - Name of the msvc makefiles subdirectory                      #
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
DISTBASE      = ${CURDIR}/${GVERDIR}
TARDIR        = ./${GVERDIR}
DISTDIR       = ${DISTBASE}/${MSVCDIR}
PASSFLAGS     = "DISTBASE=${DISTDIR}" 

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

DISTSUBDIRS   = static dynamic pygamma figs
CLEANSUBDIRS  = static dynamic pygamma
DOSCLEANDIRS  = static dynamic pygamma 
UPDATEDIRS    = static dynamic pygamma
MAKESUBDIRS   = 

HDRFILES      = 
CCFILES       = 
HTMLFILES     = index.html configure.html settingcc.html
INCFILES      = Makefile 
DISTFILES     = ${HDRFILES} ${CCFILES} ${HTMLFILES} ${INCFILES}
DOSCLEANFILES = ${DISTFILES} 
MAINMAKEDIR   = ../make
MSVCMAKEDIR = ./make
UPDATEFILES   = index.html configure.html
SRCMAKEDIR    = make
SRCMAKEFILE   = MakefileBP
DIRCONTENTS   = "MSVC++ Projects"

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
###############################################################################
###################### GAMMA Generic & Cosmetic Targets #######################
###############################################################################
###############################################################################
#                                                                             #
# The included files below supply targets and variables that are primarly     #
# used in other targets or of global applicability. Thes do not do much.      #
#                                                                             #
###############################################################################


help: force
	@echo
	@echo
	@echo "	This Makfile handles distributions and updates of the GAMMA"
	@echo "	msvc Makefiles sub-directory. Normally the targets supplied"
	@echo "	are run recursively from the main GAMMA Makefile. However, the"
	@echo "	supplied targets can be run directly if distributions/upgrades"
	@echo "	of only files in this sub-directory are desired. Here are what"
	@echo "	the supplied targets do:                                      "
	@echo 
	@echo "	make		Make a msvc Makefiles distribution (.tar.gz & .zip)"
	@echo "	make dist	Make a msvc Makefiles distribution (.tar.gz & .zip)"
	@echo "	make help	Output Makefile information and supplied targets"
	@echo "	make killdos    Remove DOS linefeeds from all files affected" 
	@echo "	make update     Update all files in distribution" 
	@echo "	make showdist   Display how a distribution will be accomplished"
	@echo "	make cleandir   Clean directory of spurious files (recursive)"
	@echo "	make showvars   Display all Makefile variables used herein"
	@echo
	@echo

cleandir:
	@echo " * Cleaning All Spurious Non-Essential Files"
	@for i in $(CLEANSUBDIRS); do \
          if [ -d ./$$i ] ; then \
            if (rootme=`pwd`/ ; export rootme ; \
              rootsrc=`cd $(srcdir); pwd`/ ; export rootsrc ; \
              cd ./$$i; \
              $(MAKE) $(NPD) $(PASSFLAGS) $@) ; then true ; \
            else exit 1 ; fi ; \
          else true ; fi ; \
	done
	@echo " * Cleaning Files In ${CURDIR}"
	@rm -rf *.zip
	@rm -rf *.tar
	@rm -rf *.gz
	@rm -rf ${TARDIR}
	@echo " * Finished With This Cleaning"

force:

###############################################################################
###############################################################################
##################  GAMMA MSVC++ Workspace Distribution Targets ###############
###############################################################################
###############################################################################
##                                                                           ##
## This section of the Makefile handles all GAMMA distributions of msvc.     ##
## makefiles. Normally, distribtions are accomplised using Makefiles earlier ##
## in the GAMMA directory hierarchy, so it should be RARE that any of these  ##
## targets are called directly. In contrast, these targets are critically    ##
## importatnt for GAMMA distributions. As such, below are listed targets and ##
## variables that this section should supply as well as any targets and      ##
## variables that are required at this point in the Makefile.                ##
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
## DIRCONTENTS:   Contents of dist dir [cosmetic]     (above =>  newdistdir) ##
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

distdir: force
        ifeq (0,${MAKELEVEL})
	  @${MAKE} $(NPD) distdirsolo;
        else
	  @${MAKE} $(NPD) newdistdir;
        endif

distdirsolo:
	@echo ""
	@echo "     Making GAMMA MS Visual C++ Directory Distribution";
	@echo "     -------------------------------------------------";
	@echo ""
	@echo " * We Will Copy The MSVC++ Workspace Directory & Files To A Temporary Directory"
	@echo "   Directory Will Be $(DISTDIR)"

	@if (test -d $(DISTBASE)) \
        then \
          echo " * Temp Directory ${DISTBASE} Currently Exists."; \
	  echo "   We Must First Clear It & Files In All Its Subdirectories" ; \
          echo " * Only Primal Makefile Directory Being Packaged, No Other GAMMA Files" ; \
	  echo " * Removing Directory $(DISTBASE)" ; \
          rm -rf $(DISTBASE); \
 	fi
	@echo " * Constructing New Directory $(DISTBASE)"
	@mkdir $(DISTBASE)
	@chmod ug+w $(DISTBASE)
	@echo " * Constructing New Directory $(DISTDIR)"
	@mkdir $(DISTDIR)
	@chmod ug+w $(DISTDIR)
 

#distdirrecursive:
#	@echo "${MAKELEVEL}"
#	@echo " * Adding Primal Makefile Directory To Distribution"
#	@echo " * We Will Copy The $(MODLABEL) Files To A Temporary"
#	@echo "   Directory $(DISTDIR)"
#	@${MAKE} $(NPD) newdistdir;

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
#             $(M(TARPGM=tar pgm, TARFLGS=tar pgm flags, TARFILE=tar file)    #
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
# UPDATEDIRS:    Subdirectories which should be recursed                      #
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
# DOSCLEANFILES:  All files cleaned of DOS linefeeds.        (set above)      #
# force:          Required target for use of this makefile   (set above)      #
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
# CURDIR:        Directory containing files to be copied. (automatic)         #
# DISTFILES:     Files in this directory to copy.         (set above)         #
# DISTDIR:       Directory name where copies will be put  (set above)         #
# TARDIR:        Directory (local) where copies are put   (set above)         #
# force:         Required target for use of this makefile (set above)         #
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

disttar: TARFILE = ${GVERDIR}.msvcdist.tar
disttar: tardir 
srctar:  TARFILE = ${GVERDIR}.msvcsrc.tar
srctar:  tardir 
hdrtar:  TARFILE = ${GVERDIR}.msvchdr.tar
hdrtar:  tardir 

distgzip: TARFILE  = ${GVERDIR}.msvcdist.tar
distgzip: GZIPFILE = ${GVERDIR}.msvcdist.tar.gz
distgzip: gziptar
srcgzip:  TARFILE  = ${GVERDIR}.msvcsrc.tar
srcgzip:  GZIPFILE = ${GVERDIR}.msvcsrc.tar.gz
srcgzip:  gziptar
hdrgzip:  TARFILE  = ${GVERDIR}.msvchdr.tar
hdrgzip:  GZIPFILE = ${GVERDIR}.msvchdr.tar.gz
hdrgzip:  gziptar

distzip: ZIPFILE = ${GVERDIR}.msvcdist.zip
distzip: zipdir
srczip:  ZIPFILE = ${GVERDIR}.msvcsrc.zip
srczip:  zipdir
hdrzip:  ZIPFILE = ${GVERDIR}.msvchdr.zip
hdrzip:  zipdir

include ${MAINMAKEDIR}/TarZipDir

