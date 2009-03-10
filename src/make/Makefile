###############################################################################
#                                                                             #
#                 Makefile For GAMMA Sources Make Directory                   #
#                      Copyright c 2002 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# =========================================================================== #
#                                                                             #
# Quick Info: 1.) GAMMA Source Make Directory Makefile.                       #
#             2.) Handles Source Makefile Distributions.                      #
#             3.) Removes DOS LineFeeds From Makefiles                        #
#                                                                             #
###############################################################################

SRCDIR        = src
DISTBASE      = ${CURDIR}/$(GVERDIR)
DISTSRC       = ${DISTBASE}/${SRCDIR}
DISTDIR       = ${DISTSRC}/make
PASSFLGS      = 
MODLABEL      = make
DIRCONTENTS   = Make

HDRFILES   = 
CCFILES    = 
HTMLFILES  = index.html
INCFILES   = Makefile CleanDir CopyDir DieDOSDie Distribute FirstTarg HdrDist \
             MakefileBP Modules SrcDist TarZipDir Variables
DISTFILES  = ${HDRFILES} ${CCFILES} ${HTMLFILES} ${INCFILES}

TARDIR        = ./${GVERDIR}
MAINMAKEDIR   = ../../make
SUBDIRS       = 
UPDATEFILES   =
UPDATEDIRS    =
DOSCLEANFILES = ${INCFILES}
DOSCLEANDIRS  = 
DIRCONTENTS   = "Sources Makefile"
CLEANCONTENTS = "Sources Makefiles"
MODLABEL      = "Make"
CLEANSUBDIRS  =

help:
	@echo "	This Makefile serves the purpose of distributing the files in this"
	@echo "	directory whenever required by GAMMA distributions. It is normally"
	@echo "	recursively by Makefiles earlier in the GAMMA directory hierarchy."
	@echo "	There are few, if any, make targets worthy of running directly from"
	@echo "	this directory. If you inssist:"
	@echo
	@echo "	make		Display this message."
	@echo "	make help	Display this message."
	@echo "	make cleandir 	Remove any spurious files from this directory."
	@echo "	make killdos 	Remove any DOS line returns from Makefiles"
	@echo


dist: distribute

distdir: force
        ifeq (0,${MAKELEVEL})
	  @${MAKE} $(NPD) distdirsolo;
        else
	  @${MAKE} $(NPD) newdistdir;
        endif


distdirsolo:
	@echo ""
	@echo "     Making GAMMA Sources Make Directory Distribution";
	@echo "     ------------------------------------------------";
	@echo ""
	@echo " * We Will Copy The Source Make Directory To A Temporary Directory"
	@echo "   Directory Will Be $(DISTDIR)"

	@if (test -d $(DISTBASE)) \
        then \
          echo " * Temp Directory ${DISTBASE} Exists. We Must First Clear It And All"; \
	  echo "   Files In All Its Subdirectories" ; \
          echo " * Only $(MODLABEL) Being Packaged, Not Any Other GAMMA Files" ; \
	  echo " * Removing Directory $(DISTBASE)" ; \
          rm -rf $(DISTBASE); \
 	fi
	@echo " * Constructing New Directory $(DISTBASE)"
	@mkdir $(DISTBASE)
	@chmod ug+w $(DISTBASE)
	@echo " * Constructing New Directory $(DISTSRC)"
	@mkdir $(DISTSRC)
	@chmod ug+w $(DISTSRC)
	@echo " * Constructing New Directory $(DISTDIR)"
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
	@rm -rf *.zip
	@rm -rf *.tar
	@rm -rf *.gz
	@rm -rf *.~
	@rm -rf *.~*
	@if (test -d $(TARDIR)) \
	then \
	 echo " * Removing directory ${TARDIR}"; \
	 rm -rf ${TARDIR}; \
	fi

###############################################################################
###############################################################################
#################### GAMMA Source Makefile Distributions ######################
###############################################################################
###############################################################################
#                                                                             #
# The included files below supply targets and variables that are primarly     #
# concerned with GAMMA source Makefle distributions. They DO NOT deal with    #
# any source code compilations nor distribution of any binary files.          #
#                                                                             #
###############################################################################

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
# DOSCLEANFILES: All files that will be cleaned of DOS line ends.             #
# DOSCLEANDIRS:  Directories to be recursed during cleaning (set above)       #
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

disttar: TARFILE = ${GVERDIR}.srcmake.tar
disttar: tardir 
srctar:  TARFILE = ${GVERDIR}.srcmake.tar
srctar:  tardir 
hdrtar:  TARFILE = ${GVERDIR}.srcmake.tar
hdrtar:  tardir 

distgzip: TARFILE  = ${GVERDIR}.srcmake.tar
distgzip: GZIPFILE = ${GVERDIR}.srcdist.tar.gz
distgzip: gziptar
srcgzip:  TARFILE  = ${GVERDIR}.srcmake.tar
srcgzip:  GZIPFILE = ${GVERDIR}.srcmakesrc.tar.gz
srcgzip:  gziptar
hdrgzip:  TARFILE  = ${GVERDIR}.srcmake.tar
hdrgzip:  GZIPFILE = ${GVERDIR}.srcmakehdr.tar.gz
hdrgzip:  gziptar

distzip: ZIPFILE = ${GVERDIR}.srcmakedist.zip
distzip: zipdir
srczip:  ZIPFILE = ${GVERDIR}.srcmakesrc.zip
srczip:  zipdir
hdrzip:  ZIPFILE = ${GVERDIR}.srcmakehdr.zip
hdrzip:  zipdir

include ${MAINMAKEDIR}/TarZipDir

force:
