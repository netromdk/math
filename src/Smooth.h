#ifndef MATH_SMOOTH_H
#define MATH_SMOOTH_H

#include <gmp.h>

namespace Math {
  namespace Fac {
    /**
     * Checks if n is B-smooth. Otherwise, if C is specified then that
     * will be the actual smoothness bound.
     */
    bool isSmooth(const mpz_t n, const mpz_t B, mpz_t *C = NULL);

    bool isSmoothI(int n, int B, int *C = NULL);
  }
}

#endif // MATH_SMOOTH_H
