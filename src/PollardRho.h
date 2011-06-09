#ifndef MATH_POLLARD_RHO_H
#define MATH_POLLARD_RHO_H

#include <gmp.h>
#include <vector>
using namespace std;

namespace Math {
  namespace Fac {
    namespace {
      void pollardRhoFactor0(mpz_t n, vector<mpz_t*> &facs);    
      void func(mpz_t r, const mpz_t x, const mpz_t a, const mpz_t n);
      int funcI(int x, int a, int n);
    }

    /**
     * Finds the prime factorization of n and puts them in the vector
     * facs.
     */
    void pollardRhoFactor(const mpz_t n, vector<mpz_t*> &facs);        

    /**
     * Finds a nontrivial factor of composite number n of arbitrary
     * size and writes the result to f.
     */
    void pollardRho(const mpz_t n, mpz_t f);

    /**
     * Finds the prime factorization of n.
     */
    void pollardRhoFactorI(int n, vector<int> &facs);            

    /**
     * Finds a nontrivial factor of composite number n.
     */
    int pollardRhoI(int n);
  }
}

#endif // MATH_POLLARD_RHO_H
