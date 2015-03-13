#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <string>
#include "comparable.hpp"
#include "arithmetic.hpp"

// default template type
template <class T>
class Rational : public Comparable< Rational<T> > // TODO: look this up
{
 protected:

  T numer;
  T denom;

 public:

  Rational() : numer(0), denom(1) { };
  // const:     no "middle man" copy
  // ampersand: prevents null ptr or uninitialized input
  //            getting a pointer but within the body you can treat
  //            it as a value
  // (i.e. no dereferencing necessary)
  //
  // TODO: look at difference between "*" and "&" in this case
  //       C++ has new additional meanings to these
  Rational(const T& _numer) : numer(_numer), denom(1) { };
  Rational(const T& _numer, const T& _denom);

  inline T Numer() const { return numer; }
  inline T Denom() const { return denom; }

  // Operators
  inline bool operator< (const Rational<T>& q) const;
  inline bool operator> (const Rational<T>& q) const;
  operator double();

  std::string print(void) const;
};


//
// Constructors
//
template <class T>
Rational<T>::Rational(const T& _numer, const T& _denom)
:
numer(_numer),
denom(_denom)
{
  // use Euclidean algorithm to reduce to simplest terms
  T r;
}

//
// Operators
//

// double is within the scope of Rational (see above)
//
// don't need to specify return type of type conversion
// TODO: this can be generalized over the type. (float, double, long double)
template <class T>
Rational<T>::operator double()
{
  return static_cast<double>(numer) / static_cast<double>(denom);
}

template <class T>
Rational<T> operator* (const Rational<T>& p, const Rational<T>& q)
{
  Rational<T> val = {p.Numer() * q.Numer(), p.Denom() * q.Denom()};
  return val;
}

template <class T>
Rational<T> operator* (const Rational<T>& p, const T& q)
{
  Rational<T> val = {p.Numer() * q, p.Denom()};
  return val;
}

template <class T>
Rational<T> operator* (const T& p, const Rational<T>& q)
{
  Rational<T> val = {p * q.Numer(), q.Denom()};
  return val;
}

template <class T>
Rational<T> operator+ (const Rational<T>& p, const Rational<T>& q)
{
  Rational<T> val = {p.Numer() * q.Denom() + p.Denom() * q.Numer(),
                     p.Denom() * q.Denom()};
  return val;
}

template <class T>
Rational<T> operator+ (const Rational<T>& p, const T& q)
{
  Rational<T> val = {p.Numer() + q * p.Denom(), p.Denom()};
  return val;
}

template <class T>
Rational<T> operator+ (const T& p, const Rational<T>& q)
{
  Rational<T> val = {q.Numer() + p * q.Denom(), q.Denom()};
  return val;
}

template <class T>
inline bool Rational<T>::operator< (const Rational<T>& q) const
{
  return numer*q.denom < denom*q.numer;
}

template <class T>
inline bool Rational<T>::operator> (const Rational<T>& q) const
{
  return numer*q.denom > denom*q.numer;
}

template <class T>
std::string Rational<T>::print(void) const
{
  std::string s = std::to_string(numer) + '/' + std::to_string(denom);
  return s;
}


#endif // #ifndef RATIONAL_HPP
