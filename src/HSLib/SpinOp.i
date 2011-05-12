/* SpinOp.i */
// Swig interface file.

%{
#include "HSLib/SpinOp.h"
%}

%include "std_string.i"

%rename(__add__)  complex::operator+;
%rename(__iadd__) complex::operator+=;
%rename(__isub__) complex::operator-=;
%rename(__neg__)  complex::operator- ();

%rename(__imul__) complex::operator*=;
%rename(__idiv__) complex::operator/=;



class spin_op 
{

public:

spin_op();
//spin_op(int spins, matrix* prmxs);
spin_op(const spin_op& SOp);

~spin_op();

//spin_op& operator= (const spin_op& SOp);

spin_op operator-  ()                    const;
spin_op operator+  (const spin_op& SOp1) const;

spin_op & operator+= (const spin_op& SOp1);

//friend spin_op          operator-  (const spin_op& SOp1, const spin_op& SOp2);

spin_op & operator-= (const spin_op& SOp1);

//friend spin_op          operator*  (const spin_op& SOp1, const spin_op& SOp2);

spin_op & operator*= (const spin_op& SOp1);

//friend spin_op       operator*  (const spin_op& SOp, const complex& z);
//friend spin_op       operator*  (const spin_op& SOp, double d);
//friend spin_op       operator*  (const complex& z,   const spin_op& SOp);
//friend spin_op       operator*  (double d,           const spin_op& SOp);

spin_op & operator*= (const complex& z);
spin_op & operator*= (double d);

//friend spin_op       operator/  (const spin_op& SOp, const complex& z);
//friend spin_op       operator/  (const spin_op& SOp, double d);

spin_op & operator/= (const complex& z);
spin_op & operator/= (double d);

//matrix   get_mx() const;
//operator matrix() const;

spin_op exp()     const; 		// Exponentation
spin_op adjoint() const; 		// Adjoint
complex trace()   const; 		// Trace

//friend spin_op exp(const spin_op& SOp); 		// Exponentation
//friend spin_op adjoint(const spin_op &SOp); 		// Adjoint
//friend complex trace(const spin_op &SOp); 		// Trace

int spins( )    const;				// Number of spins
int refs( )     const;				// Full space mx refs
int refs(int i) const;				// Sub-space mx refs
int HS( )       const;				// Full Hilbert space

//void       print(std::ostream& ostr, int full=0) const;
//friend std::ostream& operator<< (std::ostream& ostr, const spin_op& SOp);

void status(int full=1) const;

void FaxisStruct(char axis) const;

};

