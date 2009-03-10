/* ModTest.h ****************************************************-*-c++-*-
**									**
** 	                        G A M M A				**
**									**
**	Module Test                                 Interface		**
**								 	**
**      Scott Smith                                                     **
**      Copyright (c) 2000                                              **
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**      email: gamma@magnet.fsu.edu                                     **
**      www: http://gamma.magnet.fsu.edu                                **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/
     
/*************************************************************************
**                                                                      **
**  Description                                                         **
**                                                                      **
** Class ModTest embodies a test set for the GAMMA platform testing     **
** hierarchy. Such tests are specific to a particular GAMMA module.     **
** A module test will always deal with a single subdirectory in the     **
** GAMMA source directory, e.g. $GAMMA/src/"module". Thus this class    **
** will be intrinsically be associated with one such subdirectory and   **
** test all of the code therein.  It does so by running class tests     ** 
** where each class test is associated with a file within the module    **
** subdirectory.							**
**                                                                      **
*************************************************************************/

#ifndef    ModTest_h_			// Is this file already included?
#  define  ModTest_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// Then this is the interface
#  endif

#include <Testing/ClassTest.h>		// Include class tests
#include <list>				// Include libstdc++ STL lists
#include <iostream>			// Include file streams
#include <fstream>			// Include {if,of}streams
#include <string>			// Include string class

/* sosi - gcc 2.8.1 on Solaris 6 has trouble with public std::list<ClassTest>
          as the base class.  This is not true with 2.95.2 on Irix 6.5, 
          MSVC++ 5, and egcs-2.91.60 under CygWin.  Removal of std:: here is
          fine with gcc 2.8.1 though.  Soooo, what to do?  I'll type def it
          and hope for the best....... yes this seems OK with all C++ flavors.
          Here is the story then: I have replaced the simple class declaration
          below with the typedef and the declaration using the typedef.  When
          2.8.2 is ancient I'll just set things back.        June 22 2000    */

//class ModTest: public std::list<ClassTest>

typedef std::list<ClassTest> stdlistMT;

class ModTest: public stdlistMT
{
       int         TestStatus;               // Test status (True/False)
  std::string      TestName;                 // Test name
  std::string      TestDescription;          // Test description
       int         TestRunLevel;             // Test run level
  std::vector<int> TestResults;              // Array of test results

private:
 
// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i                      MODULE TEST ERROR HANDLING
// ____________________________________________________________________________

/*      Input                   MT      : A class test (this)
                                eidx    : Error index
                                noret   : Flag for linefeed (0=linefeed)
        Output                  none    : Error message output
                                          Program execution stopped if fatal */

