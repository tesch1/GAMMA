/* demo2.cc *****************************************************-*-c++-*-
**                                                                      **
**                  Basic GAMMA Demonstration Program 2					**
**                                                                      **
** This program does some very simple things just to point out a few	**
** basic principles and some aspects common to all GAMMA programs.		**
**																		**
** 1. Spin Systems - GAMMA's purpose is to facilitate simulations of	**
**		magnetic resonance problems.  Since we often work with			**
**		collections of inteactions spins, most GAMMA programs			**
**		declare a spin system.  The spin system keeps track				**
**		of the number of spins, their spin types, etc. I start			**
**		with a simple 2 spin one called sys: spin_sys sys(2)			**
**		By default all spins are protons.								**
** 2. Spin Operators - Knowing a spin system, one may construct a		**
**		consistent computer representation of spin operators.			**
**		GAMMA provides functions which build such operators				**
**		and operator data types that provide full mathematical			**
**		flexibility.  The functions take a spin system because			**
**		they contain all of the revelevant information needed			**
**		to make a spin operator: Fx(sys), Fz(sys)						**
** 3. Heteronuclei - The spin system has a set of functions (beside <<)	**
**		which allow you to change it and/or access it's details.		**
**		So you set up any spin system you like, the rest of				**
**		the functions will automaticlly adjust.							**
**                                                                      **
** GAMMA provides you the user with virtually any spin operator	for any	**
** spin system.  It provides you the way to easily make such operators	**
** by letting you set up an arbitrary spin system and mathematically	**
** manipulate the spin operators (should the one you like not be		**
** avaialable directly from a function.									**
**                                                                      **
** Those mathematically challenged take heart!  We'll move on to pulses	**
** and acquisitions in the next demo program.  Those who know about		**
** playing with spin dynamics, we have operators, superoperators and	**
** tensors yet to come.....												**
**                                                                      **
** Author:    S.A. Smith                                                **
** Date:      7/19/1996													**
** Last Date: 7/19/1996													**
**                                                                      **
*************************************************************************/

#include <gamma.h>				// Include GAMMA
using std::cout;				// (or using namespace std;)

/*              The next three should also work                         */

//#include <Matrix/MatrixIF.h>	// Include Matrix module
//#include <HSLib/HSLibIF.h>		// Inlcude Hilbert module
//using namespace std;

int main() 
  {
  cout << "\n\n\t\tGAMMA Demo Program 2\n\n";	// Write a program header
  spin_sys sys(2);				// Make a 2 spin system
  cout << "\n\tA Default Two Spin System:\n\n"	// Write the system to
       << sys;					// the screen
  cout << "\n\n\tHere is Fx For The System:"	// Write total Fx to the
	<< "\n\n" << Fx(sys);				// screen
  gen_op X = Fm(sys) + 3.2*Fz(sys);		// Build any spin operator
  cout << "\n\tHere is F- + 3.2Fz:\n\n" << X;	// Write it to screen 
  sys.isotope(0, "13C");			// Set 1st spin to carbon
  sys.isotope(1, "2H");				// Set 2nd spin to deuterium
  cout << "\n\n\tHere's The System, Now C-D:"	// Write the system to
       << "\n\n"<< sys;				// the screen
  cout << "\n\n\tHere's Fy For The C-D System:"	// Write total Fz to the
	<< "\n\n" << Fy(sys);				// screen
  cout << "\n\n\tHere's F+ For D in C-D System:"// Write selective F+ to the
	<< "\n\n" << Fp(sys);				// screen
  cout << "\n\n";				// Keep the screen nice
  return -1;
  }
