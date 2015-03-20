
#ifndef FINITE_FIELD_HPP
#define FINITE_FIELD_HPP

#include <iostream>

#include "field.hpp"
#include "arithmetic.hpp"

template <unsigned int p>
class FP : public Field< FP<p> >
{
protected:
  unsigned int val;

public:
  FP(const unsigned int& x);
  inline FP<p> operator+(const FP<p>& y) const;
  inline FP<p> operator-(const FP<p>& y) const;
  inline FP<p> operator*(const FP<p>& y) const;
  inline FP<p> operator^(const unsigned int& k) const;
  inline FP<p> operator/(const FP<p>& y) const;
  inline operator int() const;

};


template <unsigned int p>
FP<p>::FP(const unsigned int& x) : val(x % p) { }


template <unsigned int p>
FP<p> FP<p>::operator+(const FP<p>& y) const
{
  return FP<p>(val + y.val);
}


template <unsigned int p>
FP<p> FP<p>::operator*(const FP<p>& y) const
{
  return FP<p>(val * y.val);
}


template <unsigned int p>
FP<p> FP<p>::operator-(const FP<p>& y) const
{
  return FP<p>(val - y.val + p);
}


template <unsigned int p>
FP<p> FP<p>::operator/(const FP<p>& y) const
// Fermat's little theorem: x^{p - 1} = 1 mod p
{
  return (*this) * expt(y, p - 2);
}


template <unsigned int p>
FP<p>::operator int() const
{
  return (*this).val;
}



#endif
