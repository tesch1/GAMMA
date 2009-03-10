/* SingleTest.h *************************************************-*-c++-*-
**									**
** 	                        G A M M A				**
**									**
**	Single Test                                    Interface	**
**								 	**
**      Scott Smith                                                     **
**      Copyright (c) 2000                                              **
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**      email: gamma@magnet.fsu.edu                                     **
**      www: http://gamma.magnet.fsu.edu                                **
**                                                                      **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/
     
/*************************************************************************
**                                                                      **
**  Description                                                         **
**                                                                      **
** Class SingleTest embodies a single test in the GAMMA platform        **
** testing hierarchy. Such tests are direct, examining specific aspects **
** of the platform. Thus a single test will always deal with one        **
** section within one class within one Module.                          **
**                                                                      **
*************************************************************************/

#ifndef   SingleTest_h_			// Is this file already included?
#  define SingleTest_h_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// Then this is the interface
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <iostream>			// Include file streams
#include <fstream>			// Include {if,of}streams
#include <string>			// Include string class
#include <iostream>

class SingleTest
  {
       int      TestStatus;			// Test status (True/False)
  std::string   TestName;			// Test name
  std::string   TestDescription;		// Test description
       int      TestRunLevel;			// Test run level
       int    (*TestTest)(std::ostream&, int);	// Test function

/* Note that above TestTest should will serve as a pointer to a test function
   that takes, as arguments, an output stream and an integer and returns an 
   integer. The above function pointer declaration is NOT the same a 
   int *TestTest(std::ostream&,int); which is a function which returns a 
   pointer to an integer. It is possible to simplify the code with a typedef

  typedef int GTestFct(std::ostream&, int);	// Simplify code (hopefully)
  GTestFct *TestTest;				// Test function (pointer to)

   but it isn't used enough to bother, unless there are some compiler
   problems figuring out what is going on. Actually I do use this in a
   function return type later in this file (see below).                      */ 

// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i                      SINGLE TEST ERROR HANDLING
// ____________________________________________________________________________

/*      Input                   ST      : A single test (this)
                                eidx    : Error index
                                noret   : Flag for linefeed (0=linefeed)
        Output                  none    : Error message output
                                          Program execution stopped if fatal */

         void SingleTest::STerror(int eidx, int noret=0) const;
volatile void SingleTest::STfatality(int eidx)           const;

// ____________________________________________________________________________ 
// ii                       SINGLE TEST DEFAULTS
// ____________________________________________________________________________

/* Each test points to a function that takes as arguments an output stream and
   an integer and returns an integer. When there is no particular test function
   (such as during default contruction), then the test should just point to a
   default function which return true (the integer 1). This is that function.
   The function is a friend function because for a member function one will 
   need to pass the argument "this" in addition. This is normally implicltly
   done, but not when we are using function pointers, which is what is used in
   this class when it calls TrueFct. A possible alternative is to use a
   static member function, but I have not learned how to do that yet.        */

//static int SingleTest::TrueFct(std::ostream& ostr, int RL);
friend int TrueFct(std::ostream& ostr, int RL);


public:

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// A            SINGLE TEST CONSTRUCTION, DESTRUCTION, ASSIGNMENT
// ____________________________________________________________________________
 
/* These constructors set up a new single test. 

        Input Arguments                     Result
        ---------------       -------------------------------------------------
               -              An empty test, just good to have, returns true

*/

MSVCDLC      SingleTest::SingleTest();
MSVCDLC      SingleTest::SingleTest(const SingleTest& ST);
MSVCDLC      SingleTest::~SingleTest();
MSVCDLL void SingleTest::operator= (const SingleTest& ST);

// ____________________________________________________________________________
// B                        SINGLE TEST ACCESS FUNCTIONS
// ____________________________________________________________________________


/*         Input                ST : A single test (this)
                  (name)      name : The name of the test     (setting name)
                  (status)  status : Current test status      (setting status)        
                  (descr)    descr : Current test description (setting describ)        
                  (runlev)  runlev : Current test run level   (setting runlev)        
                  (test)      test : Current test             (setting test)
           Output (name)      name : The name of the test     (getting name)
                  (status)  status : Current test status      (getting status)
                  (descr)    descr : Current test description (getting describ)
                  (runlev)  runlev : Current test run level   (getting runlev)
                  (test)      test : Result of test test      (getting test)
                              void : If setting interal value 
  
   Note that none of these function will run the test. They only allow users
   to access the current test parameters.                                    */

MSVCDLL const std::string& SingleTest::name()      const;		// Get name
MSVCDLL       int          SingleTest::status()    const;		// Get status
MSVCDLL const std::string& SingleTest::describe()  const;		// Get descript
MSVCDLL       int          SingleTest::runlevel()  const;		// Get runlev
  typedef int GTestFct(std::ostream&, int);	// Simplify code (hopefully)
MSVCDLL       GTestFct*    SingleTest::test()     const;		// Test function (pointer to)

MSVCDLL void SingleTest::name(const std::string& Name);			// Set name
MSVCDLL void SingleTest::status(    int          Status);		// Set status
MSVCDLL void SingleTest::describe(const std::string& D);		// Set decript
MSVCDLL void SingleTest::runlevel(  int          RunLev);		// Set runlevel
MSVCDLL void SingleTest::test(int (*T)(std::ostream& O, int RF));	// Set test

// ____________________________________________________________________________
// C                       SINGLE TEST TESTING FUNCTIONS
// ____________________________________________________________________________
 
/* Each test has a pointer to a function that is used for actual testing.  This
   test is not invoked unless the user requests that it be run.  The functions
   in this section allow for that. Note that once a test has been run test 
   status flag is set (default = -1 ==> untested) so that subsequent testing
   within a loop can readily be avoided.                                     */ 
 
MSVCDLL int SingleTest::runtest(std::ostream&   ostr, int force=1);
MSVCDLL int SingleTest::RunLevel0(std::ostream& ostr, int force=1);
MSVCDLL int SingleTest::RunLevel1(std::ostream& ostr, int force=1);
MSVCDLL int SingleTest::RunLevel2(std::ostream& ostr, int force=1);
MSVCDLL int SingleTest::RunLevel3(std::ostream& ostr, int force=1);
MSVCDLL int SingleTest::RunLevel4(std::ostream& ostr, int force=1);

// ____________________________________________________________________________
// D                       SINGLE TEST OUTPUT FUNCTIONS
// ____________________________________________________________________________

/*              Input           ST   : A single test (this)
                                ostr : Output ASCII file stream
                                full : Flag for amount of output
                Return          void : Test is sent to the output stream    */
 
MSVCDLL        std::ostream& print(std::ostream& ostr) const;
MSVCDLL friend std::ostream& operator<< (std::ostream& ostr, const SingleTest& ST);

// ____________________________________________________________________________
// E                 SINGLE TEST STL LIST SUPPORT FUNCTIONS
// ____________________________________________________________________________

/* These functions are MUST be defined if one desired to build C++ STL lists
   and vectors of single test, i.e. list<SingleTest> and vector<SingleTest>.
   They don't make a lot of sense and aren't really used, it is just that
   some compilers complain if they are not present (MSVC++ for one)          */

MSVCDLL bool SingleTest::operator==(const SingleTest& ST) const;
MSVCDLL bool SingleTest::operator!=(const SingleTest& ST) const;
MSVCDLL bool SingleTest::operator< (const SingleTest& ST) const;
MSVCDLL bool SingleTest::operator> (const SingleTest& ST) const;

// ____________________________________________________________________________
// F                       SINGLE TEST OUTPUT FUNCTIONS
// ____________________________________________________________________________

/* These functions facilitate output of single testing in a nicely formatted
   fashion. Note that when test results are listed only the status flags are
   utilized. That is, NO TESTS ARE RUN.  So, any testing should be performed
   prior to calling test output functions.                                   */

MSVCDLL std::ostream& SingleTest::Header(std::ostream& ostr, const std::string& S) const;
MSVCDLL std::ostream& SingleTest::Header(std::ostream& ostr) const;
MSVCDLL std::ostream& SingleTest::Result(std::ostream& ostr) const;
};

#endif							// SingleTest.h

