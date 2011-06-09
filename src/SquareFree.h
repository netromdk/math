#ifndef MATH_SQUARE_FREE_H
#define MATH_SQUARE_FREE_H

#include <gmp.h>

namespace Math {
  /**
   * Checks whether n is square-free. That is, it is divisible by no
   * perfect square.
   */
  bool isSquareFree(const mpz_t n);
  
  bool isSquareFreeI(int n);
}

#endif // MATH_SQUARE_FREE_H
