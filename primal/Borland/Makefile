#########################################################################
#                                                                       #
#        GAMMA Primal Makefile: Borland BC++ ==> (Py)GAMMA Library	#
#                                                                       #
# This Makefile will NOT build GAMMA using the Borland C++ compiler!    #
#                                                                       #
# We assume that the Borland make program will be used on the command   #
# line to build GAMMA from this directory. Since that make program does #
# not have the same capabilities as GNU make, typically a Borland       #
# compatible Makefile will be incompatible with a GNU makefile. That in #
# itself is not a problem, but I use GNU make for GAMMA distributions.  #
# Consequently, I cannot have Borland based make targets for building   #
# building (Py)GAMMA in the same directory as GNU based make targets    #
# for distributing GAMMA. What to do?					#
#                                                                       #
# 1.) Only targets for distributing GAMMA are in this Makefile   (GNU)	#
# 2.) Targets for building GAMMA are in Makefile.bor         (Borland)	#
#                                                                       #
# This makefile handles GAMMA distributions (as to all the other ones)  #
# where as one must use something akin to				#
#                                                                       #
#                       make -f Makefile.bor                            #
#                                                                       #
# when using Borland make to build GAMMA.				#
#                                                                       #
#########################################################################

#################################################################################
#										#
#                              GAMMA Distributions				#
#										#
# What follows has nothing to do with any builds of GAMMA. This stuff hass been #
# included in this Makefile only so that GAMMA distributions will inlcude the   #
# distributed files in this directory. Do not worry about this for any builds   #
# and or runs of GAMMA programs.						#
#										#
#################################################################################

THISDIR       = Borland
PRIMALPLAT    = "using Borland C++ compiler"
PRIMALMAKEDIR = ../make
MAINMAKEDIR   = ../../make
SUBDIRS       =
HDRFILES      =
CCFILES       =
HTMLFILES     = index.html
IMGFILES      =
INCFILES      = Makefile Makefile.bor MakeMods gamma.in cleanup.bat
DOSCLEANFILES = Makefile gamma.in
UPDATEFILES   = ${HTMLFILES}
DISTSUBDIRS   =
MODLABEL      = ${THISDIR}

include ${PRIMALMAKEDIR}/MakeDists
include ${PRIMALMAKEDIR}/CleanDir
include ${PRIMALMAKEDIR}/MakeHelp
include ${MAINMAKEDIR}/MakeGam
include ${MAINMAKEDIR}/Distribute
include ${MAINMAKEDIR}/Update
include ${MAINMAKEDIR}/DieDOSDie
include ${MAINMAKEDIR}/CopyDelDir
include ${MAINMAKEDIR}/TarZipDir

force:
