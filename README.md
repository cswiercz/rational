# rational

A small C++11 library for working with rational numbers.

`rational` is an excuse to learn C++11-specific features and techniques. And, who knows, maybe we'll use it in our research as well...Eventually, you'll be able to compute with rational other things.

## Authors

* Daniel Shapero (danielshapero)
* Chris Swierczewski (cswiercz)

## Example

Here's a simple example of `rational` in action.

```c++
#include <iostream>
#include "rational.hpp"

using std::cout;
using std::endl;

int main(void)
{
  Rational<int> r = {1,2};
  Rational<int> s = {3,5};
  Rational<int> t = r + s;
  Rational<int> u = r*s;
  
  cout << "t = " << t.print() << endl;
  cout << "u = " << u.print() << endl;
}
```

Output:
```
t = 11/10
u = 3/10
```