         void ModTest::MTerror(int eidx, int noret=0) const;
volatile void ModTest::MTfatal(int eidx)              const;

// ____________________________________________________________________________
// ii                   MODULE TEST INITIALIZATION FUNCTIONS
// ____________________________________________________________________________

/* This function will initialize the test results vector TestResults. This      
   should be done whenever testing is done if either 1.) The status flag is
   -1, indicating no tests have ever been run, or if the current number of
   tests does not match the size of the tests results vector.  The latter
   indicates that additional tests have been added, potentially with a
   different ordering, since the test results were generated previously.    */

void ModTest::SetResults(int force=0);                 

// ____________________________________________________________________________
// iii               MODULE TEST SECTION TEST INDEXING FUNCTIONS
// ____________________________________________________________________________
 
/* These function deal with indicies of Class Test tests. They allow one to
   obtain the test Pix from either an interger or a string and they perform
   range checking to insure that the requested test exists in the section.   */
 
bool                                 ModTest::CheckIndex(int k, int w=1) const;
std::list<ClassTest>::iterator       ModTest::GetPixNC(int k);
std::list<ClassTest>::const_iterator ModTest::GetPix(int k)              const;
std::list<ClassTest>::const_iterator ModTest::GetPix(const std::string& N)    const;
int                                  ModTest::GetIndex(const std::string& N)  const;


public:

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// A            MODULE TEST CONSTRUCTION, DESTRUCTION, ASSIGNMENT
// ____________________________________________________________________________
 
/* Were it not for the additional variables defined in this class, all the
   constructors would just be inherited from the ANSI standard "list" class
   in the C++ library libstdc++. Since this is not the case, I am listing all
   such constructors (commented out) and will only (re)define the ones that
   I care about.

ModTest()                               Empty Class Test
ModTest(int N)                          Module Test w/ N Tests
ModTest(int N, const ClassTest& CT)     Module Test w/ N Class Tests
ModTest(const ModTest& MT)              Class Test copy of MT
ModTest assign(N)                       Assign N element
~ModTest()                              Destructor of Module Test           */

MSVCDLC            ModTest::ModTest();                   // Empty Module Test
MSVCDLC            ModTest::ModTest(const  ModTest& MT); // Module Test copy of MT
MSVCDLL ModTest& ModTest::operator= (const ModTest& MT); // Assignment operator
 
// ____________________________________________________________________________
// B                   MODULE TEST ITERATORS & MEMBER ACCESS
// ____________________________________________________________________________

/* These functions are inherited from the ANSI standard "list" class in the C++
   library libstdc++.  I am listing them here so that I & other users don't
   have to keep looking them up all the time.

list<SectTest>::iterator ModTest::begin()      Pointer to 1st element
list<SectTest>::iterator ModTest::end()        Pointer to last element
SectTest                 ModTest::front()      First element
SectTest                 ModTest::back()       Last element                  */

// ____________________________________________________________________________
// C                     MODULE TEST LIST & QUEUE OPERATIONS
// ____________________________________________________________________________

/* These functions are inherited from the ANSI standard "list" class in the C++
   library libstdc++.  I am listing them here so that I & other users don't 
   have to keep looking them up all the time.

ModTest::push_back(const  SectTest& ST)         Add ST to list end
ModTest::pop_back()                             Remove ST at list end
ModTest::push_front(const SectTest& ST)         Add ST to list start
ModTest::pop_front(const  SectTest& ST)         Remove ST at list start
ModTest::insert(iterator p, SectTest& ST)       Add ST before p
ModTest::erase(iterator p)                      Remove ST at p
ModTest::clear()                                Remove all list entries      */

// ____________________________________________________________________________
// D                    MODULE TEST ADDITIONAL QUEUE OPERATIONS
// ____________________________________________________________________________

/* These functions are inherited from the ANSI standard "list" class in the C++
   library libstdc++.  I am listing them here so that I & other users don't 
   have to keep looking them up all the time.

int  ModTest::size()                            Number of entries
bool ModTest::empty()                           TRUE if pset empty
bool ModTest::operator==(ModTest MT)          TRUE if psets equal
bool ModTest::operator!=(ModTest MT)          TRUE if psets not equal        */

// ____________________________________________________________________________
// E                     MODULE TEST LIST AUXILIARY FUNCTIONS
// ____________________________________________________________________________
 
/* These functions are "list" type of functions that have been added to make 
   the list of class test (i.e. module test) do simple things needed for ready 
   access of class tests.
   
    Function   Arguments                     Result 
   ----------  ---------  ----------------------------------------------------- 
    contains    string    Returns true/false if test of name is in module tests
       "       ClassTest  Returns true/false if section test is in module tests
     seek       string    Returns iterator in module tests for test with name
       "       ClassTest  Returns iterator in module tests for class test    */ 
 
MSVCDLL int ModTest::contains(const std::string& N) const;
MSVCDLL int ModTest::contains(const ClassTest& CT)  const;

MSVCDLL std::list<ClassTest>::const_iterator ModTest::seek(const std::string& N) const;
MSVCDLL std::list<ClassTest>::const_iterator ModTest::seek(const ClassTest& CT)  const;
 
// ____________________________________________________________________________
// F                       MODULE TEST ACCESS FUNCTIONS
// ____________________________________________________________________________
 
/* These functions allow access to simple details of individual Class Tests
   or all tests in one lump sum. They will perform NO TESTING (we want code
   a bit more sophisticated for that - see a later section).  These functions
   facilitate external programs in generating nicely formatted output with the
   Module Test and Class Test results. The lower case names parallel those
   that are present in the Section and Single Test classes.

     Function                             Result
  ---------------  ---------------------------------------------------------
      GetName      Returns string for name of Module or Class Test
     GetNames      Returns string vector names of all Class Tests
  GetDescription   Returns string for description of Module or Class Test
  GetDescriptions  Returns string vector descriptions of all Class Tests
     GetStatus     Returns int for status of Module or Class Test
    GetStatuses    Returns int vector for status of all Class Tests
    GetRunLevel    Returns int for run level of Module or Class Test
   GetRunLevels    Returns int vector for run level of all Class Tests
    GetResults     Returns int vector for all current Class Test Results     */

MSVCDLL std::string    ModTest::GetName()                    const;
MSVCDLL std::string    ModTest::GetName(int k)               const;
//std::string    ModTest::GetName(int k, int j)        const;
MSVCDLL std::vector<std::string> ModTest::GetNames()                   const;
//vector<string> ModTest::GetNames(int k)              const;
MSVCDLL std::string         ModTest::GetDescription()             const;
MSVCDLL std::string         ModTest::GetDescription(int k)        const;
//string         ModTest::GetDescription(int k, int j) const;
MSVCDLL std::vector<std::string> ModTest::GetDescriptions()            const;
//vector<string> ModTest::GetDescriptions(int k)       const;
MSVCDLL int            ModTest::GetStatus()                  const;
MSVCDLL int            ModTest::GetStatus(int k)             const;
MSVCDLL std::vector<int>    ModTest::GetStatuses()                const;
MSVCDLL int            ModTest::GetRunLevel()                const;
MSVCDLL int            ModTest::GetRunLevel(int k)           const;
MSVCDLL std::vector<int>    ModTest::GetRunLevels()               const;
MSVCDLL std::vector<int>    ModTest::GetResults();
MSVCDLL std::vector<int>    ModTest::GetResults(int k);

/*         Input                MT : A module test (this)
                  (name)      name : The name of the test     (setting name)
                  (status)  status : Current test status      (setting status)
                  (descr)    descr : Current test description (setting describ)
                  (runlev)  runlev : Current test run level   (setting runlev)
           Output (name)      name : The name of the test     (getting name)
                  (status)  status : Current test status      (getting status)
                  (descr)    descr : Current test description (getting describ)
                  (runlev)  runlev : Current test run level   (getting runlev)
                              void : If setting interal value                */  
 
MSVCDLL const std::string& ModTest::name()     const;                // Get name
MSVCDLL       int          ModTest::status()   const;                // Get status
MSVCDLL const std::string& ModTest::describe() const;                // Get descript
MSVCDLL       int          ModTest::runlevel() const;                // Get runlev
MSVCDLL       void         ModTest::name(const  std::string& Name);  // Set name
MSVCDLL       void         ModTest::status(     int          Status);// Set status
MSVCDLL       void         ModTest::describe(const std::string& D);  // Set decript
MSVCDLL       void         ModTest::runlevel(   int          RLev);  // Set runlev
 
// ____________________________________________________________________________
// G                      MODULE TEST TESTING FUNCTIONS
// ____________________________________________________________________________
 
/* These functions will invoke any or all of the Class Tests that are listed
   as part of this Class Test. The results of the Class Tests will be stored
   in the vector TestResults and the summed results placed into TestStatus.
   The value of TestStatus (default -1) indicates the whether the tests have
   been run (as does the vector TestResults).  There are three basic means for
   doing the testing:
                       1.) Run All Of The Class Tests
                       2.) Run All Class Tests Until A Failure Occurs
                       3.) Run A Test On A Specific Class Test

   In each case the "force" flag dictates whether these tests should be run
   anew or alternatively reuse test results if previsouly run (status!=-1).  */
 
//-----------------------------------------------------------------------------
//                             Run All Class Tests
//-----------------------------------------------------------------------------

MSVCDLL int ModTest::TestClasses(std::ostream& ostr, int anew, int keepon=0);
 
//-----------------------------------------------------------------------------
//                    Run Specific Class Test (By Index Or Name)
//-----------------------------------------------------------------------------

MSVCDLL int ModTest::TestClass(std::ostream& ostr, const int T, 
                                                     int anew=0, int keepon=0);
MSVCDLL int ModTest::TestClass(std::ostream& ostr, const std::string& T,
                                                     int anew=0, int keepon=0);

// ____________________________________________________________________________
// H                       MODULE TEST OUTPUT FUNCTIONS
// ____________________________________________________________________________

/* These functions facilitate output of module testing in a nicely formatted
   fashion. Note that when test results are listed only the status flags are
   utilized. That is, NO TESTS ARE RUN.  So, any testing should be performed
   prior to calling test output functions.
   
   Header:  This function makes a nice title for the module's class tests,
   ======   below which the PASS/FAIL results of the class tests should be
            listed. Class test PASS/FAIL listing is done in the Class Test
            class (ClassTest::Result) and should conform to the format set
            herein.
   Result:  This function makes a simple single line output for listing under
   ======   GAMMA Test headers (GamTest::Header).  The format of the output
            should conform to the format of that header.
   Results: This function loops through and spits out all the Class Test
   =======  results of the module (ClassTest::Result)
   ResRec:  Whereas the above Results function tabulates class test results,
   ======   this function will go into each class and output results from
            individual secton tests. Typically this is done only on classes
            that have failed their test. It will also have section tests
            output results from single tests if the function recursion level
            (nlevels) is set greater than 1.                                */

MSVCDLL std::ostream& ModTest::Header(std::ostream&  ostr)             const;
MSVCDLL std::ostream& ModTest::Result(std::ostream&  ostr)             const;
MSVCDLL std::ostream& ModTest::Results(std::ostream& ostr, int goon=1) const;
MSVCDLL std::ostream& ModTest::ResRec(std::ostream&  ostr, int keepon, int nl=1);

// ____________________________________________________________________________
// I                      MODULE TEST INTERACTIVE FUNCTIONS
// ____________________________________________________________________________

/* These functions facilitate the running a module test. Recall that each 
   module test runs through a series of class tests, ultimately the test 
   returning TRUE/FALSE on completion. However there are several additional 
   facets of module testing.

   1.) Reuse Last Class Test Results: If previously performed, we can just
                                      bypass a test and use its T/F status
   2.) Continue Through Failed Tests: If a class test fails should testing
                                      stop or should one go on to the next
   3.) Recurse Through Section Tests: If a class test fails should testing
                                      recurse into section tests for that
                                      class, displaying specific failures?

   These functions assume you want some output text from running the tests,
   otherwise you would just use the TestLevel function directly, right?      */  

MSVCDLL int ModTest::AskRun(std::ostream& ostr);

// ____________________________________________________________________________
// J                       SECTION TEST AUXILIARY FUNCTIONS
// ____________________________________________________________________________
 
MSVCDLL std::ostream& ModTest::ListTests(std::ostream& ostr) const;
MSVCDLL std::ostream& ModTest::FinishTest(std::ostream& ostr) const;


};

#endif							// ModTest.h

