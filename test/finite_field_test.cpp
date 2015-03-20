
#include <iostream>
#include "arithmetic.hpp"
#include "finite_field.hpp"

int main(int argc, char **argv)
{
  constexpr unsigned int p = 7;
  FP<p> x = 4, y = 2;

  std::cout << x << std::endl;
  std::cout << (x * y) << std::endl;
  std::cout << (x + y) << std::endl;
  std::cout << (x / y) << std::endl;
  std::cout << expt(x, p - 1) << std::endl;
  std::cout << expt(y, p - 1) << std::endl;

  return 0;
}
