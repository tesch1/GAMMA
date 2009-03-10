#########################################################################
#                                                                       #
#          GAMMA Primal Makefile: Irix ==> (Py)GAMMA Library		#
#                                                                       #
# This is a primitive hand made Makefile to explicitly show how one     #
# builds and uses GAMMA as either a static or shared library & how one	#
# builds and uses PyGAMMA. It assumes that one is using the GCC C++	#
# compiler provided with (& amidst) Irix. At least, the binaries will	#
# be placed in a Irix related directory. So, run this makefile from a	#
# Irix bash shell so the environment for GCC, make, etc. are set up	#
# properly. As for PyGAMMA, one must have Python (build for Irix)	#
# as well as Boost.Python on the system.				#
#                                                                       #
# --------------------------------------------------------------------- #
#                                                                       #
#                             Quick Info                                #
#                                                                       #
#  1. Type "make" to build GAMMA shared object library. 		#
#  2. Type "make demo" to compile and run the GAMMA demo program(s).    #
#  3. Type "make test" to compile and run the GAMMA test program(s).    #
#  4. Type "make clean" to remove all object files.			#
#  5. Type "make distclean" to remove all object files libraries, exes.	#
#  6. The sources are assumed in SRCDIR == ../../src			#
#  7. The object are be produced in BINDIR ==  ../../i686-pc-linux-gnu  #
#  8. The lib files are produced in BINDIR ==  ../../i686-pc-linux-gnu  #
#  9. Any executable files (test,demo) are produced in this directory.	#
# 10. The important static library file is libgamma.a 			#
# 11. The important shared library file is libgamma.so			#
# 12. The important PyGAMMA shared library file is pygamma.so.		#
# 13. Produces the following: a.) libgamma.a - The GAMMA static library	#
#			      b.) libgamma.so  - The GAMMA shared lib.  #
#                             c.) pygamma.so - The PyGAMMA shared lib.  #
#                             e.) DemoGAMMA.out - The demo program	#
#                             f.) TestGAMMA.out - The test program	#
#                                                                       #
# --------------------------------------------------------------------- #
#                                                                       #
#                                 Notes					#
#                                                                       #
# This is NOT a standalone makefile. It includes an additional file	#
# ../../make/MakeMods which is part of standard GAMMA. This latter file #
# defines which files are part of the GAMMA source codes. Changes in    #
# MakeMods will evoke changes in the build herein.                      #
#									#
# all:									#
# make all: These both run the default target all (first target). It    #
#           will compile all source codes in GAMMA as defined in file	#
#           MakeMods into object files. It will then take the object	#
#           files and convert them into a static library named		#
#           libgamma.a. Similarly, other object files object files will	#
#	    be compiled and then be combined into a shared library of 	#
#           name libgamma.so. If we are able to find Python as well as 	#
#           and Boost.Python, then the PyGAMMA shared library is also	#
#           built, pygamma.so. All libraries and object	files will be	#
#           made in the directory specified by BINDIR. The shared libs. #
#	    will be relocated with added soft links when installed.	#
#									#
# make install: This will convert the file gamma.in into the working	#
#               script gamma and move it into a system file so that it	#
#               is accessible by all users. Additionally it will move	#
#               the shared library for GAMMA into a system directory 	#
#		place appropriate soft links so that it is generally	#
#               workable. Lastly, if PyGAMMA has been built, its	#
#               shared library pygamma.so will be moved into a Python	#
#               directory.						#
#									#
# make clean: This will delete all object files from any earlier build. #
#             It is important to run make clean since the object files  #
#             can use lots of disk space as well as interfere with      #
#             other GAMMA builds (not part of this Makefile)		#
#									#
# make demo : This will build and run a set of programs that demo the   #
#             the modules provided with GAMMA.				#
#                                                                       #
# make test: This will build and run a set of programs that test the	#
#             the modules provided with GAMMA.				#
#                                                                       #
#########################################################################

#########################################################################
#                                                                       #
#                Semi-Standard Gnuish Makefile Variables                #
#									#
# CXX         = C++ compiler (used in default compiler rules)		#
# CPPFLAGS    = C preprocessor flags (used in default C/C++ rules)	#
# CXXFLAGS    = C++ compilation flags (used in default C++ builds)	#
#									#
# The default rule in make that uses the variables CXX, CPPFLAGS and	#
# CXXFLAGS to generate object files from .cc files is as follows:	#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
#########################################################################

INSTALLDIR    = /usr
BININSTALLDIR = /usr/bin
LIBINSTALLDIR = /usr/lib
HDRINSTALLDIR = /usr/include/gamma-${VERNO}.${MINNO}.${RELNO}
SRCDIR        = ../../src
BINDIR        = ../../i686-pc-linux-gnu

DEBUG    = -g #-O2
CC       = gcc
CFLAGS   = $(DEBUG)

CXX      = c++
CPPFLAGS = -I"../../src" -DGSTATIC=1
CXXFLAGS = $(DEBUG)

LIBCPPFLAGS = -I"../../src"
LIBCXXFLAGS = $(DEBUG)

#SOCPPFLAGS = -I"${SRCDIR}"
SOCPPFLAGS = -I"../../src"
SOCXXFLAGS = -fPIC

PYCPPFLAGS = -Wall -ftemplate-depth-100 -DNDEBUG -DPYGAMMA -DBOOST_PYTHON_DYNAMIC_LIB \
             -O3 -Wno-inline -fPIC -fomit-frame-pointer -I"${SRCDIR}" -isystem "${PYINCDIR}" \
             -isystem "${BOOSTINCDIR}"
PYCXXFLAGS = 

LDFLAGS  = 
exeext   = .out
defext   = .def

AR       = ar
ARFLAGS  = r
RANLIB   = ranlib

LDCONFIG = /sbin/ldconfig

NPD      = --no-print-directory

