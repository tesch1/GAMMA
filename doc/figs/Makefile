###############################################################################
#                                                                             #
#                Makefile For GAMMA HTML Documentation Figures                #
#                      Copyright c 2002 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# =========================================================================== #
#                                                                             #
# Quick Info: 1.) GAMMA Documentation Figures Directory Makefile.             #
#             2.) Handles Documentaiton Figures Distributions.                #
#                                                                             #
# =========================================================================== #
#                                                                             #
# This Makefile serves only to handle GAMMA distributions. The figures in     #
# this directory are distributed when ever the GAMMA documentation is         #
# distributed. That occurs in both a normal distribution, a source code       #
# distribution, and a documentation distribution.                             #
#                                                                             #
###############################################################################

SUBDIRS       =
HDRFILES      = 
CCFILES       = 
HTMLFILES     = 
IMGFILES      = bkground.gif bkground.jpg gamma.gif goldG.gif gsrc.gif meaning.gif src401.gif
INCFILES      = Makefile
DOSCLEANFILES = 
DISTFILES     = ${HDRFILES} ${CCFILES} ${HTMLFILES} ${INCFILES} ${IMGFILES}
DISTGVER      = ${CURDIR}/$(GVERDIR)
DISTBASE      = ${DISTGVER}/${PRIMALDIR}
DISTDIR       = ${DISTBASE}/figs
DISTSUBDIRS   = 
MAINMAKEDIR   = ../../make
UPDATEFILES   = 

dist: distribute 

distdir: force 
        ifeq (0,${MAKELEVEL})
 	  @${MAKE} $(NPD) distdirsolo;
        else
	  @${MAKE} $(NPD) distdirrecursive;
        endif

distdirsolo:
	@echo ""
	@echo "     Making GAMMA Documentation Figures Distribution";
	@echo "     -----------------------------------------------";
	@echo ""
	@echo "   Sorry. Distributions of Just the GAMMA Documentation Figures"
	@echo "   Is Not Allowed. There Is No Reason That I Can Think Of For"
	@echo "   Needing These Figures Without The Documentation Files That Use"
	@echo "   Them. Please Run Distribution Targets From (At Least) On Level"
	@echo "   Back In The GAMMA Directory Hierarchy."
	@echo

distdirrecursive:
	@echo " * Adding Documentation Figures To This Distribution"
	@echo " * We Will Copy The Figure Files To A Temporary"
	@echo "   Directory $(DISTDIR)"
	@if (test -d $(DISTDIR)) \
	then \
          echo " * This Temp Directory Exists. Clearing It And Files Therein"; \
          echo "   Removing Directory $(DISTDIR)" ; \
          rm -rf $(DISTDIR); \
	else \
          echo " * First Construct Temp Directory And Check Structure" ; \
	fi
	@echo " * Creating Fresh Temporary Directory For This Distribution"
	@echo "   Making Directory $(DISTDIR)"
	@mkdir $(DISTDIR)
	@chmod ug+w $(DISTDIR)

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
# PRIMALDIR = Name of primal makefiles directory (primal)                     #
#                                                                             #
# Requirements                                                                #
# ============                                                                #
# none                                                                        #   
#                                                                             #
###############################################################################

include ${MAINMAKEDIR}/MakeGam

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

disttar: TARFILE = ${GVERDIR}.primaldist.tar
disttar: tardir 
srctar:  TARFILE = ${GVERDIR}.primalsrc.tar
srctar:  tardir 
hdrtar:  TARFILE = ${GVERDIR}.primalhdr.tar
hdrtar:  tardir 

distgzip: TARFILE  = ${GVERDIR}.primaldist.tar
distgzip: GZIPFILE = ${GVERDIR}.primaldist.tar.gz
distgzip: gziptar
srcgzip:  TARFILE  = ${GVERDIR}.primalsrc.tar
srcgzip:  GZIPFILE = ${GVERDIR}.primalsrc.tar.gz
srcgzip:  gziptar
hdrgzip:  TARFILE  = ${GVERDIR}.primalhdr.tar
hdrgzip:  GZIPFILE = ${GVERDIR}.primalhdr.tar.gz
hdrgzip:  gziptar

distzip: ZIPFILE = ${GVERDIR}.primaldist.zip
distzip: zipdir
srczip:  ZIPFILE = ${GVERDIR}.primalsrc.zip
srczip:  zipdir
hdrzip:  ZIPFILE = ${GVERDIR}.primalhdr.zip
hdrzip:  zipdir

include ${MAINMAKEDIR}/TarZipDir

force:
