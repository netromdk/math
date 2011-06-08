#ifndef MATH_POLLARD_RHO_H
#define MATH_POLLARD_RHO_H

#include <gmp.h>

namespace Math {
  namespace Fac {
    namespace {
      void func(mpz_t r, const mpz_t x, const mpz_t a, const mpz_t n);
      int funcI(int x, int a, int n);
    }

    /**
     * Finds a nontrivial factor of composite number n of arbitrary
     * size and writes the result to f.
     */
    void pollardRho(const mpz_t n, mpz_t f);    

    /**
     * Finds a nontrivial factor of composite number n.
     */
    int pollardRhoI(int n);
  }
}

#endif // MATH_POLLARD_RHO_H