#########################################################################
#									#
#	           Names Of Various Targets To Build			#
#									#
# These names are associated with the library we plan to build.		#
#									#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)	#
# VERNO       = Shared library major version number                     #
# MINNO       = Shared library minor version number                     #
# RELNO       = Shared library release (or patch) version number        #
# SO_NAME     = Name of shared lib to generate/target.    (libgamma.so)	#
# PY_NAME    = Name of PyGAMMA shared lib. to generate    (pygamma.so) #
#									#
# Note: The shared library name should be libgamma.#.#.# where the 3    #
#       numbers are VERNO, MINNO, and RELNO respectively. For GAMMA we  #
#       are currently on major version 4 and minor version 1 so that it #
#       will have an soname of libgamma.so.4 whereas the library name   #
#       produced in the build will be libgamma.so.4.1. When the library #
#       libgamma.so.4.1 is put into a standard directory (e.g. into     #
#       /usr/lib .... done with make install) then the program ldconfig #
#       will make the symbolic link between this file and the soname.   #
#       That is, libgamma.so.4 -> libgamma.so.4.1. A second link is     #
#       set manually, libgamma.so -> libgamma.so.4 so that ld will find #
#       the right GAMMA library (with soname) to use at link time. Then #
#       if GAMMA is upgraded but not to the point that any previous     #
#       programs are affected, the library may be rebuilt with the same #
#       soname (that which all previously made executable try to link   #
#       to) but change the MINNO for the build. If the GAMMA changes    #
#       will break older programs, then adjust the major version and    #
#       the soname (e.g. libgamma.so.5.0 and libgamma.so.5) for the     #
#       rebuild. Then (after the install to /usr/lib) then switch the   #
#       symbolic link to point to the new soname library:               #
#       libgamma.so -> libgamma.so.5.                                   #
#									#
#########################################################################

LIB_NAME    = libgamma.a

VERNO      = 4
MINNO      = 1
RELNO      = 0
SO_NAME    = libgamma.so
SO_NAMEX   = ${SO_NAME}.${VERNO}
SO_NAMEXX  = ${SO_NAMEX}.${MINNO}
SO_NAMEXXX = ${SO_NAMEXX}.${RELNO}

PY_NAME    = pygamma.so
PY_NAMEX   = ${PY_NAME}.${VERNO}
PY_NAMEXX  = ${PY_NAMEX}.${MINNO}
PY_NAMEXXX = ${PY_NAMEXX}.${RELNO}

#########################################################################
#                                                                       #
#                       Gamma Related Variables                         #
#                                                                       #
#                                                                       #
# These variables are used to specify the GAMMA sources. Exactly what   #
# sources are associated with any one GAMMA module is contained in the  #
# external makefile MakeMods. From these we can construct the names of  #
# module source files and object files. These are directory specific.   #
#                                                                       #
# MakeMods    = File listing all current GAMMA source files.            #
# SRCDIR      = Base directory of GAMMA source codes.                   #
# BINDIR      = Base directory of Irix binaries.                       #
# LIB_SRCS    = All code files to be put into the GAMMA static library.	#
# LIB_OBJS    = All object files to be put in the GAMMA static library.	#
# SO_SRCS     = All code files to be put into the GAMMA shared library.	#
# SO_OBJS     = All object files to be put in the GAMMA shared library.	#
#                                                                       #
# The variable ALLCCFILES should contain all GAMMA source .cc files.    #
# The variable ALLOFILES should contain all GAMMA object .o files.	#
# The source file names will have the source sub-directory as a prefix. #
#     but not the full path relative to this directory. 		# 
#                                                                       #
# The included makefile supplies NO targets or rules of any kind.	#
#                                                                       #
#########################################################################

include ../../make/MakeMods

LIB_SRCS = $(ALLCCFILES)
LIB_OBJS = $(addsuffix .o, $(addprefix $(BINDIR)/, $(ALLFILES)))

SO_SRCS = $(ALLCCFILES)
SO_OBJS = $(addsuffix .soo, $(addprefix $(BINDIR)/, $(ALLFILES)))

PYG_SRCS = $(ALLCCFILES)
PYG_SRCS = 
PYG_OBJS = $(addsuffix .po, $(addprefix $(BINDIR)/, $(ALLFILES)))

GAM_HDRS = $(ALLHFILES)
INS_HDRS = $(addprefix $(HDRINSTALLDIR)/, $(ALLHFILES))

#########################################################################
#									#
#                Build GAMMA Static Library Pattern Rules		#
#									#
# These rules specify how we build object file (*.o) from C++ code	#
# files (*.cc). Gnu make has a built in implicit pattern rule to do	#
# this task:								#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# But that does not suffice for two reasons. First, GAMMA source files	#
# reside in module directories off of the source directory SRCDIR.	#
# Second, we want all the object files to be built in the binaries 	#
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file	#
# ${SRCDIR}/${MODDIR}/*.cc. The main GAMMA  makefile handles this by	#
# recursing through each module directory and letting it decide how to	#
# build itself. Here we will define a rule for each module directory.   #
#									#
#########################################################################

BASICS    = Basics
MATRIX    = Matrix
HSPACE    = HSLib
LEVEL1    = Level1
LSPACE    = LSLib
LEVEL2    = Level2
BLOCH     = Bloch
GAMIO     = GamIO
BWR       = BWRRelax
PULSES    = Pulses
INTRANK2  = IntRank2
FLOQUET   = Floquet
GRADIENTS = Gradients
MULTISYS  = MultiSys
ESRLIB    = ESRLib
DEPREC    = Deprecated
TESTING   = Testing
MODULEDIRS = ${ALLMODDIRS}

#########################################################################
#									#
#                Build GAMMA Static Library Pattern Rules		#
#									#
# These rules specify how we build object file (*.o) from C++ code	#
# files (*.cc). Gnu make has a built in implicit pattern rule to do	#
# this task:								#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# But that does not suffice for two reasons. First, GAMMA source files	#
# reside in module directories off of the source directory SRCDIR.	#
# Second, we want all the object files to be built in the binaries 	#
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file	#
# ${SRCDIR}/${MODDIR}/*.cc. The main GAMMA  makefile handles this by	#
# recursing through each module directory and letting it decide how to	#
# build itself. Here we will define a rule for each module directory.   #
#									#
#########################################################################

${BINDIR}/%.o : ${SRCDIR}/${BASICS}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${MATRIX}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${HSPACE}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${LEVEL1}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${LSPACE}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${LEVEL2}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${BLOCH}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${GAMIO}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${BWR}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${PULSES}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${INTRANK2}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${FLOQUET}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${GRADIENTS}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${MULTISYS}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${ESRLIB}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${DEPREC}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

${BINDIR}/%.o : ${SRCDIR}/${TESTING}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

#########################################################################
#									#
#                Build GAMMA Shared Library Pattern Rules		#
#									#
# These rules specify how we build object file (*.soo) from C++ code	#
# files (*.cc). Gnu make has a built in implicit pattern rule to do	#
# this task:								#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# But that does not suffice for a few reasons. First, GAMMA sources	#
# reside in module directories off of the source directory SRCDIR.	#
# Second, we want all the object files to be built in the binaries 	#
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file	#
# ${SRCDIR}/${MODDIR}/*.cc. Third, we want to clearly distinguish the   #
# object files for the shared library from those that are static. For   #
# that we will use the suffix .soo rather than .o. Here we will define  #
# define a rule for each module directory.  	                        #
#									#
#########################################################################

${BINDIR}/%.soo : ${SRCDIR}/${BASICS}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${MATRIX}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${HSPACE}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${LEVEL1}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${LSPACE}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${LEVEL2}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${BLOCH}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${GAMIO}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${BWR}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${PULSES}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${INTRANK2}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${FLOQUET}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${GRADIENTS}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${MULTISYS}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${ESRLIB}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${DEPREC}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

${BINDIR}/%.soo : ${SRCDIR}/${TESTING}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

#########################################################################
#									#
#                Build PyGAMMA Shared Library Pattern Rules		#
#									#
# These rules specify how we build object file (*.po) from C++ code	#
# files (*.cc). Gnu make has a built in implicit pattern rule to do	#
# this task:								#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# But that does not suffice for a few reasons. First, GAMMA sources	#
# reside in module directories off of the source directory SRCDIR.	#
# Second, we want all the object files to be built in the binaries 	#
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file	#
# ${SRCDIR}/${MODDIR}/*.cc. Third, we want to clearly distinguish the   #
# object files for the PyGAMMA shared library from those that are 	#
# for the static and shared GAMMA libraries. For that we will use the	#
# suffix .po rather than either .o (static) or .soo (shared). Here we	#
# will define define a rule for each module directory.			#
#									#
#########################################################################

${BINDIR}/%.po : ${SRCDIR}/${BASICS}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${MATRIX}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${HSPACE}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${LEVEL1}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${LSPACE}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${LEVEL2}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${BLOCH}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${GAMIO}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${BWR}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${PULSES}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${INTRANK2}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${FLOQUET}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${GRADIENTS}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${MULTISYS}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${ESRLIB}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${DEPREC}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

${BINDIR}/%.po : ${SRCDIR}/${TESTING}/%.cc
	$(CXX) -c $(PYCPPFLAGS) $(PYCXXFLAGS) $< -o $@

#########################################################################
#									#
#                      Copying GAMMA Headers Rules		        #
#									#
# These rules specify how to update the GAMMA header files in the	#
# installation directory from those same header files in a source	#
# directory. If the headers are to be kept in the source directory then	#
# these targets should never be used.					#
#									#
#########################################################################

${HDRINSTALLDIR}/%.h : ${SRCDIR}/%.h
	cp -f $< $@

#########################################################################
#									#
#                              Main Target				#
#									#
# This target produce the static library.				#
#									#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)	#
#									#
#########################################################################

all: ihatewindows $(BINDIR)/$(SO_NAME)
lib: ihatewindows $(BINDIR)/$(LIB_NAME)
so:  ihatewindows $(BINDIR)/$(SO_NAME)
pyg: ihatewindows $(BINDIR)/$(PY_NAME)

${LIB_NAME}: ${BINDIR}/${LIB_NAME}
${SO_NAME}:  ${BINDIR}/${SO_NAME}
${PY_NAME}:  ${BINDIR}/${PY_NAME}

#########################################################################
#									#
#                       Library Related Variables			#
#									#
# These variables are used exclusively when building the static lib. 	#
#									#
# LIB_SRCS    = All code files to be put into the library.		#
# LIB_OBJS    = All object files to be put into the library.		#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)	#
# LIB_OBJS    = Name of object files used in library.			#
#									#
# These variables are used exclusively when building a shared library.	#
#									#
# SO_LDFLAGS = Flags used in .so build.                      (-shared)  #
# SO_LDLIBS  = Any libraries the shared lib. to be built depends upon.	#
# SO_SRCS    = All code files to be put into the shared library. 	#
# SO_OBJS    = All object files to be put into the shared lib. Note 	#
#              they are NOT the same as LIB_OBJ since we use special    #
#              compiler flags to generate them over the static library 	#
#									#
# These variables are used exclusively to build the PyGAMMA shared lib.	#
#									#
# PYG_SRCS    = All code files to be put into the PyGAMMA library.	#
# PYG_OBJS    = All object files to be put into the PYGAMMA library.	#
#               These will have special names because they are built    #
#               with special flags, in particular _PYGAMMA being set.   #
#									#
# These variables are used generally. 					#
#									#
# BINDIR      = Where we will ultimately place or binaries. This is	#
#               set to replace a CygWin build.				#
# NPD         = Turns of directory name printing when recursing through #
#               other directories.                 			#
#									#
#########################################################################

SO_LDFLAGS = -shared
SO_LDLIBS  =

PY_LDFLAGS = -shared
PY_LDLIBS  =

#########################################################################
#									#
#                      Build The GAMMA Static Library 			#
#									#
# LIB_SRCS    = All code files to be put into the library.		#
# LIB_OBJS    = All object files to be put into the library.		#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)	#
# LIB_OBJS    = Name of object files used in library.			#
#									#
# The static library build depends on the object files in LIB_OBJS. If  #
# or when these are up to date then the target uses ar to form the 	#
# library from the object files and then ranlib to adjust the library.	#
#									#
# The LIB_OBJS variable is set from LIB_SRCS earlier in this file.	#
# These are apparently implicitly dependent upon the source codes in	#
# LIB_SRCS (i.e. the .cc file with the same base name as the .o file)   #
# & have an implicit pattern rule as to how the .cc files are compiled	#
# into .o files. This pattern rule, as specified in the documentation	#
# for GNU make, is							#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# This implicit rule can be replaced by defining a new pattern rule	#
# with the same target and prerequisites, but different commands. 	#
# If there are no commands following the rule, the rule is cancelled.	#
# When the new rule is defined, the built-in one is replaced. The new	#
# rule's position in the sequence of implicit rules is determined by 	#
# where you write the new rule and affects how they are chained.	#
#									#
#########################################################################

${BINDIR}/$(LIB_NAME): ${BINDIR} ${LIB_OBJS}
	@echo
	@echo "Making Static Library $(LIB_NAME) From Object Files"
	@echo
	${AR} ${ARFLAGS} ${BINDIR}/$(LIB_NAME) $(LIB_OBJS)
	@echo
	@echo "Adjusting Static Library $(LIB_NAME) For Random Access"
	@echo
	${RANLIB} ${BINDIR}/$(LIB_NAME)

#########################################################################
#                                                                       #
#                       Build The GAMMA Shared Library 			#
#                                                                       #
# SO_NAME    = Name of shared library to be generated.   (libgamma.so)	#
# SO_OBJS    = Name of object files used in shared lib.			#
# SO_LDFLAGS = Flags used in shared library linking.         (-shared) 	#
# SO_LDLIBS  = Libraries GAMMA shared library depends upon.             #
#                                                                       #
# The shared library build depends on the object files in SO_OBJS. If   #
# or when # these are up to date then the target uses g++ to form the	#
# library from the object files using appropriate linking commands.	#
#									#
# The SO_OBJS variable is set from SO_SRCS earlier in this file.	#
# These are NOT the same as LIB_OBJS used for the static library build 	#
# because different flags are used when the source files are compiled.  #
# As with LIB_OBJS, the objects files are implicitly dependent upon the #
# source codes in SO_SRCS (i.e. the .cc file with the same base name as #
# the .soo file) & have an implicit pattern rule as to how the .cc 	#
# files are compiled into .soo files. This pattern rule, as specified	#
# in the documentation for GNU make, is					#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#									#
# Since we switched from .o to .soo and use particular sub-directories  #
# we have made our own rules to handle the compilation of sources.	#
#									#
#########################################################################

${SO_NAME}: ${BINDIR}/${SO_NAME}

${BINDIR}/${SO_NAME}: ${BINDIR}/${SO_NAMEXXX}
	@rm -f ${BINDIR}/${SO_NAME}
	@cp -f ${BINDIR}/${SO_NAMEXXX} ${BINDIR}/${SO_NAME}

$(BINDIR)/$(SO_NAMEXXX): $(SO_OBJS)
	@echo
	@echo "Making Shared Library $(SO_NAME) From Object Files"
	@echo
	@g++ ${SO_LDFLAGS} -Wl,-soname,${SO_NAMEX} -o ${BINDIR}/${SO_NAMEXXX} $(SO_OBJS) $(SO_LDLIBS)

#########################################################################
#                                                                       #
#                     Build The PyGAMMA Shared Library 			#
#                                                                       #
# PY_NAME    = Name of library to be generated/targeted.  (pygamma.so)	#
# SO_OBJS    = Name of object files used in shared library. 		#
# SO_LDFLAGS = Flags used in shared library build.          (-shared)	#
# SO_LDLIBS  = Libraries shared library depends upon.			#
#                                                                       #
# The PyGAMMA build depends on the object files in PYG_OBJS. If or when	#
# these are up to date then the target uses g++ to form the library 	#
# from the object files using g++ with appropriate linking commands.	#
#									#
# The PYG_OBJS variable is set from PYG_SRCS earlier in this file.	#
# These are NOT one and the same as LIB_OBJS nor SO_OBJS. This is 	#
# because the sources are compiled into object files with the variable	#
# _PYGAMMA defined. This cause the build to include addtional sources	#
# and headers required for PyGAMMA. The actual source code files from	#
# which PYG_OBJS are made, PYG_SRCS, is one and the same as LIB_SRCS &	#
# SO_SRCS, but the _PYGAMMA variable forces the preprocessor to use	#
# code commented out in the latter two.					#
#									#
# Normally objects files are implicitly dependent upon the source codes #
# That is, the files in SO_OBJS depend upon SO_SRCS (i.e. the .cc 	#
# file with the same base name as the .o file) & have an implicit 	#
# pattern rule as to how the .cc files are compiled into .o files. 	#
# But since PyGAMMA demands are different, the files in PYG_OBJS are	#
# set to end with .po rather than .o so that the implicit pattern rule 	#
# is not invoked. Rather we have earlier defined our own pattern rule	#
# to handle the compilation of .cc to .po. The default is		#
#									#
# %.o : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@			#
#                                                                       #
# and the own we will invoke in the following target is			#
#                                                                       #
# %.po : %.cc								#
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(PYGFLAGS) $< -o $@		#
#                                                                       #
#########################################################################

PYGFLAGS   = -D_PYGAMMA=1 -I${BOOSTINCDIR} -I${PYINCDIR}
PYG_LDFLAGS = -L${BOOSTLIBDIR} -L${PYLIBDIR} -L${PYLIB2DIR} -lboost_python
PYGLDLIBS = 
PYINCDIR    = /usr/include/python2.2
PYLIBDIR    = /usr/lib/python2.2
PYLIB2DIR   = /usr/lib/python2.2/config
BOOSTINCDIR = "/usr/local/src/boost_1_29_0"
BOOSTLIBDIR = "/usr/local/src/boost_1_29_0/libs/python/build/bin/libboost_python.so/gcc/release/inlining-on/runtime-link-dynamic/shared-linkable-true"

%.po : %.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(PYGFLAGS) $< -o $@

PyGAMMAChk:
	@echo
	@echo "Making PyGAMMA Shared Library $(PY_NAME) From Pythonized Object Files"
	@echo
	@if (test -d ${PYINCDIR}) \
	then echo Good. The Irix Python Includes Directory Exists. ${PYINCDIR}; \
	else echo Cannot Find The Irix Python Includes Directory! ${PYINCDIR}; \
	     echo Python Must Be Installed On The System For PyGAMMA To Work.; \
	     echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
	     echo; \
	     false; \
	fi
	@if (test -d ${PYLIBDIR}) \
	then echo Good. The Irix Python Library Directory Exists. ${PYLIBDIR}; \
	else echo Cannot Find The Irix Python Library Directory! ${PYLIBDIR}; \
	     echo Python Must Be Installed On The System For PyGAMMA To Work.; \
	     echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
	     echo; \
	     false; \
	fi
	@if (test -d ${BOOSTINCDIR}) \
	then echo Good. The Irix Boost Includes Directory Exists. ${BOOSTINCDIR}; \
	else echo Cannot Find The Irix Boost Includes Directory! ${BOOSTINCDIR}; \
	     echo We Must Know Where Boost Is Installed On The System.; \
	     echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
	     echo; \
	     false; \
	fi
	@if (test -d ${BOOSTLIBDIR}) \
	then echo Good. The Irix Boost Library Directory Exists. ${BOOSTLIBDIR}; \
	else echo Cannot Find The Irix Boost Library Directory! ${BOOSTLIBDIR}; \
	     echo The Boost.Python Library Must Be Available On The System.; \
	     echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
	     echo; \
	     false; \
	fi
	@echo "Compiling GAMMA Source Into PyGAMMA Object Code"
	@echo


${BINDIR}/$(PY_NAME): PyGAMMAChk $(PYG_OBJS)
	@echo
	@echo "Making PyGAMMA Shared $(PY_NAME) From Pythonized Object Files"
	@echo
	g++ ${PY_LDFLAGS} -Wl,-soname,${PY_NAMEX} -o ${BINDIR}/${PY_NAMEXXX} $(PYG_OBJS) $(PY_LDLIBS)
#	g++ -shared -Wl,--out-implib=$(PYG_EXP_LIB) \
#	-o $(PY_NAME) $(PYG_OBJS) $(PYG_LDFLAGS) $(PYG_LDLIBS)


#########################################################################
#                                                                       #
#                       Build The PyGAMMA Shared Library		#
#                                                                       #
# PY_NAME    = Name of DLL to be generated/targeted.    (pygamma.dll)	#
# SO_EXP_LIB = Name of exports library generated.    (libgamma.dll.a)   #
# SO_OBJS    = Name of object files used in DLL.                        #
# SO_LDFLAGS = Flags used in DLL build.                     (-shared)	#
# SO_LDLIBS  = Libraries DLL depends upon.                              #
#                                                                       #
# The PyGAMMA build depends on the object files in PYG_OBJS. If or when	#
# these are up to date then the target uses g++ to form the DLL from	#
# the object files using g++ with appropriate linking commands.		#
#									#
# The PYG_OBJS variable is set from PYG_SRCS earlier in this file.	#
# These are NOT one and the same as LIB_OBJS nor SO_OBJS. This is 	#
# because the sources are compiled into object files with the variable	#
# _PYGAMMA defined. This cause the build to include addtional sources	#
# and headers required for PyGAMMA. The actual source code files from	#


#########################################################################
#									#
#               Insure Needed Irix Binary Directory Exists		#
#									#
#########################################################################

${BINDIR}: force
	@if (test ! -d ./$(BINDIR)) \
        then \
          echo "First Constructing Irix Binaries Directory For GAMMA"; \
          echo "Making Directory ./$(BINDIR)"; \
          mkdir $(BINDIR); \
          chmod ug+w $(BINDIR); \
	fi

force:

#########################################################################
#									#
#                     Build And Run The Demos				#
#									#
# The purpose of this target is to run the GAMMA demo program(s). The   #
# demo programs painstakingly walk the user through each GAMMA module   #
# so that they can get a feel of what is available.                     #
#									#
# The program will be named DemoGAMMA and should be found in the GAMMA  #
# demo directory in the modules sub-directory. The target should always	#
# run the demo program. It will insure that the GAMMA library  is  	#
# up to date, that the GAMMA library exists in the PATH, and that the   #
# demo executable is up to date.					#
#									#
# $(exeext)   = Executable extension on system.                  (.exe) #
# CXX         = C++ compiler name                                 (c++)	#
# CXXFLAGS    = C++ compiler flags                             $(DEBUG)	#
# LDFLAGS     = Linker flags (automatically used)			#
#									#
# DEMO_DIR    = Directory where demo program sources are		#
# DEMO_NAME   = Base name of demo program (without .cc, .o, .exe,...)	# 
# DEMO_PGM    = Name of produced demo executable			#
# DEMO_SRC    = Full name of demo program source file			#
# DEMO_OBJ    = Full name of demo program object file			#
# DEMO_FLAGS  = Flags to use when compiling the demo program		#
# DEMO_LD     = Command to link to shared library during runtime	#
#									#
# -o $@       : Sets output executable name to match the name of 	#
#               the target (TestGAMMA.exe)				#
# -L          : Look in local directory for libraries			#
# -lgamma    : Link to library lgamma					#
#									#
#########################################################################

DEMO_DIR     = ../../demo/modules
DEMO_NAME    = DemoGAMMA
DEMO_PGM     = ${DEMO_NAME}${exeext}
DEMO_SRC     = $(DEMO_DIR)/${DEMO_NAME}.cc
DEMO_OBJ     = ./${DEMO_NAME}.o
DEMO_FLAGS   = -D_GAMMADEMO=1
DEMO_LD      = /lib/ld-linux.so.2 --library-path

DEMO_OBJ_S   = ./${DEMO_NAME}.static.o
DEMO_PGM_S   = ${DEMO_NAME}.static${exeext}
DEMO_FLAGS_S = -D_GAMMADEMO=1 -DGSTATIC=1

# --------------------- Demo Targets With Default Library ---------------------
#            (Use Shared Library If Present, If Not Use Static Library)

%.o : ${DEMO_DIR}/%.cc
	$(CXX) -c $(SOCPPFLAGS) $(SOCXXFLAGS) $< -o $@

demo:	
	@${MAKE} $(NPD) ${DEMO_PGM}
	@strip ./${DEMO_PGM}
	@${DEMO_LD} ${BINDIR} ./${DEMO_PGM} $(DEMO_DIR)

${DEMO_PGM}: ${DEMO_OBJ}
	$(CXX) -o $@ ${DEMO_OBJ} ${DEMO_FLAGS} $(SOCPPFLAGS) $(CXXFLAGS) \
        $(LDFLAGS) -L${BINDIR} -lgamma
#	$(CXX) -o $@ ${DEMO_OBJ} ${DEMO_FLAGS} $(CPPFLAGS) $(CXXFLAGS) \
#        $(LDFLAGS) -L${BINDIR} -lgamma

# --------------------- Demo Targets With Static Library ---------------------

%.static.o : ${DEMO_DIR}/%.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@

demostatic:	
	@${MAKE} $(NPD) ${DEMO_PGM_S}
	@strip ./${DEMO_PGM_S}
	./${DEMO_PGM_S} $(DEMO_DIR)

${DEMO_PGM_S}: ${DEMO_OBJ_S}
	$(CXX) -g -o $@ ${DEMO_OBJ_S} ${DEMO_FLAGS_S} -Wl,-static \
        $(LIBCPPFLAGS) $(LIBCXXFLAGS) $(LDFLAGS) -L${BINDIR} -static -lgamma

#########################################################################
#									#
#                     Build And Run The Tests				#
#									#
# The purpose of this target is to run the GAMMA test program(s). The   #
# test programs painstakingly run through each GAMMA module and do some	#
# rather extensive checking for validity.				#
#									#
# The program will be named TestGAMMA and should be found in the GAMMA  #
# test directory. This target should always run the test program. It	#
# will insure that the GAMMA library is up to date, that the 		#
# GAMMA library exists in the PATH, and that the test executable is up 	#
# to date.								#
#									#
# $(exeext)   = Executable extension on system.                  (.exe) #
# CXX         = C++ compiler name                                 (c++)	#
# CXXFLAGS    = C++ compiler flags                             $(DEBUG)	#
# LDFLAGS     = Linker flags						#
#									#
# -o $@       : Sets output executable name to match the name of 	#
#               the target (TestGAMMA.exe)				#
# -L          : Look in local directory for libraries			#
# -lgamma    : Link to library lgamma					#
#									#
#########################################################################

TESTDIR      = ../../test
TEST_PGM     = $(TESTDIR)/TestGAMMA${exeext}
TEST_SRC     = $(TESTDIR)/TestGAMMA.cc
TEST_OBJ     = $(TESTDIR)/TestGAMMA.o

test:	
	@${MAKE} $(NPD) ${TEST_PGM}
	${TEST_PGM}

${TEST_PGM}: ${TEST_OBJ}
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) ${TEST_OBJ} -L${BINDIR}/ -lgamma 

#########################################################################
#									#
#                            TestGAMMA.o 				#
#									#
# This is the target for building an object file from the test file.	#
#									#
# CXX         = C++ compiler name                                 (c++)	#
# CPPFLAGS    = C++ compiler flags                        (-I../../src)	#
# CXXFLAGS    = C++ compiler flags                             $(DEBUG)	#
#									#
#########################################################################

TestGAMMA.o: %o: %cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

#########################################################################
#									#
#                           Installation 				#
#									#
# This is the typical Gnuish install target with some added GAMMA 	#
# features. There are 3 items of concern here. 1.) The GAMMA script,	#
# 2.) The GAMMA shared library and 3.) The GAMMA headers. Here are 	#
# details regarding each.						#
#									#
# 1.) The GAMMA script (gamma)						#
# ============================						#
# The GAMMA script (gamma) is that which is run when programs linking	#
# to GAMMA are compiled. This script is tailored for a particular	#
# version and installation, that is, it knows which GAMMA version it    #
# is associated with & where the library + headers for that version are	#
# located. For example, the version may be 4.1.0 & compiled for Irix.	#
# The library headers are either placed in a Irix system directory	#
# (e.g. /usr/include/gamma-4.1.0) or they are left in a GAMMA directory	#
# (e.g. /E/gamma/gamma-4.1.0/src). Similarly the library itself is put  #
# in either the Irix system directory (e.g. /usr/lib) or left in a	#
# GAMMA directory (e.g. /E/gamma/gamma-4.1.0/i686-pc-linux-gnu). Since 	#
# shared obeject libraries are preferable on Irix systems, the system  #
# directories are best because then their location is standard. If, for #
# reasons unknown, a static library is preferred then the either the    #
# system or GAMMA directory setup can be used.  The only reason to have #
# the GAMMA directory settings is if the user shares disks between      #
# different systems and wishes them all to have similar locations.      #
#									#
# When using the Gnu configuration process all of this information is	#
# set into the GAMMA script automatically. Since we do not run 		#
# ./configure for this primal Makefile build, the GAMMA script must be	#
# configured directly herein. All that entails is setting the variable	#
# GAMMA_PATH with the script. This is done using sed on the precursor	#
# file gamma.in. When "make install" is run the target will convert	#
# gamma.in into gamma and set the proper directory information therein. #
#									#
# In addition, the GAMMA script must be placed into a directory that	#
# is commonly known to most users. So, gamma is copied to ${INSTALLDIR}	#
# which is typically /usr/local/bin (or maybe just /usr/bin). This make #
# currently defaults to /usr/local/bin.                                 #
#									#
# 2.) The GAMMA shared library (libgamma.so)				#
# ==========================================				#
# When building GAMMA based programs using the GAMMA script gamma, the	#
# programs will be linked to the GAMMA library. This all works quite	#
# simply if linking is done to the static library, libgamma.a, because	#
# the GAMMA script tell the compiler to look in the Irix binaries	#
# directory for the GAMMA library. Once the program has been compiled	#
# into an executable it contains the library functionality (at the	#
# expense of large executable file size) and no longer needs the static #
# library. Hence the executable program can be moved anywhere on the	#
# system and run without troubles. They have the library embedded in	#
# them.	All that is required for all this to work is that the gamma     #
# script (or the compilation command) used to build GAMMA based 	#
# programs know where the static library is located. This can be either #
# a GAMMA directory (e.g /E/gamma/gamma-4.1.0/i686-pc-linux-gnu) or a 	#
# Irix system directory (e.g. /usr/lib)                                #
#									#
# The same is NOT true when GAMMA based programs link to the shared	#
# library, libgamma.so. THIS IS THE DEFAULT LINKAGE IN THIS GAMMA	#
# SCRIPT. In this instance the executable program will not contain	#
# the functions of the library (this keeps the executable file size	#
# small). Rather it just keeps a record that it needs a library with a  #
# particular name (the library soname). When the executable is run it   #
# will attempt to use the library having the name (soname) specified    #
# when the executable was built and linked. As a consequence, the       #
# system must know where to find the shared library when the executable #
# is run. Since the executable may be moved around on the system, one   #
# must tell the system where the library exists.	 		#
#									#
# To accomplish this, libgamma.so needs to be put in a standard 	#
# directory where shared libraries are kept. For Irix this is usually	#
# /usr/lib (directory /usr/local/lib AFAIK is not preferred here.)	#
# Furthermore, libgamma.so should simply exist as a symbolic link to	#
# the library that has the soname that the executable needs. Even more  #
# complicated, the true library naming should use GAMMA version	        #
# numbering in it (libgamma.so.#.#.#, the last number optional). It is  #
# this latter file that is built when GAMMA itself is compiled. So, the #
# actual physical library file will be /usr/lib/libgamma.so.#.#(.#),    #
# the file with the soname will be /usr/lib/libgamma.so.# and exist as  #
# a symbolic link to the physical library, and the basic library        #
# /usr/lib/libgamma.so will be a symbolic link to the library having    #
# the soname name, /usr/lib/libgamma.so.#. Whew. In any event, the	#
# GAMMA directory (e.g /E/gamma/gamma-4.1.0/i686-pc-linux-gnu) is NOT	#
# used in this case to keep the shared object libraries on the system,	#
# although they may be built in such a directory.			#
#									#
# 3.) The GAMMA headers (*.h)						#
# ==========================================				#
# When building GAMMA based programs using the GAMMA script gamma, the	#
# programs will include the GAMMA source headers. Whether linking to	#
# the static or shared library, the headers must exist in a known	#
# location. On some systems this can be the GAMMA source directory	#
# (e.g /E/gamma/gamma-4.1.0/src) or it can be a Irix system directory	#
# (e.g. /usr/include/gamma-4.1.0). It is the latter directory that is	#
# used in typical Irix system GAMMA binary installations.		#
#									#
# To summarize, this target (install) does the following:		#
#									#
# a.) Determines the GAMMA version directory (this is GAMMA_PATH)       #
# b.) Converts gamma.in into gamma where GAMMA_PATH is set properly.    #
# c.) Copies gamma to INSTALLDIR (e.g. /usr/local/bin).			#
# d.) Copies the GAMMA shared library to LIBINSTALLDIR (e.g. /usr/lib)  #
#     This is the full library name, libgamma.so.#.#.#                  #
# e.) Runs LDCONFIG (/sbin/ldconfig) to set up a symbolic link between  #
#     the built library & a file with the soname. That is (in lib dir)  #
#                libgamma.so.# --> libgamma.so.#.#.#                    #
# f.) Makes a final symbolic link between the common library name &     #
#     the soname library. Again this is done in LIBINSTALLDIR           # 
#                    libgamma.so --> libgamma.so.#                      #
#									#
#########################################################################

GSCRIPT       = gamma
GSCRIPTIN     = gamma.in
CURRENTDIR    = ${shell pwd}
#GAMMA_PATH    = ${shell cd ../..; pwd; cd primal/Irix}
GAMMA_PATH    = ${HDRINSTALLDIR}
SEDSUB        = 's|CONFIGUREDGAMMAPATH|${GAMMA_PATH}|g'

#################################################################################
#										#
# 	                     Targets For The GAMMA Headers			#
#										#
#################################################################################

installhdrs: force
	@if (test -d ${HDRINSTALLDIR}) \
	then echo The Irix System GAMMA Headers Directory Exists. ${HDRINSTALLDIR}; \
	else echo Creating GAMMA Headers Directory On Irix System. ${HDRINSTALLDIR}; \
	     echo * mkdir ${HDRINSTALLDIR}; \
	     mkdir ${HDRINSTALLDIR}; \
	     for i in ${MODULEDIRS}; do \
                echo  "* Making Subdirectory $$i"; \
                mkdir ${HDRINSTALLDIR}/$$i; \
	        done; \
	fi
	@${MAKE} ${NPD} ${HDRINSTALLDIR}/gamma.h
	@${MAKE} ${NPD} ${HDRINSTALLDIR}/GamGen.h
	@${MAKE} ${NPD} ${INS_HDRS}

#################################################################################
#										#
#                           Targets For The GAMMA Script			#
#										#
# gamma:		  Construct gamma script from gamma.in			#
# ${BININSTALLDIR}/gamma: Copy local gamma script to script in BININSTALLDIR	#
# script:		  Same as gamma						#
# installscript:	  Same as ${BININSTALLDIR}/gamma			#
#										#
#################################################################################

gamma: gamma.in
	@echo Creating An Appropriate GAMMA Script From gamma.in
	@sed ${SEDSUB} ${GSCRIPTIN}>${GSCRIPT}

${BININSTALLDIR}/gamma: gamma
	@echo Copying The GAMMA Script To The Bin Directory ${BININSTALLDIR}
	@cp -f ./${GSCRIPT} ${BININSTALLDIR}

script: gamma
installscript: ${BININSTALLDIR}/gamma

#################################################################################
#										#
# 	                     Targets For The GAMMA Library			#
#										#
#################################################################################

${LIBINSTALLDIR}/${SO_NAMEXXX}: ${BINDIR}/${SO_NAMEXXX}
	@echo Copying The GAMMA Shared Object Library To The Lib Directory ${LIBINSTALLDIR}
	@cp -f ${BINDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}

