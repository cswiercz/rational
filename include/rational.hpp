#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <string>

// default template type
template <class T>
class Rational
{
 protected:

  T numer;
  T denom;

 public:

  Rational() : numer(0), denom(1) { };
  // ampersand: prevents null ptr or uninitialized input
  // const:     no "middle man" copy
  // getting a pointer but within the body you can treat it as a value
  // (i.e. no dereferencing necessary)
  //
  // TODO: look at difference between "*" and "&" in this case
  //       C++ has new additional meanings to these
  Rational(const T& _numer) : numer(_numer), denom(1) { };
  Rational(const T& _numer, const T& _denom);

  // Operators
  Rational<T> operator* (const Rational<T>& q) const;
  inline bool operator== (const Rational<T>& q) const;
  inline bool operator< (const Rational<T>& q) const;
  inline bool operator> (const Rational<T>& q) const;
  inline bool operator<= (const Rational<T>& q) const;
  inline bool operator>= (const Rational<T>& q) const;

  std::string print(void) const;   // const disallows modification of the obj
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
  // TODO: reduce to simplest terms
}


//
// Operators
//
template <class T>
Rational<T> Rational<T>::operator* (const Rational<T>& q) const
{
  Rational<T> val = {numer*q.numer, denom*q.denom};
  return val;
}

template <class T>
inline bool Rational<T>::operator== (const Rational<T>& q) const
{
  return (numer == q.numer) && (denom == q.denom);
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
inline bool Rational<T>::operator<= (const Rational<T>& q) const
{
  return !(*this > q);
}

template <class T>
inline bool Rational<T>::operator>= (const Rational<T>& q) const
{
  return !(*this < q);
}

template <class T>
std::string Rational<T>::print(void) const
{
  std::string s = std::to_string(numer) + '/' + std::to_string(denom);
  return s;
}


#endif // #ifndef RATIONAL_HPP
