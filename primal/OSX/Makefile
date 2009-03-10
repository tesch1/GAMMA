#########################################################################
#                                                                       #
#          GAMMA Primal Makefile: OSX ==> (Py)GAMMA Library		#
#                                                                       #
# This is a primitive hand made Makefile to explicitly show how one     #
# builds and uses GAMMA as either a static or shared library & how one	#
# builds and uses PyGAMMA. It assumes that one is using the GCC C++	#
# compiler provided with (& amidst) OSX. At least, the binaries will	#
# be placed in a OSX related directory. So, run this makefile from a	#
# OSX bash shell so the environment for GCC, make, etc. are set up	#
# properly. As for PyGAMMA, one must have Python (build for OSX)	#
# as well as Boost.Python on the system.				#
#                                                                       #
# --------------------------------------------------------------------- #
#                                                                       #
#                             Quick Info                                #
#                                                                       #
#  1. Type "make" to build GAMMA static library. 		  	#
#  2. Type "make demo" to compile and run the GAMMA demo program(s).    #
#  3. Type "make test" to compile and run the GAMMA test program(s).    #
#  4. Type "make clean" to remove all object files.			#
#  5. Type "make distclean" to remove all object files libraries, exes.	#
#  6. The sources are assumed in SRCDIR == ../../src			#
#  7. The object are be produced in BINDIR ==  ../../powerpc-mac-darwin #
#  8. The lib files are produced in BINDIR ==  ../../powerpc-mac-darwin #
#  9. Any executable files (test,demo) are produced in this directory.	#
# 10. The important static library file is libgamma.a 			#
# 11. The important DLL library files are gamma.dll and libgamma.dll.a	#
# 12. The important PyGMAMA DLL library file is pygamma.dll.		#
# 13. Produces the following: a.) libgamma.a - The GAMMA static library	#
#			      b.) gamma.dll  - The GAMMA DLL		#
#			      c.) libgamma.dll.a - GAMMA imports lib.   #
#                             d.) pygamma.dll - PyGAMMA DLL             #
#                             e.) DemoGAMMA.exe - The demo program	#
#                             f.) TestGAMMA.exe - The test program	#
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
#           libgamma.a. These same object files will then be combined	#
#           into a dynamic library (DLL) with its assocatied imports    #
#           library, gamma.dll and libgamma.dll.a respectively. If we   #
#           are able to find Python and Boost.Python, then the PyGAMMA  #
#           DLL is also built, pygamma.dll. All libraries and object	#
#           files will be made in the directory specified by BINDIR.    #
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

DEBUG    = -g #-O2

CC       = gcc
CFLAGS   = $(DEBUG)

CXX      = c++
CPPFLAGS = -I../../src -DGSTATIC=1
CXXFLAGS = $(DEBUG)

LIBCPPFLAGS = -I../../src
LIBCXXFLAGS = $(DEBUG)

SOCPPFLAGS = -I../../src
SOCXXFLAGS = -fno-common

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
# SO_NAME    = Name of DLL to be generated/targeted.      (gamma.dll)   #
# SO_EXP_LIB = Name of exports library generated.    (libgamma.dll.a)   #
# SO_EXP_DEF = Name of definiton file to use.             (gamma.def)   #
# PYG_NAME    = Name of PyGAMAM DLL to be generated       (pygamma.dll) #
#									#
#########################################################################

LIB_NAME    = libgamma.a

VERNO      = 4
MINNO      = 1
RELNO      = 0
COMPVER    = ${VERNO}.${MINNO}
CURRVER    = ${COMPVER}.${RELNO}
SO_BASE    = libgamma
SO_BAUL    = "========"
SO_NAME    = ${SO_BASE}.dylib
SO_NAUL    = ${SO_BAUL}======
SO_NAMEX   = ${SO_BASE}.${VERNO}.dylib
SO_NAMEXX  = ${SO_BASE}.${COMPVER}.dylib
SO_NAMEXXX = ${SO_BASE}.${CURRVER}.dylib

