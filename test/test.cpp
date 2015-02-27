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

  cout << (r < s) << endl;
  cout << (r > s) << endl;
  cout << (r == s) << endl;
  cout << (r <= s) << endl;
  cout << (r >= s) << endl;
  cout << (r == r) << endl;

  cout << ((1 * r) == r) << endl;
  cout << ((r * 1) == r) << endl;

  return 0;
}
