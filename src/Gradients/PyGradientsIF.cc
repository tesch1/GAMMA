/* PyGradientsIF.cc *********************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      PyGAMMA Gradients Module Interface          Implementation 	**
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
** This file is used ONLY for administrative purposes. It is used only  **
** when the GAMMA Gradients module is built into a Python module w/o	**
** the rest of GAMMA exported. It is NOT used when PyGAMMA in its full  **
** splendor is made. In fact, this file should probably NOT be released **
** in a GAMMA distribution.                                             **
**                                                                      **
*************************************************************************/

#include <Gradients/PyGradientsIF.h>
