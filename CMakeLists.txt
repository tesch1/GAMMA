cmake_minimum_required (VERSION 2.8.8)

# on macos, try to find gfortran from MacPorts
find_program (FORTRAN_COMPILER_MAC "gfortran-mp-4.8" )
if (NOT FORTRAN_COMPILER_MAC)
find_program (FORTRAN_COMPILER_MAC "gfortran-mp-4.9" )
endif (NOT FORTRAN_COMPILER_MAC)
if (FORTRAN_COMPILER_MAC)
set (CMAKE_Fortran_COMPILER ${FORTRAN_COMPILER_MAC})
endif (FORTRAN_COMPILER_MAC)

# default build mode
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "RelWithDebInfo")
  message ("Default build target: RelWithDebInfo")
endif (NOT CMAKE_BUILD_TYPE)

#
# GAMMA Project
#
project (GAMMA CXX)
enable_language (C)
enable_testing ()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 ")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall ")

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set (CMAKE_MACOSX_RPATH 1)

find_package (BLAS)
find_package (PythonLibs)
find_package (PythonInterp)
find_package (SWIG)

#
# Options
#
option (ENABLE_PYGAMMA "Build pyGAMMA (python swig bindings)" ON)
option (ENABLE_GAMMAT  "Build GAMMAT (matlab swig bindings)" ON)
option (ENABLE_STATIC  "Build static libgamma" ON)

if (NOT SWIG_EXECUTABLE OR NOT PYTHON_INCLUDE_PATH)
  set (ENABLE_PYGAMMA OFF)
endif (NOT SWIG_EXECUTABLE OR NOT PYTHON_INCLUDE_PATH)

if (ENABLE_PYGAMMA)
  set (ENABLE_STATIC ON)
  include (${SWIG_USE_FILE})
  #set (SWIG_CXX_EXTENSION "cc")
  set (CMAKE_SWIG_FLAGS "-c++")
else (ENABLE_PYGAMMA)
  message (WARNING "not building pygamma")
endif (ENABLE_PYGAMMA)

if (ENABLE_GAMMAT)
  set (ENABLE_STATIC ON)
  # for mex wrapper, finds MATLAB_ROOT for us
  #find_package (Matlab) - doesnt find matlab install correctly
  include (${CMAKE_SOURCE_DIR}/cmake/modules/mex2.cmake)
  mex_setup()
  #mex_setup("-largeArrayDims")
endif (ENABLE_GAMMAT)

# to be able to link the static lib into the dynamic wrappers
if (ENABLE_STATIC OR ENABLE_GAMMAT)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC ")
endif (ENABLE_STATIC OR ENABLE_GAMMAT)

#
# Subdirectories
#

# libgamma
add_subdirectory (src)
add_subdirectory (examples)

# pygamma
add_subdirectory (pygamma)

