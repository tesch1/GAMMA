###############################################################################
#                                                                             #
#                        Makefile For A GAMMA Module                          #
#                      Copyright © 2000 Scott A. Smith                        #
#                  National High Magnetic Field Laboratory                    #
#                         1800 E. Paul Dirac Drive                            #
#                     Tallahassee, FL, USA 32306-4005                         #
#                          ssmith@magnet.fsu.edu                              #
#                      On WWW See gamma.magnet.fsu.edu                        #
#                                                                             #
# This Makefile is intended to be called recursively from the main GAMMA      #
# makefile, $GAMMA/Makefile.  It's purpose is to handle compilation and       #
# distribution of files in this GAMMA module. This file should reside in      #
# the module directory from the GAMMA source directory, $GAMMA/src. It will   #
# NOT be different from any other GAMMA module's Makefile. Module specifics   #
# are imported in, as are common segements shared by all module Makefiles.    #
#                                                                             #
#    IT IS UNLIKELY YOU WOULD EVER NEED TO MAKE CHANGES IN THIS FILE!         #
#             SPECIFICS FOR THIS FILE ARE FOUND IN MakeDefs                   #  
#                                                                             #
# All module specifics are included in the file MakeDefs.  If any changes are #
# needed for this specific module change ./MakeDefs.  If any changes are      #
# required for targets change the included segments in ../Make* so that they  #
# will apply to all module Makefiles.                                         # 
#                                                                             #
# The primary targets provided by this makefile are:                          #  
#                                                                             #
# all:     This is the 1st (default) target to build the module from sources. #
#          A library for this module will be generated through source code    #
#          compilation.                                                       #
# profile: This target builds the module from sources with the profiling. It  #
#          is similar to the above target except that generated binaries will #
#          contain additional information that enables programs to be run     #
#          with profiling turned on.                                          #
# force:    Dummy target to insure a target is run.                           #
# srcdist: Copies source distribution files to a temporary directory. If not  #
#          run recursively (from the main GAMMA Makefile) will tar and zip    #
#          these files into a package for distribution.                       #  
# srcvars: Output all variables relevant to using this makefile to screen.    #
#          This is done in a nicely formatted manner and useful in Makefile   #
#          debugging. Most GAMMA users will not wish to use this.             #  
# bindist: Target. Distributes files define in $(HFILES) and $(SUPPF)         #
#                                                                             #
# Users are free to copy this file for personal use but may NOT give out      #
# modifications with or without the GAMMA platform.  This GAMMA module's      #
# source distrubution is typically packaged with the full GAMMA source        #
# distribution.  The full src distrubution and one for just this module may   #
# be obtained from the GAMMA WWW site above or any of its mirrors.            #
#                                                                             #
###############################################################################

###############################################################################
#                                                                             #
#                            Module Specific Definitons                       # 
#                                                                             #
# The following included Makefile controls GAMMA module specifics.  It is in  #
# this file where anything specific to the module in this directory should be #
# specified.  It contents are listed below.                                   #
#                                                                             #
# LIBBASE  - Base Name of Module Library                                      #
# DIRNAME  - The Local Directory Name                                         #
# DIRNAMEUL - Cosmetic Underline Of Local Directory Name                      #
# FNAMES   - Base Names of Source/Header Files in The Module. Thus All The    #
#            Module Source Code to Be Compiled Are in $(FNAMES).cc And Their  #
#            Associated Interface Files $(FNAMES).h.  The Resulting Object    #
#            Files Will Be $(FNAMES).o.                                       #
#                                                                             #
###############################################################################

include ./MakeDefs

