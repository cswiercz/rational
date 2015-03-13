#include <iostream>
#include "rational.hpp"

using std::cout;
using std::endl;

int main(void)
{
  Rational<int> r = {1,2};
  cout << "r = " << r.print() << endl;

  Rational<int> s = {3,5};
  Rational<int> t = r*s;
  cout << "s = " << s.print() << endl;
  cout << "t = " << t.print() << endl;

  cout << endl << "Test Comparison:" << endl;
  cout << (r < s) << endl;
  cout << !(r > s) << endl;
  cout << !(r == s) << endl;
  cout << (r <= s) << endl;
  cout << !(r >= s) << endl;
  cout << (r == r) << endl;

  cout << endl << "Test Multiplication:" << endl;
  cout << ((1 * r) == r) << endl;
  cout << ((r * 1) == r) << endl;

  cout << endl << "Test Addition:" << endl;
  cout << (r + s == Rational<int>(11,10)) << endl;
  cout << (r + 1 == Rational<int>(3,2)) << endl;
  cout << (1 + r == Rational<int>(3,2)) << endl;

  return 0;
}
