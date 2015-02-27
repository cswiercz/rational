#include <iostream>
#include "rational.hpp"

using std::cout;
using std::endl;

int main(void)
{
  Rational<int> r = {1,2};
  cout << r.print() << endl;

  Rational<int> s = {3,5};
  Rational<int> t = r*s;
  cout << s.print() << endl;
  cout << t.print() << endl;

  cout << endl << "Test Comparison:" << endl;
  cout << (r < s) << endl;
  cout << (r > s) << endl;
  cout << (r == s) << endl;
  cout << (r <= s) << endl;
  cout << (r >= s) << endl;
  cout << (r == r) << endl;

  cout << endl << "Test Multiplication:" << endl;
  cout << ((1 * r) == r) << endl;
  cout << ((r * 1) == r) << endl;

  cout << endl << "Test Addition:" << endl;
  cout << (r + s).print() << endl;
  cout << (r + 1).print() << endl;
  cout << (1 + r).print() << endl;

  return 0;
}
