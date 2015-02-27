#ifndef COMPARABLE_HPP
#define COMPARABLE_HPP

template <class T>
class Comparable
{
public:
  // assuming that T already has > and <
  inline bool operator== (const T& other) const
  {
    return !((static_cast<const T&>(*this) > other) ||
             (static_cast<const T&>(*this) < other));
  }

  inline bool operator<= (const T& other) const
  {
    return !(static_cast<const T&>(*this) > other);
  }

  inline bool operator>= (const T& other) const
  {
    return !(static_cast<const T&>(*this) < other);
  }

  inline bool operator!= (const T& other) const
  {
    return !(static_cast<const T&>(*this) == other);
  }

};



#endif
