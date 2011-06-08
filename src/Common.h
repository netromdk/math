#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include <gmp.h>
#include <string>

namespace Math {
  bool isPropPrime(const mpz_t n);  
  bool isPropPrime(int n);
  void dump(mpz_t n, std::string msg = "", bool newline = true);
}

#endif // MATH_COMMON_H
