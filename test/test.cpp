#include <iostream>
#include "rational_comparable.hpp"

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

  cout << (r < s) << endl;
  cout << (r > s) << endl;
  cout << (r == s) << endl;
  cout << (r <= s) << endl;
  cout << (r >= s) << endl;
  cout << (r == r) << endl;

  return 0;
}
