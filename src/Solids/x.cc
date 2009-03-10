#include <gamma.h>
#include "Powder.cc"

int main()
  {
  Powder P;
  cout << P;
  P.Spherical(200, 1, false);
  P.print(cout, 200);

  P.Cheng(15);
  cout << P;
  }
