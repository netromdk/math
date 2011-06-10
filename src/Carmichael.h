#ifndef MATH_CARMICHAEL_H
#define MATH_CARMICHAEL_H

#include <gmp.h>

namespace Math {
  namespace Fac {
    /**
     * Checks whether n is a Carmichael number. That is, if it is
     * square-free and for all prime factors it holds that p-1 | n-1.
     */
    bool isCarmichael(const mpz_t n);
    
    bool isCarmichaelI(int n);
  }
}

#endif // MATH_CARMICHAEL_H
