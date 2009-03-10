/* PyHSLibIF.cc ************************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      PyGAMMA HSLib Interface                       Implementation 	**
**                                                                      **
**      Copyright (c) 2002                                              **
**      Scott Smith							**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
** Description                                                          **
**                                                                      **
** PyGAMMA is GAMMA wrapped up into Python. To produce PyGAMMA the 	**
** GAMMA codes are compiled with the BOOST.Python library which exposes	**
** C++ to Python. Prior to compilation the flag PYGAMMA set non-zero,	**
** this signals the preprocessor to include any additional code that is	**
** exclusive to PyGAMMA (beyond GAMMA).					**
**                                                                      **
** The PyGAMMA interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the sources. This	**
** file is a dummy cc file that just includes the header (interface)	**
** were all the really important stuff is.				**
**                                                                      **
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#include <HSLib/PyHSLibIF.h>		// Include our interface. This is
					// where the vast majority of Python
					// exported functions are defined.

// sosi - look in Matrix build. I think this was put into an individual file...
//______________________________________________________________________________
//                          std::vector<int>
//______________________________________________________________________________

/* Some GAMMA functions use and return STL vectors of integers. Python cannot
   inherently know about an object of type std::vector<int>, so here we must
   define one.
*/

/*
typedef std::vector<int> IntVector;

// A helper function for dealing with errors. Throw a Python exception
// if p == m.end().
void throw_key_error_if_end(const IntVector& m, IntVector::const_iterator p) 
  {
  if(p == m.end())
    {
    PyErr_SetObject(PyExc_KeyError, boost::python::converters::to_python(3));
    boost::python::throw_error_already_set();
    }
  }

const int& get_item(const IntVector& self, int idx)
  { return self[idx]; }

const int& size(const IntVector& self)
  { return self.size(); }

void IntVectorPythonClass::set_item(IntVector& self, int idx, int value)
  { self[idx] = value; }
*/


//______________________________________________________________________________
//                          Boost.Python StringMap Example
//______________________________________________________________________________

//typedef std::map<std::size_t, std::string> StringMap;

// A helper function for dealing with errors. Throw a Python exception
// if p == m.end().
/*
void throw_key_error_if_end(
        const StringMap& m, 
        StringMap::const_iterator p, 
        std::size_t key)
{
    if (p == m.end())
    {
        PyErr_SetObject(PyExc_KeyError, boost::python::converters::to_python(key));
        boost::python::throw_error_already_set();
    }
}

// Define some simple wrapper functions which match the Python  protocol
// for __getitem__, __setitem__, and __delitem__.  Just as in Python, a
// free function with a ``self'' first parameter makes a fine class method.

const std::string& get_item(const StringMap& self, std::size_t key)
{
    const StringMap::const_iterator p = self.find(key);
    throw_key_error_if_end(self, p, key);
    return p->second;
}

// Sets the item corresponding to key in the map.
void StringMapPythonClass::set_item(StringMap& self, std::size_t key, const std::string& value)
{
    self[key] = value;
}

// Deletes the item corresponding to key from the map.
void StringMapPythonClass::del_item(StringMap& self, std::size_t key)
{
    const StringMap::iterator p = self.find(key);
    throw_key_error_if_end(self, p, key);
    self.erase(p);
}
*/

#endif					// End PyGAMMA include