installsolib: force
	@echo " * Copying Shared Library To ${LIBINSTALLDIR}"
	@cp -f ${BINDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}
	@echo " * Setting Link For libgamma.so"
	@echo " * Running ldconfig To Update Cache Of Known Shared Libraries"
	@echo " *         (This May Take A Couple Of Seconds)"
	@${LDCONFIG} -n ${LIBINSTALLDIR}
	@echo " * Adding Link For GAMMA Base Library Name"
	@ln -sf ${LIBINSTALLDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}/${SO_NAME}
	@echo

#################################################################################
#										#
# 	                    Targets For The GAMMA Installation			#
#										#
#################################################################################

install: force
	@echo
	@echo "           Installing Irix GAMMA"
	@echo
	@echo " * GAMMA Script Installation Directory Is ${BININSTALLDIR}"
	@echo " * GAMMA Binary Library Installation Directory Is ${LIBINSTALLDIR}"
	@echo " * GAMMA Headers Installation Directory Is ${HDRINSTALLDIR}"
	@${MAKE} ${NPD} installscript
	@${MAKE} ${NPD} installhdrs
	@${MAKE} ${NPD} installsolib
	@echo " * Finished. Compile Command gamma Should Now Work"
	@echo
#	@echo " * Setting GAMMA Script To Know GAMMA Path"
#	@sed ${SEDSUB} ${GSCRIPTIN}>${GSCRIPT}
#	@echo " * Copying GAMMA Script ${GSCRIPT} To Installation Directory"
#	@cp -f ./${GSCRIPT} ${BININSTALLDIR}
#	@echo " * GAMMA Library Installation Directory Is ${LIBINSTALLDIR}"
#	@echo " * Copying Shared Library To ${LIBINSTALLDIR}"
#	@cp -f ${BINDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}
#	@echo " * Setting Link For libgamma.so"
#	@echo " * Running ldconfig To Update Cache Of Known Shared Libraries"
#	@echo " *         (This May Take A Couple Of Seconds)"
#	@${LDCONFIG} -n ${LIBINSTALLDIR}
#	@echo " * Adding Link For GAMMA Base Library Name"
#	@ln -sf ${LIBINSTALLDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}/${SO_NAME}

#########################################################################
#									#
#                                Clean 					#
#									#
# This is the typical Gnuish clean target. It will remove any libraries #
# (both dll and .a), any definition files, all object files, and the    #
# build of the test program(s)                                          #
#									#
#########################################################################

clean:
	rm -f ${LIB_OBJS}
	rm -f ${SO_OBJS}
	@rm -f $(PYG_OBJS)
	@rm -f $(TEST_OBJ)
	@rm -f *.asc
	@rm -f *.gnu
	@rm -f $(DEMO_OBJ)
	@rm -f $(DEMO_PGM)
	@rm -f ${BINDIR}/${SO_NAMEXXX}

strip:
	@strip ${BINDIR}/${LIB_NAME}
	@strip ${BINDIR}/${SO_NAME}
	@strip ${LIBINSTALLDIR}/${SO_NAMEXXX}

testclean:
	@rm -f $(TEST_PGM)
	@rm -f $(TEST_OBJ)

democlean:
	@rm -f $(DEMO_OBJ)
	@rm -f $(DEMO_PGM)
	@rm -f $(DEMO_OBJ_S)
	@rm -f $(DEMO_PGM_S)
	@rm -f *.asc
	@rm -f *.gnu
	@rm -f *.mif

distclean:
	@rm -f $(LIB_OBJS)
	@rm -f ${LIB_NAME}
	@rm -f $(DEMO_OBJ)
	@rm -f $(DEMO_PGM)
	@rm -f $(TEST_OBJ)
	@rm -f $(TEST_PGM)

dllclean:
	@rm -f ./${BINDIR}/*.dll
	@rm -f ./${BINDIR}/*.dll.*

#################################################################################
#                                                                               #
#                              GAMMA Distributions                              #
#                                                                               #
# What follows has nothing to do with any builds of GAMMA. This stuff has been  #
# included in this Makefile only so that GAMMA distributions will include the   #
# distributed files in this directory. Do not worry about this for any builds   #
# and or runs of GAMMA programs.                                                #
#                                                                               #
#################################################################################

THISDIR       = Irix
PRIMALPLAT    = "using Irix and the GCC compiler"
PRIMALMAKEDIR = ../make
MAINMAKEDIR   = ../../make
SUBDIRS       =
HDRFILES      =
CCFILES       =
HTMLFILES     = index.html
IMGFILES      =
INCFILES      = Makefile gamma.in
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

# When Irix and Windows Share Disk Partitions (FAT32) Windows Can Wreck 
# Some Of The GAMMA Source Code Filenames. This Target Is Run To Fix Them.
# Seems To Only Occur On Names That Have All Capitol Letters In Them!
# Windows Then Converts All Letters To Lower Case For Some Unknown Reason....

ihatewindows: force
	@if (test -f ../../src/GamIO/ml5af.cc) \
	then mv ../../src/GamIO/ml5af.cc x; \
	     mv x ../../src/GamIO/ML5AF.cc; \
	fi
	@if (test -f ../../src/GamIO/ml5af.h) \
	then mv ../../src/GamIO/ml5af.h x; \
	     mv x ../../src/GamIO/ML5AF.h; \
	fi

	@if (test -f ../../src/GamIO/ml5an.cc) \
	then mv ../../src/GamIO/ml5an.cc x; \
	     mv x ../../src/GamIO/ML5AN.cc; \
	fi
	@if (test -f ../../src/GamIO/ml5an.h) \
	then mv ../../src/GamIO/ml5an.h x; \
	     mv x ../../src/GamIO/ML5AN.h; \
	fi

	@if (test -f ../../src/GamIO/ml5da.cc) \
	then mv ../../src/GamIO/ml5da.cc x; \
	     mv x ../../src/GamIO/ML5DA.cc; \
	fi
	@if (test -f ../../src/GamIO/ml5da.h) \
	then mv ../../src/GamIO/ml5da.h x; \
	     mv x ../../src/GamIO/ML5DA.h; \
	fi

	@if (test -f ../../src/ESRLib/esrif.h) \
	then mv ../../src/ESRLib/esrif.h x; \
	     mv x ../../src/ESRLib/ESRIF.h; \
	fi

force:
