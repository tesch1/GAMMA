#########################################################################
#
#          OS X GAMMA Makefile for the (Py)GAMMA Library
#
# This builds GAMMA and PyGAMMA. It assumes that one is using the GCC C++
# compiler. As for PyGAMMA, one must have Python available.
#
# ---------------------------------------------------------------------
#
#                             Quick Info
#
#  1. Type "make" to build GAMMA static library.
#  2. Type "make demo" to compile and run the GAMMA demo program(s).
#  3. Type "make test" to compile and run the GAMMA test program(s).
#  4. Type "make clean" to remove all object files.
#  5. Type "make distclean" to remove all object files libraries, exes.
#  6. The sources are assumed in SRCDIR
#  7. The object are be produced in BINDIR
#  8. The lib files are produced in BINDIR
#  9. Any executable files (test, demo) are produced in BINDIR.
# 10. The important static library file is libgamma.a
# 11. The important DLL library files are gamma.dll and libgamma.dll.a
# 12. The important PyGMAMA DLL library file is pygamma.dll.
# 13. Produces the following: a.) libgamma.a - The GAMMA static library
#			      b.) gamma.dll  - The GAMMA DLL
#			      c.) libgamma.dll.a - GAMMA imports lib.
#                             e.) DemoGAMMA.exe - The demo program
#                             f.) TestGAMMA.exe - The test program
#
# ---------------------------------------------------------------------
#
#                                 Notes
#
# This is NOT a standalone makefile. It includes an additional file
# ../../make/MakeMods which is part of standard GAMMA. This latter file
# defines which files are part of the GAMMA source codes. Changes in
# MakeMods will evoke changes in the build herein.
#
# all:
# make all: These both run the default target all (first target). It
#           will compile all source codes in GAMMA as defined in file
#           MakeMods into object files. It will then take the object
#           files and convert them into a static library named
#           libgamma.a. These same object files will then be combined
#           into a dynamic library (DLL) with its assocatied imports
#           library, gamma.dll and libgamma.dll.a respectively. If we
#           are able to find Python and Boost.Python, then the PyGAMMA
#           DLL is also built, pygamma.dll. All libraries and object
#           files will be made in the directory specified by BINDIR.
#
# make install: This will convert the file gamma.in into the working
#               script gamma and move it into a system file so that it
#               is accessible by all users. Additionally it will move
#               the shared library for GAMMA into a system directory
#		place appropriate soft links so that it is generally
#               workable. Lastly, if PyGAMMA has been built, its
#               shared library pygamma.so will be moved into a Python
#               directory.
#
# make clean: This will delete all object files from any earlier build.
#             It is important to run make clean since the object files
#             can use lots of disk space as well as interfere with
#             other GAMMA builds (not part of this Makefile)
#
# make demo : This will build and run a set of programs that demo the
#             the modules provided with GAMMA.
#
# make test: This will build and run a set of programs that test the
#             the modules provided with GAMMA.
#
#########################################################################

#########################################################################
#
#                Semi-Standard Gnuish Makefile Variables
#
# CXX         = C++ compiler (used in default compiler rules)
# CPPFLAGS    = C preprocessor flags (used in default C/C++ rules)
# CXXFLAGS    = C++ compilation flags (used in default C++ builds)
#
# The default rule in make that uses the variables CXX, CPPFLAGS and
# CXXFLAGS to generate object files from .cc files is as follows:
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
#########################################################################

BININSTALLDIR = /usr/local/bin
LIBINSTALLDIR = /usr/local/lib
HDRINSTALLDIR = /usr/local/include/gamma-${MAJORVERSION}.${MINORVERSION}.${RELEASEVERSION}

ROOTDIR = ../..
SRCDIR  = ../../src
SRCDIR1 = ../../src

# We use OS X's built-in BLAS/LAPACK/ATLAS libraries by default.
BLASINCL_FLAG   = -D_USING_BLAS_
LAPACKINCL_FLAG = -I/System/Library/Frameworks/vecLib.framework/Versions/A/Headers/ -D_USING_LAPACK_
# Uncomment the next two lines to disable use of OS X's built-in
# BLAS/LAPACK/ATLAS libraries.
# BLASINCL_FLAG   =
# LAPACKINCL_FLAG =

SRCDIRINCL_FLAG = -I$(SRCDIR1) $(BLASINCL_FLAG) $(LAPACKINCL_FLAG)

BINDIR   = ../../mac-darwin

DEBUG    = -g
OPTIMIZE = -O2

CC       = gcc
#CFLAGS  = $(DEBUG)
CFLAGS   = $(SRCDIRINCL_FLAG) $(OPTIMIZE)

CXX      = c++
CPPFLAGS = $(SRCDIRINCL_FLAG)

#CXXFLAGS = $(DEBUG)
CXXFLAGS = $(SRCDIRINCL_FLAG) $(OPTIMIZE)

LIBCPPFLAGS = $(SRCDIRINCL_FLAG)
#LIBCXXFLAGS = $(DEBUG)
LIBCXXFLAGS = $(OPTIMIZE)

SOCPPFLAGS = $(SRCDIRINCL_FLAG)
# Under OSX, -fPIC is a default so we don't need to specify it. However, one 
# does need -fno-common because the OS X linker does not allow "common" 
# symbols in shared libraries.
SOCXXFLAGS = $(SRCDIRINCL_FLAG) -fno-common $(OPTIMIZE)

PYSGCPPINCLFLAGS =
PYSGCPPFLAGS = -Wall -fPIC -fno-stack-protector $(SRCDIRINCL_FLAG)
PYSGCXXFLAGS = $(OPTIMIZE)

LDFLAGS  =
exeext   = .out

AR       = ar
ARFLAGS  = r
RANLIB   = ranlib

LDCONFIG = /sbin/ldconfig

LAPACK_LIBS =
BLAS_LIBS  = -framework veclib
LAB_LIBS = $(BLAS_LIBS) $(LAPACK_LIBS)
# If you want to disable use of OS X's built-in BLAS/ATLAS/LAPACK libraries,
# it's sufficient to change BLASINCL_FLAG and LAPACKINCL_FLAG (above). But
# if you want to be really sure, you can uncomment the line below.
# LAB_LIBS =

NPD      = --no-print-directory

#########################################################################
#
#	           Names Of Various Targets To Build
#
# These names are associated with the library we plan to build.
#
# LIB_NAME  = Name of library to be generated
# SO_NAME   = Name of shared lib to generate
# PYS_NAME  = Name of SWIG shared lib to generate
#
#
#########################################################################

LIB_NAME    = libgamma.a

COMPVER    = ${MAJORVERSION}.${MINORVERSION}
CURRVER    = ${COMPVER}.${RELEASEVERSION}

SO_BASE    = libgamma
SO_NAME    = ${SO_BASE}.dylib
SO_NAMEX   = ${SO_BASE}.${MAJORVERSION}.dylib
SO_NAMEXX  = ${SO_BASE}.${COMPVER}.dylib
SO_NAMEXXX = ${SO_BASE}.${CURRVER}.dylib

PYS_NAME    = _pygamma.so
PYS_NAMEX   = ${PYS_NAME}.${MAJORVERSION}
PYS_NAMEXX  = ${PYS_NAMEX}.${MINORVERSION}
PYS_NAMEXXX = ${PYS_NAMEXX}.${RELEASEVERSION}

#########################################################################
#
#                       Gamma Related Variables
#
#
# These variables are used to specify the GAMMA sources. Exactly what
# sources are associated with any one GAMMA module is contained in the
# external makefile MakeMods. From these we can construct the names of
# module source files and object files. These are directory specific.
#
# MakeMods    = File listing all current GAMMA source files.
# SRCDIR      = Base directory of GAMMA source codes.
# BINDIR      = Base directory of binaries.
# LIB_SRCS    = All code files to be put into the GAMMA static library.
# LIB_OBJS    = All object files to be put in the GAMMA static library.
# SO_SRCS     = All code files to be put into the GAMMA shared library.
# SO_OBJS     = All object files to be put in the GAMMA shared library.
#
# The variable ALLCCFILES should contain all GAMMA source .cc files.
# The variable ALLOFILES should contain all GAMMA object .o files.
# The source file names will have the source sub-directory as a prefix.
#     but not the full path relative to this directory.
#
# The included makefile supplies NO targets or rules of any kind.
#
#########################################################################


include ../../make/MakeMods


#########################################################################
#
#                              Main Target
#
# This target produce the static library.
#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)
#
#########################################################################


all: so lib
lib: $(BINDIR) ${BINDIR}/${LIB_NAME}
so:  $(BINDIR) $(BINDIR)/$(SO_NAME)
pysg: $(BINDIR) $(BINDIR)/$(PYS_NAME)

${LIB_NAME}: ${BINDIR}/${LIB_NAME}
${SO_NAME}:  ${BINDIR}/${SO_NAME}
${PYS_NAME}:  ${BINDIR}/${PYS_NAME}

big: so lib pysg test

#########################################################################

LIB_SRCS = $(ALLCCFILES)
LIB_OBJS = $(addsuffix .o, $(addprefix $(BINDIR)/, $(ALLFILES)))

SO_SRCS = $(ALLCCFILES)
SO_OBJS = $(addsuffix .soo, $(addprefix $(BINDIR)/, $(ALLFILES)))

