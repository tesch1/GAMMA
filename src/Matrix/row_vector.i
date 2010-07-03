// row_vector.i
// Swig interface file.

%{
#include "Matrix/row_vector.h"
%}

%include "std_vector.i"
%include "std_string.i"


%rename(__add__)  row_vector::operator+;
%rename(__iadd__) row_vector::operator+=;
%rename(__sub__)  row_vector::operator-;
%rename(__isub__) row_vector::operator-=;

%rename(__mul__)  row_vector::operator*;
%rename(__imul__) row_vector::operator*=;

//class col_vector;

class row_vector : public matrix
{

//friend class col_vector;


public:


row_vector( );
row_vector(int i);
row_vector(int i, const complex& z);
row_vector(int i, double d);
row_vector(const row_vector& rvec);
//row_vector(const matrix& mx);

~row_vector();

//void     operator = (const row_vector& rvec);

//void     operator = (const col_vector& cvec);
//void     operator = (const matrix& mx);

complex& operator() (int i);
complex  get(int i)   const;

double   getRe(int i) const;
double   getIm(int i) const;

void     put(const complex& z, int i);

int elements( ) const;
int size( )     const;

//friend row_vector operator * (const complex& z, const row_vector& rvec);
//friend row_vector operator * (double         d, const row_vector& rvec);

row_vector operator + (const row_vector& rvec) const;
//row_vector operator + (const matrix&     mx)   const;

row_vector operator - (const row_vector& rvec) const;
//row_vector operator - (const matrix&     mx)   const;

//complex    operator * (const row_vector& rvec) const; // this causes a c++ error.
complex    operator * (const col_vector& cvec) const;

//row_vector operator * (const matrix& mx)       const;

row_vector operator * (const complex& z)       const;
row_vector operator * (double d)               const;
//row_vector operator / (const complex& z)       const;
//row_vector operator / (double d)               const;

row_vector& operator += (const row_vector& rvec1);
//void operator += (const matrix& mx);

row_vector& operator -= (const row_vector& rvec1);
//void operator -= (const matrix& mx);

row_vector& operator *= (      double d);
row_vector& operator *= (const complex& z);
//void operator /= (      double d);
//void operator /= (const complex& z);

/*
friend col_vector adjoint(const     row_vector& rvec);
friend col_vector transpose(const   row_vector& rvec);
friend complex    trace(const       row_vector& rvec);
*/

row_vector differential() const;

double           norm()              const;
complex          sum()               const;
double           maxRe()             const;
double           maxIm()             const;
complex          maxZ()              const;
double           minRe()             const;
double           minIm()             const;
complex          minZ()              const;
int              max(int type=0)     const;
int              min(int type=0)     const;
void             flip();
complex          sum(int st, int ne) const;
void             zero();

std::vector<int> sort(int type=0)    const;

/*
friend row_vector FFT(const  row_vector& rvec);
friend row_vector IFFT(const row_vector& rvec);

friend int operator==(const row_vector& rvec1, const row_vector& rvec2);
friend int operator!=(const row_vector& rvec1, const row_vector& rvec2);

friend row_vector product(const row_vector& rvec1, const row_vector& rvec2);
friend row_vector product(const row_vector& rvec,        col_vector& cvec);
*/

row_vector product()                        const;
row_vector product(const row_vector& cvec2) const;
row_vector product(const col_vector& rvec)  const;

/*
friend double  scalar_product(const row_vector& rvec);
friend complex scalar_product(const row_vector& rvec1, const row_vector& rvec2);
friend complex scalar_product(const row_vector& rvec,  const col_vector& cvec);
*/

double  scalar_product()                        const;
complex scalar_product(const row_vector& cvec2) const;
complex scalar_product(const col_vector& rvec)  const;

std::string              hdrString() const;

//std::vector<std::string> printStrings(const MxPrint& PFlgs) const;

/*
       std::ostream& printcols(std::ostream& ost, int nc=4,int rc=1,int ne=0) const;
       std::ostream& print(std::ostream& ostr, int full=0) const;
friend std::ostream& operator << (std::ostream& ostr, const row_vector& rvec);
friend std::istream& operator >> (std::istream& istr, row_vector& rvec);
*/

enum { SMIS = 0, SIEMENS, SIEMENS_NOHDR, PLAIN_ASCII, ASCII_MT_DEG, SVS };

static row_vector read_pulse (const std::string filename, const int PulseFmt);

void ask();
};

