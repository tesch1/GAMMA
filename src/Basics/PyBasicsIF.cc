/* PyBasicsIF.cc ************************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      PyGAMMA Basics Interface                       Implementation 	**
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
** The PyBasics interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the Basics module.	**
** This file's a simple file that just includes the header (interface)	**
** were all the really important stuff is.				**
**									**
** Note: The ONLY time this file is ever needed is when JUST the GAMMA	**
**       Basics module is exported. That is rarely done, mostly when	**
**       testing of the module in Python is needed. As such, this file	**
**	 is normally not used in builds of either GAMMA or PyGAMMA.	**
**                                                                      **
*************************************************************************/

#include <Basics/PyBasicsIF.h>
