/* PyBoost.cc ***************************************************-*-c++-*-
**									**
**                                 G A M M A				**
**									**
**      Boost.Python Functions                          Implementation	**
**									**
**      Copyright (c) 2002						**
**      Scott A. Smith							**
**									**
**      $Header: $
**									**
*************************************************************************/
     
/*************************************************************************
**								 	**
**  Description							 	**
**								 	**
** This file defines some functionality for export into Python via	**
** Boost.Python. This includes both global functions and classes.	**
** This is NOT stemming directly from the GAMMA code, but is more	**
** auxiliary in nature. For example, GAMMA uses C++ STL classes such	**
** as vector and list. These may be needed in Python as GAMMA functions	**
** can take them as arguments or return them. However they are not	**
** implicitly exported. In order to utilize them in Python we must	**
** export them overtly, and this is done herein amoung other things.	**
**									**
** Note that unless one is building PyGAMMA (i.e. the variable PYGAMMA	**
** is set during the build), then none of this will be included.	**									**
**									**
*************************************************************************/

#ifndef   GPyBoost_cc_			// Is this file already included?
#  define GPyBoost_cc_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma implementation		// Then this is the implementation
#  endif

#ifdef PYGAMMA				// If compiling PyGAMMA

#include <boost/python/class.hpp>	// Boost.Python classes
#include <boost/python/iterator.hpp>	// Boost.Python iterators
#include <boost/python.hpp>	// Boost.Python
#include <vector>			// Include libstdc++ STL vectors

using std::string;			// Using libstdc++ strings
using std::vector;			// Using libstdc++ vectors
using boost::python::class_;		// Using Boost.Python classes
using boost::python::iterator;		// gcc 2.96 bug workaround

// ____________________________________________________________________________
//                            STL Vector Of Doubles - C++
// ____________________________________________________________________________

//typedef std::list<int> list_int;
//typedef std::pair<list_int::iterator,list_int::iterator> list_range;

//void   push_back(list_int& x, int y) { x.push_back(y); }
//int         back(list_int& x)        { return x.back(); }
//list_range range(list_int& x)        { return list_range(x.begin(), x.end()); }

void PyBoost()
  {
//  def("range", &::range);

// ____________________________________________________________________________
//                        STL Vector Of Integers - Python Export
// ____________________________________________________________________________

    class_<vector<int> >("ivec")
//      .def("__iter__", iterator<vector<int> >())
      ;
// ____________________________________________________________________________
//                        STL Vector Of Doubles - Python Export
// ____________________________________________________________________________

    class_<vector<double> >("dvec")
//      .def("__iter__", iterator<vector<double> >())
      ;
  }

#endif					// End PyGAMMA code block

#endif					// PyBoost.cc
