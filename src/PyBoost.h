/* PyBoost.h ****************************************************-*-c++-*-
**									**
** 	                        G A M M A				**
**									**
**	Boost.Python Functions                               Interface	**
**								 	**
**      Scott Smith                                                     **
**      Copyright (c) 2002						**
**      $Header: $
**								 	**
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
     
#ifndef   GPyBoost_h_			// Is this file already included?
#  define GPyBoost_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// Then this is the interface
#  endif

#ifdef PYGAMMA				// If compiling PyGAMMA

void PyBoost();

#endif					// End PyGAMMA code block

#endif					// PyBoost.h