# Python Swig
PYSG_SRCS = $(ALLCCFILES)
PYSG_SRCS =
PYSG_OBJS = $(addsuffix .pso, $(addprefix $(BINDIR)/, $(ALLFILES)))


PYSG_WRAP_SRC = $(addprefix $(BINDIR)/, pygamma_wrap.cxx)
PYSG_WRAP_SRC1 = $(addprefix $(BINDIR)/, pygamma.py)

PYSG_WRAP_SRCS = $(PYSG_WRAP_SRC) $(PYSG_WRAP_SRC1)
PYSG_WRAP_OBJS = $(addprefix $(BINDIR)/, pygamma_wrap.o)

# If add a new .i file, it needs to be added to gamma/trunk/make/Makemods
# You'll see examples there of how to do this.

OTHERDOTIFILES = $(addprefix $(SRCDIR)/, $(ALLIFILES))

$(PYSG_WRAP_SRC) : ${SRCDIR}/pygamma.i $(OTHERDOTIFILES)
	@echo
	swig -c++ -python -outdir $(BINDIR) -o $@ \
         -I../../src $<


#########################################################################
#
#                Build GAMMA Static Library Pattern Rules
#
# These rules specify how we build object file (*.o) from C++ code
# files (*.cc). Gnu make has a built in implicit pattern rule to do
# this task:
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
# But that does not suffice for two reasons. First, GAMMA source files
# reside in module directories off of the source directory SRCDIR.
# Second, we want all the object files to be built in the binaries
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file
# ${SRCDIR}/${MODDIR}/*.cc. The main GAMMA  makefile handles this by
# recursing through each module directory and letting it decide how to
# build itself. Here we will define a rule for each module directory.
#
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

#########################################################################
#
#                Build GAMMA Static Library Pattern Rules
#
# These rules specify how we build object file (*.o) from C++ code
# files (*.cc). Gnu make has a built in implicit pattern rule to do
# this task:
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
# But that does not suffice for two reasons. First, GAMMA source files
# reside in module directories off of the source directory SRCDIR.
# Second, we want all the object files to be built in the binaries
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file
# ${SRCDIR}/${MODDIR}/*.cc. The main GAMMA  makefile handles this by
# recursing through each module directory and letting it decide how to
# build itself. Here we will define a rule for each module directory.
#
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
#
#                Build GAMMA Shared Library Pattern Rules
#
# These rules specify how we build object file (*.soo) from C++ code
# files (*.cc). Gnu make has a built in implicit pattern rule to do
# this task:
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
# But that does not suffice for a few reasons. First, GAMMA sources
# reside in module directories off of the source directory SRCDIR.
# Second, we want all the object files to be built in the binaries
# directory, BINDIR. Thus we must build ${BINDIR}/*.o from a code file
# ${SRCDIR}/${MODDIR}/*.cc. Third, we want to clearly distinguish the
# object files for the shared library from those that are static. For
# that we will use the suffix .soo rather than .o. Here we will define
# define a rule for each module directory.
#
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
#
#         Build _PGSGAMMA (SWIG) Shared Library Pattern Rules
#
########################################################################

${BINDIR}/%.pso : ${SRCDIR}/${BASICS}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${MATRIX}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${HSPACE}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${LEVEL1}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${LSPACE}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${LEVEL2}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${BLOCH}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${GAMIO}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${BWR}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${PULSES}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${INTRANK2}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${FLOQUET}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${GRADIENTS}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${MULTISYS}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${ESRLIB}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${DEPREC}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

${BINDIR}/%.pso : ${SRCDIR}/${TESTING}/%.cc
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSGCXXFLAGS) $< -o $@

$(PYSG_WRAP_OBJS) : $(PYSG_WRAP_SRC)
	$(CXX) -c $(PYSGCPPFLAGS) $(PYSG_WRAP_SRC)  \
         $(PYSINCFLAGS) -o $(PYSG_WRAP_OBJS)


#########################################################################
#
#                       Library Related Variables
#
# These variables are used exclusively when building the static lib.
#
# LIB_SRCS    = All code files to be put into the library.
# LIB_OBJS    = All object files to be put into the library.
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)
# LIB_OBJS    = Name of object files used in library.
#
# These variables are used exclusively when building the shared library.
#
# SO_LDFLAGS = Flags used in .so build.                      (-shared)
# SO_LDLIBS  = Any libraries the shared lib. to be built depends upon.
# SO_SRCS    = All code files to be put into the shared library.
# SO_OBJS    = All object files to be put into the shared lib. Note
#              they are NOT the same as LIB_OBJ since we use special
#              compiler flags to generate them over the static library
#
# These variables are used generally.
#
# BINDIR      = Where we will ultimately place or binaries. This is
#               set to replace a CygWin build.
# NPD         = Turns of directory name printing when recursing through
#               other directories.
#
#########################################################################

SO_LDFLAGS = -dynamiclib
SO_LDLIBS  = $(LAB_LIBS)

#########################################################################
#
#                      Build The GAMMA Static Library
#
# LIB_SRCS    = All code files to be put into the library.
# LIB_OBJS    = All object files to be put into the library.
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)
# LIB_OBJS    = Name of object files used in library.
#
# The static library build depends on the object files in LIB_OBJS. If
# or when these are up to date then the target uses ar to form the
# library from the object files and then ranlib to adjust the library.
#
# The LIB_OBJS variable is set from LIB_SRCS earlier in this file.
# These are apparently implicitly dependent upon the source codes in
# LIB_SRCS (i.e. the .cc file with the same base name as the .o file)
# & have an implicit pattern rule as to how the .cc files are compiled
# into .o files. This pattern rule, as specified in the documentation
# for GNU make, is
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
# This implicit rule can be replaced by defining a new pattern rule
# with the same target and prerequisites, but different commands.
# If there are no commands following the rule, the rule is cancelled.
# When the new rule is defined, the built-in one is replaced. The new
# rule's position in the sequence of implicit rules is determined by
# where you write the new rule and affects how they are chained.
#
#########################################################################


${BINDIR}/${LIB_NAME}: ${BINDIR} ${LIB_OBJS}
	@echo
	@echo "Making Static Library $(LIB_NAME) From Object Files"
	@echo
	${AR} ${ARFLAGS} ${BINDIR}/${LIB_NAME} $(LIB_OBJS)
	@echo
	@echo "Adjusting Static Library $(LIB_NAME) For Random Access"
	@echo
	${RANLIB} ${BINDIR}/${LIB_NAME}

#########################################################################
#
#                       Build The GAMMA Shared Library
#
# The shared library build depends on the object files in SO_OBJS. If
# or when # these are up to date then the target uses g++ to form the
# library from the object files using appropriate linking commands.
#
# The SO_OBJS variable is set from SO_SRCS earlier in this file.
# These are NOT the same as LIB_OBJS used for the static library build
# because different flags are used when the source files are compiled.
# As with LIB_OBJS, the objects files are implicitly dependent upon the
# source codes in SO_SRCS (i.e. the .cc file with the same base name as
# the .soo file) & have an implicit pattern rule as to how the .cc
# files are compiled into .soo files. This pattern rule, as specified
# in the documentation for GNU make, is
#
# %.o : %.cc
#        $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $@
#
# Since we switched from .o to .soo and use particular sub-directories
# we have made our own rules to handle the compilation of sources.
#
# Mac OSX treates shared libraries a bit differently than most other
# Unix based systems. First they like their libraries to end with
# the suffix .dylib. They also have loadable modules (which this
# does not currently build) which may end in anything, so some use .so
# for the loadable module. During the shared library construction from
# object files they use the flag -dynamiclib (rather than shared on
# other Unix systems). As for library naming conventions, this also is
# slightly different. The full version is number (x.x.x) is placed
# between the library name and suffix, e.g. libgamma.4.0.1.dylib. This
# allows linking directly to a particular version of the library using
# -lname.x.x.x (e.g. -lgamma.4.0.1). To complicate matters a bit more,
# the name to be used when searching for the library at run time (of
# programs using the library) is specified.  After the shared library
# is created, linkes are set for the other library names to it. For
# example
#
# Library Made: libgamma.4.2.0.dylib
# First Link:   libgamma.4.dylib --> libgamma.4.2.0.dylib
# Second Link:  libgamma.dylib   --> libgamma.4.2.0.dylib
#
# SO_NAME    = Name of shared library to be generated. (libgamma.dylib)
# SO_LDFLAGS = Flags used in shared library linking.   (-dynamiclib)
# SO_OBJS    = Name of object files used in building the shared lib.
# SO_LDLIBS  = Libraries GAMMA shared library depends upon.
#
#########################################################################

${SO_NAME}: ${BINDIR}/${SO_NAME}

${BINDIR}/${SO_NAME}: ${BINDIR}/${SO_NAMEXXX}
	@rm -f ${BINDIR}/${SO_NAME}
	@ln -s ${BINDIR}/${SO_NAMEXXX} ${BINDIR}/${SO_NAME}

$(BINDIR)/$(SO_NAMEXXX): $(SO_OBJS)
	@echo
	@echo "Making Shared Library $(SO_NAME) From Object Files"
	@echo "      ========================================"
	@echo
	@echo "   * Building Library ${BINDIR}/${SO_NAMEXXX}"
	@$(CXX) ${SO_LDFLAGS} -install_name ${BINDIR}/${SO_NAMEX} \
         -compatibility_version ${COMPVER} -current_version ${CURRVER} \
         -o ${BINDIR}/${SO_NAMEXXX} ${SO_OBJS} $(SO_LDLIBS)
	@# gcc creates both libgamma.dylib and libgamma.4.2.0.dylib; we
	@# only want the latter.
	@rm -f ${BINDIR}/${SO_NAME} ${BINDIR}/${SO_NAMEX}
	@echo "   * Linking ${BINDIR}/${SO_NAMEX} To This Library"
	@cd $(BINDIR);ln -s ${SO_NAMEXXX} ${SO_NAMEX}
	@echo "   * Linking ${BINDIR}/${SO_NAME} To This Library"
	@cd $(BINDIR);ln -s ${SO_NAMEXXX} ${SO_NAME}
	@echo
	@echo



#########################################################################
#
#  Python Swig build shared library details
#
#########################################################################

# Using python to find the default library and include path for "python"
# executable on the local machine.
PYTHON_EXECUTABLE = python

PYTHONINCDIRS := ${shell ${PYTHON_EXECUTABLE} -c "import distutils.sysconfig; print distutils.sysconfig.get_python_inc()"}
PYTHONLIBDIRS := ${shell ${PYTHON_EXECUTABLE} -c "import distutils.sysconfig; print distutils.sysconfig.get_python_lib()"}

# Under OS X 10.6 (Snow Leopard), gcc wants to build 64-bit objects by
# default and will do so even if Python is 32 bit. We check whether Python
# is 32 or 64 bit and then use gcc's -arch flag to ensure it generates the
# correct object types.
# The test for 32 versus 64 bit Python is from here:
# http://stackoverflow.com/questions/1405913/how-do-i-determine-if-my-python-shell-is-executing-in-32bit-or-64bit-mode
# For the record, I've built a universal (32 and 64 bit) pygamma.so by
# setting PYTHONARCH to '-arch i386 -arch x86_64'. But with our current
# setup routine for PyGAMMA, a universal binary doesn't provide any
# advantages.
PYTHONARCH := ${shell ${PYTHON_EXECUTABLE} -c "import sys; print 'i386' if sys.maxint==2147483647 else 'x86_64'"}
PYTHONARCH :=  -arch $(PYTHONARCH)

PYSGCPPFLAGS += $(PYTHONARCH)


PYSINCFLAGS = -I$(PYTHONINCDIRS)
PYSG_LDFLAGS = -L$(PYTHONLIBDIRS)

PYSGAMMA_CHK = $(addprefix $(BINDIR)/, python_lib_incl.chk)

$(PYSGAMMA_CHK):
	@echo
	@echo Include directory: $(PYTHONINCDIRS)
	@echo Library directory: $(PYTHONLIBDIRS)
	@echo
	@echo Checking for python include and lib directories
	@echo
	@if (test -d ${PYTHONINCDIRS}); \
	then echo Good. The Python Includes Directory Exists. ${PYTHONINCDIRS}; \
	else echo Cannot Find The Python Include Directory! ${PYTHONINCDIRS}; \
	     echo Python Must Be Installed On The System For PyGAMMA To Work.; \
	     echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
	     echo ; \
	     false; \
	fi
	@if (test -d ${PYTHONLIBDIRS}); \
	then echo Good. The Python Library Directory Exists. ${PYTHONLIBDIRS}; \
	else echo Cannot Find The Python Library Directory! ${PYTHONLIBDIRS}; \
		echo Python Must Be Installed On The System For PyGAMMA To Work.; \
		echo Sorry, Cannot Build PyGAMMA Until This Is Taken Care Of.; \
		echo ; \
		false; \
	fi
	@echo

PYS_LDFLAGS = -dynamiclib -Wl,-headerpad_max_install_names -undefined dynamic_lookup $(PYTHONARCH)
PYS_LDLIBS   = $(LAB_LIBS)


${BINDIR}/$(PYS_NAME): $(PYSGAMMA_CHK) $(PYSG_OBJS) $(PYSG_WRAP_OBJS) 
	@echo
	@echo "Making PYSGAMMA Shared $(PYS_NAME) From Pythonized and Swigged Object Files"
	@echo
	$(CXX) ${PYS_LDFLAGS} $(PYSG_LIBDIR) -o ${BINDIR}/${PYS_NAME} $(PYSG_OBJS) $(PYSG_WRAP_OBJS) $(PYS_LDLIBS)



#########################################################################
#
#               Ensure Needed Binary Directory Exists
#
#########################################################################

${BINDIR}: force
	@if (test ! -d ./$(BINDIR)) \
        then \
          echo "First Constructing Binary Directory For GAMMA"; \
          echo "Making Directory ./$(BINDIR)"; \
          mkdir $(BINDIR); \
          chmod ug+w $(BINDIR); \
	fi

force:

#########################################################################
#
#                     Build And Run The Demos
#
# The purpose of this target is to run the GAMMA demo program(s). The
# demo programs painstakingly walk the user through each GAMMA module
# so that they can get a feel of what is available.
#
# The program will be named DemoGAMMA and should be found in the GAMMA
# demo directory in the modules sub-directory. The target should always
# run the demo program. It will insure that the GAMMA shared library is
# up to date, that the GAMMA library exists in the PATH, and that the
# demo executable is up to date.
#
# $(exeext)   = Executable extension on system.
# CXX         = C++ compiler name
# CXXFLAGS    = C++ compiler flags
# LDFLAGS     = Linker flags (automatically used)
#
# DEMO_DIR    = Directory where demo program sources are
# DEMO_NAME   = Base name of demo program (without .cc, .o, .exe,...)
# DEMO_PGM    = Name of produced demo executable
# DEMO_SRC    = Full name of demo program source file
# DEMO_OBJ    = Full name of demo program object file
# DEMO_FLAGS  = Flags to use when compiling the demo program
# DEMO_LD     = Command to link to shared library during runtime
#
# -o $@       : Sets output executable name to match the name of
#               the target (TestGAMMA.exe)
# -L          : Look in local directory for libraries
# -lgamma    : Link to library lgamma
#
#########################################################################

DEMO_DIR     = ../../demo/modules
DEMO_NAME    = DemoGAMMA
DEMO_PGM     = ${DEMO_NAME}${exeext}
DEMO_SRC     = $(DEMO_DIR)/${DEMO_NAME}.cc
DEMO_OBJ     = $(DEMO_DIR)/${DEMO_NAME}.o
DEMO_FLAGS   = -D_GAMMADEMO=1
DEMO_LD      = /lib/dyld --library-path

# --------------------- Demo Targets With Default Library -------------------
#            (Use Shared Library If Present, If Not Use Static Library)

demo:
	@${MAKE} $(NPD) ${DEMO_PGM}
	@strip ./${DEMO_PGM}
#	@${DEMO_LD} ${BINDIR} ./${DEMO_PGM} $(DEMO_DIR)

${DEMO_PGM}: ${DEMO_OBJ}
	$(CXX) -o $@ ${DEMO_SRC} ${DEMO_FLAGS} $(SOCPPFLAGS) $(CXXFLAGS) \
        $(LDFLAGS) -L${BINDIR} -lgamma

# --------------------- Demo Targets With Static Library ---------------------

demostatic:
	@${MAKE} $(NPD) demostat
	@strip ./${DEMO_PGM}
	./${DEMO_PGM} $(DEMO_DIR)

demostat: ${DEMO_OBJ}
	$(CXX) -g -o ${DEMO_PGM} ${DEMO_SRC} ${DEMO_FLAGS} -Wl,-static \
        $(LIBCPPFLAGS) $(LIBCXXFLAGS) $(LDFLAGS) -L${BINDIR} -static -lgamma

#########################################################################
#
#                     Build And Run The Tests
#
# The purpose of this target is to run the GAMMA test program(s). The
# test programs painstakingly run through each GAMMA module and do some
# rather extensive checking for validity.
#
# The program will be named TestGAMMA and should be found in the GAMMA
# test directory. This target should always run the test program. It
# will insure that the GAMMA library is up to date, that the
# GAMMA library exists in the PATH, and that the test executable is up
# to date.
#
# $(exeext)   = Executable extension on system.
# CXX         = C++ compiler name
# CXXFLAGS    = C++ compiler flags
# LDFLAGS     = Linker flags
#
# -o $@       : Sets output executable name to match the name of
#               the target
# -L          : Look in local directory for libraries
# -lgamma    : Link to library lgamma
#
#########################################################################

#########################################################################
#
# New Test routines
#

test:  ${BINDIR}/${LIB_NAME} $(BINDIR)/runtests $(BINDIR)/hstat \
       $(BINDIR)/sl_exchange7_L $(BINDIR)/par_xixA $(BINDIR)/xix_dec run


TESTS       = Tests
TESTSBASE   = testsuite runtests
TESTSHDR    = testsuite.h

TESTCCFILES   += $(addsuffix .cc, $(addprefix $(TESTS)/, $(TESTSBASE)))
TESTOBJFILES  += $(addsuffix .too,  $(addprefix $(BINDIR)/, $(TESTSBASE)))

ZTESTSBASE   = homo_stat sl_exchange7_L par_xixA xix_dec
ZTESTSHDR    =

ZTESTCCFILES += $(addsuffix .cc, $(addprefix $(TESTS)/, $(ZTESTSBASE)))
ZTESTOBJFILES  += $(addsuffix .too,  $(addprefix $(BINDIR)/, $(ZTESTSBASE)))

ALLTESTOBJFILES = $(TESTOBJFILES) $(ZTESTOBJFILES)

#CPP_TESTFLAGS = -g -Wall $(SRCDIRINCL_FLAG)
CPP_TESTFLAGS = -Wall $(SRCDIRINCL_FLAG)
CXX_TESTFLAGS = $(OPTIMIZE)

LD_TESTFLAGS =


${BINDIR}/%.too : ${SRCDIR}/${TESTS}/%.cc
	$(CXX) -c $(CPP_TESTFLAGS) $(CXX_TESTFLAGS) $< -o $@

$(BINDIR)/runtests : $(TESTOBJFILES)
	$(CXX) -o $@ $(LD_TESTFLAGS) $(TESTOBJFILES) -L${BINDIR}/ -lgamma $(LAB_LIBS)

$(BINDIR)/hstat : $(BINDIR)/homo_stat.too
	$(CXX) -o $@ $(LD_TESTFLAGS) $(BINDIR)/homo_stat.too -L${BINDIR}/ -lgamma $(LAB_LIBS)

$(BINDIR)/sl_exchange7_L : $(BINDIR)/sl_exchange7_L.too
	$(CXX) -o $@ $(LD_TESTFLAGS) $(BINDIR)/sl_exchange7_L.too -L${BINDIR}/ -lgamma $(LAB_LIBS)

$(BINDIR)/par_xixA : $(BINDIR)/par_xixA.too
	$(CXX) -o $@ $(LD_TESTFLAGS) $(BINDIR)/par_xixA.too -L${BINDIR}/ -lgamma $(LAB_LIBS)

$(BINDIR)/xix_dec : $(BINDIR)/xix_dec.too
	$(CXX) -o $@ $(LD_TESTFLAGS) $(BINDIR)/xix_dec.too -L${BINDIR}/ -lgamma $(LAB_LIBS)

RUNDIR = ./../../src/Tests

run: force
	@echo
	@echo Running tests:
	@echo
	@cd $(RUNDIR); python run_tests.py -v -p $(BINDIR)/
	@echo


# Python test suite.

PY_RUNDIR = ./../../src/pyTests

pytest: force
	@echo
	@echo Running Python tests:
	@echo
	@cd $(PY_RUNDIR); python ../Tests/run_tests.py -v
	@echo


#########################################################################
#
#                           Installation
#
# This is the typical Gnuish install target with some added GAMMA
# features. There are two items of concern here. 1.) The GAMMA script
# and 2.) The GAMMA shared library. Here are details for each.
#
# 1.) The GAMMA script (gamma)
# ============================
# The GAMMA script (gamma) is that which is run when programs linking
# to GAMMA are compiled. This script is tailored for a particular
# version and installation, that is, it knows which GAMMA version it
# is associated with and where that version is located. For example,
# the version may be 4.2.0 and compiled for OSX. On my OSX box that
# means my GAMMA script will know that /E/gamma/gamma-4.2.0 is my base
# GAMMA directory, that /E/gamma/gamma-4.2.0/src is where it can find
# the GAMMA source headers, & /E/gamma/gamma-4.2.0/mac-darwin
# is where any OSX specific GAMMA binaries will be located.
#
# When using the Gnu configuration process all of this information is
# set into the GAMMA script automatically. Since we do not run
# ./configure for this Makefile build, the GAMMA script must be
# configured directly herein. All that entails is setting the variable
# GAMMA_PATH with the script. This is done using sed on the precursor
# file gamma.in. When "make install" is run the target will convert
# gamma.in into gamma and set the proper directory information therein.
#
# In addition, the GAMMA script must be placed into a directory that
# is commonly known to most users. So, gamma is copied to ${INSTALLDIR}
# which is typically /usr/local/bin (or maybe just /usr/bin).
#
# 2.) The GAMMA shared library (libgamma.so)
# ==========================================
# When building GAMMA based programs using the GAMMA script gamma, the
# program will be linked to the GAMMA library. This all works just
# dandy if linking is done to the static library, libgamma.a, because
# the GAMMA script tell the compiler to look in the OSX binaries
# directory for the GAMMA library. Once the program has been compiled
# into an executable it contains the library functionality (at the
# expense of large executable file size) and no longer needs the static
# library. Hence the executable program can be moved anywhere on the
# system and run without troubles.
#
# The same is NOT true when GAMMA based programs link to the shared
# library, libgamma.so. THIS IS THE DEFAULT LINKAGE IN THIS GAMMA
# SCRIPT. In this instance the executable program will not contain
# the functions of the library (this keeps the executable file size
# small) and as a consequence must be told where to find the shared
# library when run. Since the executable may be moved around on the
# system, one must tell the system where the library exisits.
#
# To accomplish this, libgamma.so needs to be put in a standard
# directory where shared libraries are kept. For OSX this is usually
# /usr/lib (directory /usr/local/lib AFAIK is not preferred here)
# Furthermore, libgamma.so should simply exist as a symbolic link to
# the true library, the true library naming should use GAMMA version
# numbering in it.