PYG_NAME    = pygamma.dll

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
# BINDIR      = Base directory of Cygwin binaries.                      #
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
SRCDIR   =  ../../src
BINDIR   = ../../powerpc-mac-darwin

LIB_SRCS = $(ALLCCFILES)
LIB_OBJS = $(addsuffix .o, $(addprefix $(BINDIR)/, $(ALLFILES)))

SO_SRCS = $(ALLCCFILES)
SO_OBJS = $(addsuffix .soo, $(addprefix $(BINDIR)/, $(ALLFILES)))

PYG_SRCS = $(ALLCCFILES)
PYG_SRCS = 
PYG_OBJS = $(addsuffix .po, $(addprefix $(BINDIR)/, $(ALLFILES)))

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
BWR       = WBR
PULSES    = Pulses
INTRANK2  = IntRank2
FLOQUET   = Floquet
GRADIENTS = Gradients
MULTISYS  = MultiSys
ESRLIB    = ESRLib
DEPREC    = Deprecated
TESTING   = Testing

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
# Under OSX, -fPIC is a default so this is not a flag required during   #
# compilation. However, one does need -fno-common because their linker  #
# does not allow "common" symbols in shared libraries. These two ideas  #
# are dealt with withion SOCXXFLAGS.                                    #
#									#
# SOCPPFLAGS = -I../../src                                              #
# SOCXXFLAGS = -fno-common                                              #
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
#                              Main Target				#
#									#
# This target produce the static library.				#
#									#
# LIB_NAME    = Name of library to be generated/targeted.  (libgamma.a)	#
#									#
#########################################################################

all: $(BINDIR)/$(SO_NAME)
#all: $(BINDIR)/$(LIB_NAME) $(BINDIR)/$(SO_NAME)
#all: $(LIB_NAME) $(SO_NAME) $(PY_NAME)

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
# These variables are used exclusively when building the DLL. 		#
#									#
# SO_LDFLAGS = Flags used in DLL build.     (-Wl,--export-all-symbols)  #
# SO_LDLIBS  = Any libraries the DLL to be build depends upon.          #
# SO_SRCS    = All code files to be put into the DLL.                   #
# SO_OBJS    = All object files to be put into the DLL. Note that they  #
#               are one and the same as LIB_OBJ since we use no special #
#               compiler flags to generate them over the static library #
#									#
# These variables are used exclusively when building the PyGAMMA DLL.	#
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

SO_LDFLAGS = -dynamiclib
SO_LDLIBS  =

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
# Mac OSX treates shared libraries a bit differently than most other    #
# Unix based systems. First they like their libraries to end with       #
# the suffix .dylib. They also have loadable modules (which this        #
# does not currently build) which may end in anything, so some use .so  #
# for the loadable module. During the shared library construction from  #
# object files they use the flag -dynamiclib (rather than shared on     #
# other Unix systems). As for library naming conventions, this also is  #
# slightly different. The full version is number (x.x.x) is placed      #
# between the library name and suffix, e.g. libgamma.4.0.1.dylib. This  #
# allows linking directly to a particular version of the library using  #
# -lname.x.x.x (e.g. -lgamma.4.0.1). To complicate matters a bit more,  #
# the name to be used when searching for the library at run time (of    #
# programs using the library) is specified.  After the shared library   #
# is created, linkes are set for the other library names to it. For     #
# example                                                               #
#									#
# Library Made: libgamma.4.1.0.dylib					#
# First Link:   libgamma.4.dylib --> libgamma.4.1.0.dylib               #
# Second Link:  libgamma.dylib   --> libgamma.4.1.0.dylib               #
#									#
# SO_NAME    = Name of shared library to be generated. (libgamma.dylib)	#
# SO_LDFLAGS = Flags used in shared library linking.   (-dynamiclib) 	#
# SO_OBJS    = Name of object files used in building the shared lib.	#
# SO_LDLIBS  = Libraries GAMMA shared library depends upon.             #
#									#
#########################################################################

${SO_NAME}: ${BINDIR}/${SO_NAME}

${BINDIR}/${SO_NAME}: ${BINDIR}/${SO_NAMEXXX}
	@rm -f ${BINDIR}/${SO_NAME}
	@cp -f ${BINDIR}/${SO_NAMEXXX} ${BINDIR}/${SO_NAME}

$(BINDIR)/$(SO_NAMEXXX): $(SO_OBJS)
	@echo
	@echo "Making Shared Library $(SO_NAME) From Object Files"
	@echo "      ======================${SO_NAUL}=================="  
	@echo
	@echo "   * Building Library ${BINDIR}/${SO_NAMEXXX}"
	@g++ ${SO_LDFLAGS} -install_name ${BINDIR}/${SO_NAMEX} \
         -compatibility_version ${COMPVER} -current_version ${CURRVER} \
         -o ${BINDIR}/${SO_NAMEXXX} ${SO_OBJS} $(SO_LDLIBS)
	@rm -f ${BINDIR}/${SO_NAMEX} ${BINDIR}/${SO_NAME}
	@echo "   * Linking ${BINDIR}/${SO_NAMEX} To This Library"
	@ln -s ${BINDIR}/${SO_NAMEXXX} ${BINDIR}/${SO_NAMEX}
	@echo "   * Linking ${BINDIR}/${SO_NAME} To This Library"
	@ln -s ${BINDIR}/${SO_NAMEXXX} ${BINDIR}/${SO_NAME}
	@echo
	@echo

#########################################################################
#                                                                       #
#                     Build The PyGAMMA Shared Library 			#
#                                                                       #
# PYG_NAME    = Name of DLL to be generated/targeted.    (pygamma.dll)  #
# SO_EXP_LIB = Name of exports library generated.     (libgamma.dll.a)  #
# SO_OBJS    = Name of object files used in DLL.                        #
# SO_LDFLAGS = Flags used in DLL build.                      (-shared)  #
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
PYG_EXP_LIB = libpygamma.dll.a
PYGLDLIBS = 
PYINCDIR = C:/cygwin/usr/include/python2.2
PYLIBDIR = C:/cygwin/lib/python2.2
PYLIB2DIR = C:/cygwin/lib/python2.2/config
BOOSTINCDIR = "C:/Program Files/Boost/boost_1_28_0"
BOOSTLIBDIR = "C:/Program Files/Boost/boost_1_28_0/libs/python/build/bin/boost_python.dll/gcc/release/inlining-on/runtime-link-dynamic" 

 %.po : %.cc
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(PYGFLAGS) $< -o $@

PyGAMMAChk:
	@echo
	@echo "Making PyGAMMA DLL $(PYG_NAME) From Pythonized Object Files"
	@echo
	@if (test -d ./${PYINCDIR}) \
	then echo Good. The Cygwin Python Includes Directory Exists. ${PYINCDIR}; \
	else echo Cannot File The Cygwin Includes Python Directory! ${PYINCDIR}; \
	fi
	@if (test -d ./${PYLIBDIR}) \
	then echo Good. The Cygwin Python Library Directory Exists. ${PYLIBDIR}; \
	else echo Cannot File The Cygwin Python Library Directory! ${PYLIBDIR}; \
	fi
	@if (test -d ./${BOOSTINCDIR}) \
	then echo Good. The Cygwin Boost Includes Directory Exists. ${BOOSTINCDIR}; \
	else echo Cannot File The Cygwin Boost Includes Directory! ${BOOSTINCDIR}; \
	fi
	@if (test -d ./${BOOSTLIBDIR}) \
	then echo Good. The Cygwin Boost Library Directory Exists. ${BOOSTLIBDIR}; \
	else echo Cannot File The Cygwin Boost Library Directory! ${BOOSTLIBDIR}; \
	fi
	@echo "Compiling GAMMA Source Into PyGAMMA Object Code"
	@echo


$(PYG_NAME): PyGAMMAChk $(PYG_OBJS)
	@echo
	@echo "Making PyGAMMA DLL $(PYG_NAME) From Pythonized Object Files"
	@echo
	g++ -shared -Wl,--out-implib=$(PYG_EXP_LIB) \
	-o $(PYG_NAME) $(PYG_OBJS) $(PYG_LDFLAGS) $(PYG_LDLIBS)


#########################################################################
#                                                                       #
#                       Build The PyGAMMA DLL           		#
#                                                                       #
# PYG_NAME    = Name of DLL to be generated/targeted.    (pygamma.dll)  #
# SO_EXP_LIB = Name of exports library generated.    (libgamma.dll.a)   #
# SO_OBJS    = Name of object files used in DLL.                        #
# SO_LDFLAGS = Flags used in DLL build.     (-Wl,--export-all-symbols)  #
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
#                      Insure Needed Directories Exist                  #
#									#
#									#
#									#
#########################################################################

${BINDIR}: force
	@if (test ! -d ./$(BINDIR)) \
        then \
          echo "First Constructing OSX Binaries Directory For GAMMA"; \
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
# run the demo program. It will insure that the GAMMA shared library is #
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
DEMO_OBJ     = $(DEMO_DIR)/${DEMO_NAME}.o
DEMO_FLAGS   = -D_GAMMADEMO=1 -DGSTATIC=1
DEMO_LD      = /lib/dyld --library-path

# --------------------- Demo Targets With Default Library ---------------------
#              (Use DLL If Present, If Not Use Static Library)

demo:	
	@${MAKE} $(NPD) ${DEMO_PGM}
	@strip ./${DEMO_PGM}
#	@${DEMO_LD} ${BINDIR} ./${DEMO_PGM} $(DEMO_DIR)

${DEMO_PGM}: ${DEMO_OBJ}
	$(CXX) -o $@ ${DEMO_SRC} ${DEMO_FLAGS} $(CPPFLAGS) $(CXXFLAGS) \
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
#									#
#                     Build And Run The Tests				#
#									#
# The purpose of this target is to run the GAMMA test program(s). The   #
# test programs painstakingly run through each GAMMA module and do some	#
# rather extensive checking for validity.				#
#									#
# The program will be named TestGAMMA and should be found in the GAMMA  #
# test directory. This target should always run the test program. It	#
# will insure that the GAMMA library (DLL) is up to date, that the 	#
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
# features. There are two items of concern here. 1.) The GAMMA script	#
# and 2.) The GAMMA shared library. Here are details for each.		#
#									#
# 1.) The GAMMA script (gamma)						#
# ============================						#
# The GAMMA script (gamma) is that which is run when programs linking	#
# to GAMMA are compiled. This script is tailored for a particular	#
# version and installation, that is, it knows which GAMMA version it    #
# is associated with and where that version is located. For example,	#
# the version may be 4.1.0 and compiled for OSX. On my OSX box that 	#
# means my GAMMA script will know that /E/gamma/gamma-4.1.0 is my base  #
# GAMMA directory, that /E/gamma/gamma-4.1.0/src is where it can find   #
# the GAMMA source headers, & /E/gamma/gamma-4.1.0/powerpc-mac-darwin 	#
# is where any OSX specific GAMMA binaries will be located.		#
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
# which is typically /usr/local/bin (or maybe just /usr/bin).		#
#									#
# 2.) The GAMMA shared library (libgamma.so)				#
# ==========================================				#
# When building GAMMA based programs using the GAMMA script gamma, the	#
# program will be linked to the GAMMA library. This all works just	#
# dandy if linking is done to the static library, libgamma.a, because	#
# the GAMMA script tell the compiler to look in the OSX binaries	#
# directory for the GAMMA library. Once the program has been compiled	#
# into an executable it contains the library functionality (at the	#
# expense of large executable file size) and no longer needs the static #
# library. Hence the executable program can be moved anywhere on the	#
# system and run without troubles.					#
#									#
# The same is NOT true when GAMMA based programs link to the shared	#
# library, libgamma.so. THIS IS THE DEFAULT LINKAGE IN THIS GAMMA	#
# SCRIPT. In this instance the executable program will not contain	#
# the functions of the library (this keeps the executable file size	#
# small) and as a consequence must be told where to find the shared	#
# library when run. Since the executable may be moved around on the	#
# system, one must tell the system where the library exisits.		#
#									#
# To accomplish this, libgamma.so needs to be put in a standard 	#
# directory where shared libraries are kept. For OSX this is usually	#
# /usr/lib (directory /usr/local/lib AFAIK is not preferred here)	#
# Furthermore, libgamma.so should simply exist as a symbolic link to	#
# the true library, the true library naming should use GAMMA version	#
# numbering in it.

# To summarize, this target (install) does the following:		#
#									#
# a.) Determines the GAMMA version directory (this is GAMMA_PATH)       #
# b.) Converts gamma.in into gamma where GAMMA_PATH is set properly.    #
# c.) Copies gamma to INSTALLDIR (e.g. /usr/local/bin).			#
#									#
#########################################################################

INSTALLDIR    = /usr/local/bin
LIBINSTALLDIR = /usr/lib
GSCRIPT    = gamma
GSCRIPTIN  = gamma.in
CURRENTDIR = ${shell pwd}
GAMMA_PATH = ${shell cd ../..; pwd; cd primal/OSX}
SEDSUB     = 's|CONFIGUREDGAMMAPATH|${GAMMA_PATH}|g'

install: force
	@echo
	@echo "           Installing OSX GAMMA"
	@echo
	@echo " * GAMMA Script Installation Directory Is ${INSTALLDIR}"
	@echo " * The GAMMA Path Is Set to ${GAMMA_PATH}"
	@echo " * Setting GAMMA Script To Know GAMMA Path"
	@sed ${SEDSUB} ${GSCRIPTIN}>${GSCRIPT}
	@echo " * Copying GAMMA Script ${GSCRIPT} To Installation Directory"
	@cp -f ./${GSCRIPT} ${INSTALLDIR}
	@echo " * GAMMA Library Installation Directory Is ${LIBINSTALLDIR}"
	@echo " * Copying Shared Library To ${LIBINSTALLDIR}"
	@cp -f ${BINDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}
	@echo " * Setting Link For libgamma.so"
	@echo " * Running ldconfig To Update Cache Of Known Shared Libraries"
	@echo " *         (This May Take A Couple Of Seconds)"
	@${LDCONFIG} -n ${LIBINSTALLDIR}
	@echo " * Adding Link For GAMMA Base Library Name"
	@ln -sf ${LIBINSTALLDIR}/${SO_NAMEXXX} ${LIBINSTALLDIR}/${SO_NAME}
	@echo " * Finished. Compile Command gamma Should Now Work"
	@echo

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

crap:
	@echo "Here Is LIB_SRCS " ${LIB_SRCS}
	@echo "Here Is LIB_OBJS " ${LIB_OBJS}
	@echo "Here Is PYG_SRCS " ${PYG_SRCS}
	@echo "Here Is PYG_OBJS " ${PYG_OBJS}


#################################################################################
#                                                                               #
#                              GAMMA Distributions                              #
#                                                                               #
# What follows has nothing to do with any builds of GAMMA. This stuff hass been #
# included in this Makefile only so that GAMMA distributions will inlcude the   #
# distributed files in this directory. Do not worry about this for any builds   #
# and or runs of GAMMA programs.                                                #
#                                                                               #
#################################################################################

THISDIR       = OSX 
PRIMALPLAT    = "using OSX and the GCC compiler"
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

force:
