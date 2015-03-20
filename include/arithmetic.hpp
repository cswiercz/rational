#ifndef RATIONAL_ARITHMETIC_HPP
#define RATIONAL_ARITHMETIC_HPP

/*
  exponentiation by squaring - generic

  As long as the type T implements * and has an integer constructor
  then this will work.
*/
template <class T>
T expt(const T& x, unsigned int k)
{
  T y = 1;
  while (k > 0)
  {
    if (k % 2 == 0) {
      y = y * y;
      k /= 2;
    } else {
      y = y * x;
      k -= 1;
    }
  }

  return y;
}


/*
  gcd - generic

  As long as the type T implements "%" and "!= 0" then
  this will work.

  NOTE: just setting "T" to the return type results in an ambiguity
  error. looks for ways to make the code prefer
*/
template <class T>
typename std::enable_if<!std::is_integral<T>::value, T>::type
gcd(T a, T b)
{
  T r;
  while (b != 0)
    {
      r = a % b;
      a = b;
      b = r;
    }
  return a;
}

/*
  gcd - for integral types

  Specialized for integral types. This is because c++ modulus "%" allows
  for negative returns with "%".
*/
template <class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T a,T b)
{
  T r;

  // because c++ modulus "%" allows negative remainder, we need to make
  // sure that b is positive.
  b = b > 0 ? b : -b;

  // swap arguments if a < b
  if (a < b)
    {
      r = a;
      a = b;
      b = r;
    }

  // euclidean algorithm for integral types
  while (b != 0)
    {
      r = a % b;
      a = b;
      b = r;
    }
  return a;
}

#endif // #ifndef RATIONAL_ARITHMETIC_HPP