# To summarize, this target (install) does the following:
#
# a.) Determines the GAMMA version directory (this is GAMMA_PATH)
# b.) Converts gamma.in into gamma where GAMMA_PATH is set properly.
# c.) Copies gamma to INSTALLDIR (e.g. /usr/local/bin).
#
#########################################################################

GSCRIPT       = gamma
#GAMMA_PATH    = ${shell cd ../..; pwd; cd platforms/Linux}
# GAMMA_PATH    = ${HDRINSTALLDIR}
# SEDSUB        = 's|CONFIGUREDGAMMAPATH|${GAMMA_PATH}|g'

####################################################################
#
# 	                     Targets For The GAMMA Headers
#
#####################################################################

installhdrs: force
	@if (test -d ${HDRINSTALLDIR}) \
	then echo The System GAMMA Headers Directory Exists. ${HDRINSTALLDIR}; \
	else echo Creating GAMMA Headers Directory. ${HDRINSTALLDIR}; \
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



# install: force
# 	@echo
# 	@echo "           Installing GAMMA"
# 	@echo
# 	@echo " * GAMMA library installation directory is ${LIBINSTALLDIR}"
# 	@echo " * Copying ${SO_NAMEXXX} to ${LIBINSTALLDIR}"
# 	@cp -f ${BINDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}
# 	@echo " * Linking ${SO_NAME} to ${SO_NAMEXXX}"
# 	@ln -sf ${LIBINSTALLDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}/${SO_NAME}
# 	@echo
install: force
	@echo
	@echo "           Installing GAMMA"
	@echo
	@echo " * GAMMA Script Installation Directory Is ${BININSTALLDIR}"
	@echo " * GAMMA Binary Library Installation Directory Is ${LIBINSTALLDIR}"
	@echo " * GAMMA Headers Installation Directory Is ${HDRINSTALLDIR}"
	@${MAKE} ${NPD} installscript
	@${MAKE} ${NPD} installhdrs
	@${MAKE} ${NPD} installsolib
	@echo " * Finished. Compile Command gamma Should Now Work"
	@echo




# PYSGDISTDIR is the destination directory for the binary (and pygamma.py)
# that the SWIG process creates.
PYSGDISTDIR = $(ROOTDIR)/pygamma/homemade

pysgdist: ${BINDIR} ${BINDIR}/$(PYS_NAME)
	@cp -f  ${BINDIR}/pygamma.py   $(PYSGDISTDIR)
	@cp -f  ${BINDIR}/$(PYS_NAME)  $(PYSGDISTDIR)
	@# Write a tiny Python file that contains the PyGAMMA version
	@echo "__version__ = '$(GAMMAVERSION)'" > $(PYSGDISTDIR)/pygamma_version.py


########################################################################
#
#                                Clean
#
# This is the typical Gnuish clean target. It will remove any libraries
# (dynamic and static), all object files, and the test program(s)
#
########################################################################

clean:
	rm -f ${LIB_OBJS}
	rm -f ${SO_OBJS}
	@rm -f $(PYSG_OBJS) $(PYSG_WRAP_SRCS) $(PYSG_WRAP_OBJS) $(PYSGAMMA_CHK)
	@rm -f $(ALLTESTOBJFILES)
	@rm -f *.asc
	@rm -f *.gnu
	@rm -f $(DEMO_OBJ)
	@rm -f $(DEMO_PGM)
	@rm -f ${BINDIR}/${SO_NAME}
	@rm -f ${BINDIR}/${SO_NAMEX}
	@rm -f ${BINDIR}/${SO_NAMEXX}
	@rm -f ${BINDIR}/${SO_NAMEXXX}
	@rm -f $(BINDIR)/$(PYS_NAME)

strip:
	@strip ${BINDIR}/${LIB_NAME}
	@strip ${BINDIR}/${SO_NAME}
	@strip ${LIBINSTALLDIR}/${SO_NAMEXXX}

testclean:
	@rm -f $(ALLTESTOBJFILES)

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



force:
