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

set (CMAKE_CXX_FLAGS " -g -O3 ")
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
option (ENABLE_PYGAMMA "Build pyGAMMA as well as GAMMA" ON)
option (ENABLE_STATIC  "Build static libgamma" OFF)

if (NOT SWIG_EXECUTABLE OR NOT PYTHON_INCLUDE_PATH)
  set (ENABLE_PYGAMMA OFF)
endif (NOT SWIG_EXECUTABLE OR NOT PYTHON_INCLUDE_PATH)

if (ENABLE_PYGAMMA)
  include (${SWIG_USE_FILE})
  #set (SWIG_CXX_EXTENSION "cc")
  set (CMAKE_SWIG_FLAGS "-c++")
else (SWIG_EXECUTABLE)
  message (WARNING "not building pygamma")
endif (SWIG_EXECUTABLE)

#
# Subdirectories
#

# libgamma
add_subdirectory (src)

# pygamma
add_subdirectory (pygamma)