###############################################################################
#                                                                             #
#                         Non-Specific Module Definitions                     #
#                                                                             #
# These are generated from the variables defined in ./ModDefs.  The ones used #
# from ./ModDefs are                                                          #
#                                                                             #
# DIRNAME   - The Local Directory Name                                        #
# DIRNAMEUL - Cosmetic Underline Of Local Directory Name                      #
# LIBBASE   - The Base Name of the Module Library                             #
#                                                                             #
# The variables set in this section are as follows:                           #
#                                                                             #
# MODLABEL - This Modules Label for Output                                    #
# MODLABUN - This Modules Label Output Underlining                            #
# BASENAME - Base Name Of Output File(s) To Be Produced                       #
# RCSSCR   - Script That Maintains The Module Via RCS                         #
# LIBNAME  - Module Static Library Name                                       #
# LIBNAMEP - Module Static Library With Profiling Name                        #
#                                                                             #
###############################################################################

GAMBASEVER    = 4
GAMSUBVER     = 0
GAMSUBSUBVER  = 4B
GVERSION      = $(GAMBASEVER).$(GAMSUBVER).$(GAMSUBSUBVER)
GVERDIR       = gamma-$(GVERSION)
MODLABEL      = GAMMA $(DIRNAME)
MODLABUN      = ------$(DIRNAMEUL)
BASENAME      = $(DIRNAME)Src
RCSSCR        = $(DIRNAME)RCS
LIBNAME       = lib$(LIBBASE).a 
LIBNAMEP      = lib$(LIBBASE)_p.a
NOTSOLO       = ""
PASSFLGS      = ""
NPD           = --no-print-directory                                            
SRCDIR        = src
TARPGM        = tar
TARFLGS       = cf
GZIPPGM       = gzip
GZIPFLGS      =  
ZIPPGM        = pkzip
ZIPFLGS       = -p -r
MODULEDIR     = $(shell pwd)
COPY2BASE     = ./$(GVERDIR)

MODCCFILES    = $(addsuffix .cc, $(addprefix $(SRCLOCAL)/, $(FNAMES)))
MODHFILES     = $(addsuffix .h,  $(addprefix $(SRCLOCAL)/, $(FNAMES)))
MODDEFFILE    = $(addprefix $(SRCLOCAL)/, MakeDefs)
MODMAKEFILE   = $(addprefix $(SRCLOCAL)/, Makefile)
MODHSUMFILE   = $(addprefix $(SRCLOCAL)/, $(HDRFILE))
MODSRCFILES   = $(MODCCFILES) $(MODHFILES) $(MODMAKEFILE) $(MODDEFFILE) $(MODHSUMFILE)
MODHDRFILES   = $(MODHFILES) $(MODMAKEFILE) $(MODDEFFILE) $(MODHSUMFILE)

###############################################################################
#                                                                             #
# Start with an included Makefile that sets up the typically GNU boiler-plate #
# definitions (srcdir, prefix, bindir, libdir, infodir, mandir, host,....).   #
# This will also set up standard SUFFIXES and the SHELL variable. Compiler    #
# flags will be set herein too. These are as follows:                         #
#                                                                             #
# .SUFFIXES - Clears out any implicit make rules that might be present        #
# .SUFFIXES - Adds back in implicit make rules that we might want to use      #
# SHELL     - Don't want SHELL variable inherited from environment (want sh)  #
# CXX      - The C++ Compiler To Be Used                                      #
# CXXFLAGS - The C++ Compiler Flags To Be Used                                #
# RANLIB    - The ranlib program to use.  Set as RANLIB = : if not required.  #
# GCXXFLAGS - Additonal C++ Compiler Flags That GAMMA Uses                    #
# SRCLOCAL  - Local module source directory
#                                                                             #
# Note that ../MakeGen is generated from a typical Gnu configuration from the #
# file ../MakeGen.in.  This is done when "./configure" is run from the base   #
# GAMMA directory for the current GAMMA version.                              #
#                                                                             #
###############################################################################

include ../../make/MakeModGen

###############################################################################
#                                                                             #
#                            Files Under Make Control                         #
#                                                                             #
# Below are the module specific files that this Makefile deals with.  There   #
# are two essential points to understanding this section.  First, the local   #
# file ./ModDefs will contain the variable FNAMES. It is therein that sets    #
# up base names of the source & header files associate with specific modules. #
# Second, the file ../MakeFiles will expand upon the FNAMES variable and      #
# construct additonal variables that, when used in different generic targes,  #
# cause the target to deal with files specific to a particular GAMMA module.  #
#                                                                             #
# Thus, change variable FNAMES in ./MakeDefs to affect the particular module  #
# being dealt with.  Change ../MakeFiles to change any definitions to be used #
# which are based on FNAMES.                                                  #
#                                                                             #
# Here are the current definitions:                                           #
#                                                                             #
# FNAMES: "filename" where filename.h & filename.cc are souce code files that #
#         are part of this module.  These will be compiled into the module    #
#         library.                                                            #
# BINSUPP:Supplementary files to be included in the binary distrubution.      #
# SUPPF:  Supplementary files to be include in the source distrubution.       #
# FILES:  These are automatically formed  herein from the base filenames set  #
#         in FNAMES. The are the source interface and implementation files.   #
# OBJ:    These are automatically formed herein from the base filenames set   #
#         in FNAMES. The are the object file names after source compilation.  #
#         Note that unlike the names in FILES, these will contain the full    #
#         GAMMA library path.                                                 #
# OBJP:   Same as OBJ but used when profiling.                                #
#                                                                             #
# Note that the files defined by FNAMES.h should also be represented in the   #
# module header file called HDRFILE as well as in the RCS control script      #
# RCSSCR. The former will affect how GAMMA generally takes this package       #
# whereas the latter helps to maintain these files (but does not affect GAMMA #
# program directly.)                                                          #
#                                                                             #
###############################################################################

#include ../../make/MakeModFiles

###############################################################################
#                                                                             #
# The next included Makefile is concerned with building GAMMA libraries from  #
# object files and, in turn, building GAMMA object files from source code.    #
# The following patterns will be defined herein:                              #
#                                                                             #
# $(LIB)/file.o      <-- $(SRCLOCAL)/file.cc   - Object files from cc files   #
# $(LIB)/file_p.o    <-- $(SRCLOCAL)/file.cc   - Same as above with profiling #
# $(LIB)/$(LIBNAME)  <-- $(LIB)/{file.o}       - Library from object files    #
# $(LIB)/$(LIBNAMEP) <-- $(LIB)/{file_p.o      - Same as above with profiling #
#                                                                             #
# Targets included in the Makefile are as follows:                            #
#                                                                             #
# all:      This is the 1st (default) target to build GAMMA from sources.     #
# profile:  This is the target to build GAMMA from sources with profiling.    #
# force:    Dummy target to insure a target is run.                           #
# clean:    Target to both object and source files.                           #
# cleanobj: Target to clean just object files.                                #
#                                                                             #
###############################################################################

include ../../make/MakeModTarg

###############################################################################
#                                                                             #
#                         Source & Header Distributions                       #
#                                                                             #
# The following included Makefile controls GAMMA source code distributions.   #
# Typically GAMMA sources are copied to a temporary directory, compressed     #
# into a single file, then moved to a release location. If running SOLO then  #
# modules sources/headers are copied in the temporary location, packaged into #
# a single file, and then the copied files deleted. If running NONSOLO then   #
# it is assumed that the Makefile is running recursively and only the module  #
# sources/headers are copied into a temporary location.  In this case it is   #
# up to the make recursing into the module Makefile to do packaging and and   #
# temporary file deletions. Targets supplied here exist to release the full   #
# sources or just the headers. Variations allow for the packaged release to   #
# be in Windows-like zip format or Unix-like tar.gz form (when run SOLO).     #
#                                                                             #
# Required Variables (MUST Be Defined Herein):                                #
# ============================================                                #
#                                                                             #
# NOTSOLO     Controls if targets run recursively (NOTSOLO) or not.           #
# NPD         Direct print supression flag (--no-print-directory).  This will #
#             be defined in the generic file $GAMMAVER/$MAKE/MakeGam but that #
#             definition will only be used when running NONSOLO.  If SOLO the #
#             definition of NPD will stem from the definition in this file.   #
# MODLABEL    Module Name. Used for output to screen when make runs.          #
# MODLABEL    This Modules Labe Underlining for Output                        #
# MODULEDIR   Name of module directory to be copied.                          #  
# COPY2BASE   Base name of the distribution directory. This should be passed  #
#                                                                             #
# Supplied Patterns:                                                          #
# ==================                                                          #
#                                                                             #
# $(LIB)/file.o      <-- $(MODULEDIR)/file.cc  - Object files from cc files   #
# $(LIB)/file_p.o    <-- $(MODULEDIR)/file.cc  - Same as above with profiling #
# $(LIB)/$(LIBNAME)  <-- $(LIB)/{file.o}       - Library from object files    #
# $(LIB)/$(LIBNAMEP) <-- $(LIB)/{file_p.o      - Same as above with profiling #
#                                                                             #
# Supplied Targets:                                                           #
# =================                                                           #
#                                                                             #
# buildvars - Write out the variables used in source/header distributions.    #
#                                                                             #
###############################################################################

include ../../make/MakeModBuild

###############################################################################
#                                                                             #
#                         Source & Header Distributions                       #
#                                                                             #
# The following included Makefile controls GAMMA source code distributions.   #
# Typically GAMMA sources are copied to a temporary directory, compressed     #
# into a single file, then moved to a release location. If running SOLO then  #
# modules sources/headers are copied in the temporary location, packaged into #
# a single file, and then the copied files deleted. If running NONSOLO then   #
# it is assumed that the Makefile is running recursively and only the module  #
# sources/headers are copied into a temporary location.  In this case it is   #
# up to the make recursing into the module Makefile to do packaging and and   #
# temporary file deletions. Targets supplied here exist to release the full   #
# sources or just the headers. Variations allow for the packaged release to   #
# be in Windows-like zip format or Unix-like tar.gz form (when run SOLO).     #
#                                                                             #
# Required Variables (MUST Be Defined Herein):                                #
# ============================================                                #
#                                                                             #
# NOTSOLO     Controls if targets run recursively (NOTSOLO) or not.           #
# NPD         Direct print supression flag (--no-print-directory).  This will #
#             be defined in the generic file $GAMMAVER/$MAKE/MakeGam but that #
#             definition will only be used when running NONSOLO.  If SOLO the #
#             definition of NPD will stem from the definition in this file.   #
# MODLABEL    Module Name. Used for output to screen when make runs.          #
# MODLABEL    This Modules Labe Underlining for Output                        #
# MODULEDIR   Name of module directory to be copied.                          #  
# COPY2BASE   Base name of the distribution directory. This should be passed  #
#             into the Makefile when being run recursively (NONSOLO) in the   #
#             $PASSFLAGS variable.  It will be defined below as "." when the  #
#             make is run in SOLO mode.                                       #
# GVERDIR     Name of GAMMA version directory (gamma-4.0.4B).                 #
# SRCDIR      Name of GAMMA source directory (src).                           #
# MODSRCFILES Source files that will be distributed with the module.          #  
# MODHDRFILES Header files that will be distributed with the module.          #  
# TARPGM      Tar program (usually tar). Used if SOLO & Unix style output.    #
# TARFLGS     Tar flags (ususally cf). Used if SOLO & Unix style output.      #
# GZIPPGM     Compression program (usually gzip). Works on TARFILE if running #
#             SOLO with Unix style output.                                    #  
# GZIPFLGS    Compression flags (usually nothing). Used when running SOLO     #
#             with Unix style output.                                         #
# ZIPPGM      Compression program that condenses distribution (pkzip or zip). #
#             Used when runnin SOLO with Windows style output.                #
# ZIPFLGS     Compression program flags. Used when running SOLO with Windows  #
#             style output (-p -r).                                           #
#                                                                             #
# Supplied Targets:                                                           #
# =================                                                           #
#                                                                             #
# srcdist  - Makes tar/gzipped file of all GAMMA module sources.  (SOLO)      #  
#          - Copies all modules sources to temporary directory.   (NONSOLO)   #
# hdrdist  - Makes tar/gzipped file of all GAMMA module headers.  (SOLO)      #  
#          - Copies all modules headers to temporary directory.   (NONSOLO)   #
# srcddist - Makes zipped file of all GAMMA module sources.       (SOLO)      #  
#          - Copies all modules sources to temporary directory.   (NONSOLO)   #
# hdrddist - Makes zipped file of all GAMMA module headers.       (SOLO)      #  
#          - Copies all modules headers to temporary directory.   (NONSOLO)   #
# srcvars  - Write out the variables used in source/header distributions.     #  
#                                                                             #
###############################################################################

include ../../make/MakeModSrc

###############################################################################
#                                                                             #
#                             Binary Distributions                            #
#                                                                             #
# The following included Makefile controls GAMMA binary distributions.        #
# Typically GAMMA libraries and headers are copied to a temporary directory,  #
# compressed into a single file, then moved to a release location. The        #
# sources that are copies in the temporary location are subsequently deleted. #
#                                                                             #
# bindist     - Target. Distributes files define in $(HFILES) and $(SUPPF)    #
# NOTSOLO     - controls whether make runs recursively (cleans itself) or not #
# LABEL       - Used for output to screen when make runs                      #
# LABELUN     - Same as above.                                                #
# MODULEDIR   - GAMMA module actual directory                                 #
# LOCALMIRROR - Where the temporary files will be copied.                     #
# TARFILE     - Tarred file that will be created from sources                 #
# ZIPFILE     - Zip file that will be created from sources                    #
#                                                                             #
###############################################################################
 
include ../../make/MakeModBin

###############################################################################
#                                                                             #
#                                Variable Checking                            #
#                                                                             #
# This included Makefile contains targets for looking at variables defined in #
# the makefile itself. This is normally used only to debug the Makefile.      #
#                                                                             #
# Targets:                                                                    #
#                                                                             #
# variables  - Print out the variables used in this module's Makefile         #
# gnuvars    - Output just the boilerplate GNU variables (set in configure)   #
# compvars   - Output just the compiler related variables                     #
# gcntrlvars - Output the GAMMA version control variables                     #
# dirvars    - Output the GAMMA directory variables                           #
# pkgvars    - Output the GAMMA package variables                             #
# srcfiles   - Output a list of module source (.cc) files                     #
# hdrfiles   - Output a list of module header (.h) files                      #
# objfiles   - Output a list of module object files                           #
#                                                                             #
# Note that variables will output {gnu,comp,gcntrl,dir,pkg}vars as well.      #
#                                                                             #
###############################################################################

include ../../make/MakeModVars

################################################################################
#                                                                              #
#                     How To Run This Makefile Directly                        #
#                                                                              #
# To get a source distrubution:                                                #
#                                                                              #
# One may choose to run this directly in order to generate a zipped file       #
# containing only the source distrubution for this GAMMA module. In doing      #
# so, one does not include the rest of the GAMMA source distribution.          #
# To run the Makefile directly for source distrubution, issue the command      #
#                                                                              #
#                             make srcdist                                     #
#                                                                              #
# from this directory.  Since this provides the Makefile with no additional    #
# variables, the default setting of this makefile will be used.                #
#                                                                              #
# ---------------------------------------------------------------------------- #
#                                                                              #
#                     How To Run This Makefile Recursively                     #
#                                                                              #
# To get a source distrubution:                                                #
#                                                                              #
# As mentioned earlier, this is designed to be run recursively from the Level  #
# 0 Makefile, namely $GAMMA/Makefile.  This make is run from the former        #
# by issuing                                                                   #
#                             make srcdist                                     #
#                                                                              #
# from the $GAMMA directory, as long as "Basics" is listed as one of the       #
# modules in that Makefile (not in this one).  Use of this Level 0 makefile is #
# superior in that it includes the entire GAMMA source distribution, not just  #
# the source files for the this module.                                        #
#                                                                              #
################################################################################
