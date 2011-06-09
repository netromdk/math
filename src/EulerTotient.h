#ifndef MATH_EULER_TOTIENT_H
#define MATH_EULER_TOTIENT_H

#include <gmp.h>

namespace Math {
  int totient(int n);
  void totient(const mpz_t n, mpz_t tot);
}

#endif // MATH_EULER_TOTIENT_H
