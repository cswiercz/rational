
#ifndef FIELD_HPP
#define FIELD_HPP

/* This class is a mixin representing the algebraic notion of a `field`, i.e.
 * an algebraic structure on which addition, multiplication, subtraction and
 * division are well-defined operations obeying the usual commutative,
 * distributive, and associative laws.
 */

template <class T>
class Field
{
public:
  inline T operator+(const T& y) const
  {
    return static_cast<const T&>(*this) + y;
  }

  inline T operator-(const T& y) const
  {
    return static_cast<const T&>(*this) - y;
  }

  inline T operator*(const T& y) const
  {
    return static_cast<const T&>(*this) * y;
  }

  inline T operator/(const T& y) const
  {
    return static_cast<const T&>(*this) / y;
  }

};


#endif
