/* col_vector.i */
// Swig Interface File


%{
#include "Matrix/col_vector.h"
%}


%include "std_vector.i"
%include "std_string.i"


%rename(__add__)  col_vector::operator+;
%rename(__iadd__) col_vector::operator+=;
%rename(__sub__)  col_vector::operator-;
%rename(__isub__) col_vector::operator-=;

%rename(__mul__)  col_vector::operator*;
%rename(__imul__) col_vector::operator*=;



//class row_vector;			 // Know that row_vector is a class

class col_vector : public matrix
{

//friend class row_vector;

public:


col_vector ( );
col_vector (int i);
col_vector (int i, double d);
col_vector (int i, const complex& z);
col_vector (const col_vector& cvec);

//col_vector (const matrix& mx);

~col_vector ();

//col_vector& operator = (const col_vector& cvec);
//col_vector& operator = (const row_vector& rvec);

//col_vector& operator = (const matrix& mx);

complex&    operator() (int i);
complex     get(int i) const;

double      getRe(int i) const;
double      getIm(int i) const;
void        put(const complex& z, int i);

int elements( ) const;
int size( )     const;

/*
friend col_vector operator * (const complex& z, const col_vector& cvec);
friend col_vector operator * (double         d, const col_vector& cvec);
friend col_vector operator * (const matrix& mx, const col_vector& cvec);
*/

col_vector operator + (const col_vector& cvec) const;
//col_vector operator + (const matrix&     mx)   const;

col_vector operator - (const col_vector& cvec) const;
//col_vector operator - (const matrix&     mx)   const;

//complex    operator * (const col_vector& cvec) const; // causes and error in C++ code.
//matrix     operator * (const row_vector& rvec) const;
//matrix     operator * (const matrix&     mx)   const;

col_vector operator * (const complex&    z)    const;
col_vector operator * (double            d)    const;

//col_vector operator / (const complex&    z)    const;
//col_vector operator / (double            d)    const;

void operator += (const col_vector& cvec1);
//void operator += (const matrix&        mx);

void operator -= (const col_vector& cvec1);
//void operator -= (const matrix&        mx);

void operator *= (const complex&        z);
void operator *= (      double          d);

//void operator /= (const complex&        z);
//void operator /= (const double          d);

// col_vector operator- ();                   // MATRIX INHERITED

/*
friend row_vector adjoint(const   col_vector& cvec);
friend row_vector transpose(const col_vector& cvec);
friend complex    trace(const     col_vector& cvec);
*/

row_vector adjoint()      const;
row_vector transpose()    const;
complex    trace()        const;
col_vector differential() const;

double           norm()          const;
complex          sum()           const;
double           maxRe()         const;
double           maxIm()         const;
complex          maxZ()          const;
double           minRe()         const;
double           minIm()         const;
complex          minZ()          const;
int              max(int type=0) const;
int              min(int type=0) const;
void             flip();
complex          sum(int st, int ne) const;
void             zero();

std::vector<int> sort(int type=0) const;

/*
friend col_vector FFT(const  col_vector& cvec);
friend col_vector IFFT(const col_vector& cvec);
friend col_vector product(const col_vector& cvec1, const col_vector& cvec2);
friend col_vector product(const col_vector& cvec,        row_vector& rvec);
*/

col_vector product()                        const;
col_vector product(const row_vector& rvec)  const;
col_vector product(const col_vector& cvec2) const;

/*
friend double  scalar_product(const col_vector& cvec);
friend complex scalar_product(const col_vector& cvec1, const col_vector& cvec2);
friend complex scalar_product(const col_vector& cvec,  const row_vector& rvec);
*/

double  scalar_product()                        const;

complex scalar_product(const col_vector& cvec2) const;
complex scalar_product(const row_vector& rvec)  const;

std::string hdrString() const;

//std::vector<std::string> printStrings(const MxPrint& PFlgs) const;

/*
std::ostream& printcols(std::ostream& ost, int nc=4,int rc=1,int ne=0) const;
std::ostream& print(std::ostream& ostr, int full=0) const;
friend std::ostream& operator << (std::ostream& ostr, const col_vector& cvec);
friend std::istream& operator >> (std::istream& istr, col_vector& cvec);
*/

void ask();

};

