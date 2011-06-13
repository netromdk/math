#ifndef MATH_EXPONENTIAL_H
#define MATH_EXPONENTIAL_H

#include <gmp.h>

#include "PTypes.h"

namespace Math {
  void exp(uint n, mpf_t r);
  void exp(uint n, mpz_t r);    
  void exp(const mpz_t n, mpz_t r);
}

#endif // MATH_EXPONENTIAL_H
