#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include <gmp.h>
#include <string>

namespace Math {
  bool isPropPrime(const mpz_t n);  
  bool isPropPrime(int n);
  void dump(const mpz_t n, std::string msg = "", bool newline = true);
  void dump(const mpf_t n, std::string msg = "", bool newline = true);  
  bool mpzLessThanP(const mpz_t *a, const mpz_t *b);
}

#endif // MATH_COMMON_H
