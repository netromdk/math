#include "Mod.h"
#include "GCD.h"
#include "Random.h"
#include "Common.h"
#include "PollardRho.h"

namespace Math {
  namespace Fac {
    namespace {
      void pollardRhoFactor0(mpz_t n, vector<mpz_t*> &facs) {
        if (isPropPrime(n)) {
          mpz_t *tmp = new mpz_t[1];
          mpz_init(*tmp);
          mpz_set(*tmp, n);
          facs.push_back(tmp);
          return;
        }

        mpz_t *g = new mpz_t[1];
        mpz_init(*g);
        pollardRho(n, *g);
        facs.push_back(g);

        mpz_divexact(n, n, *g);
        pollardRhoFactor0(n, facs);
      }
      
      void func(mpz_t r, const mpz_t x, const mpz_t a, const mpz_t n) {
        mpz_mul(r, x, x);
        mpz_add(r, r, a);
        mpz_mod(r, r, n);
      }
      
      int funcI(int x, int a, int n) {
        return mod(x * x + a, n);
      }
    }

    void pollardRhoFactor(const mpz_t n, vector<mpz_t*> &facs) {
      mpz_t tmp;
      mpz_init(tmp);
      mpz_set(tmp, n);
      pollardRhoFactor0(tmp, facs);
      mpz_clear(tmp);
    }

    void pollardRho(const mpz_t n, mpz_t f) {
      // Return n as the factor if it's a probable-prime.      
      if (isPropPrime(n)) {
        mpz_set(f, n);
        return;
      }

      mpz_t a, s, g, u, v, one, zero, tmp;
      mpz_inits(a, s, g, u, v, one, zero, tmp, NULL);
      mpz_set_ui(zero, 0);      
      mpz_set_ui(one, 1);
      mpz_sub_ui(tmp, n, 3);
      randRange(a, one, tmp); // a in [1, n - 3]

      mpz_sub_ui(tmp, n, 1);      
      randRange(s, zero, tmp); // s in [0, n - 1]

      // u = v = s
      mpz_set(u, s);
      mpz_set(v, s);

      do {
        func(u, u, a, n);
        func(v, v, a, n);
        func(v, v, a, n);

        // g = gcd((u - v) mod n, n)
        mpz_sub(tmp, u, v);
        mpz_mod(tmp, tmp, n);
        mpz_gcd(g, tmp, n);
      } while (mpz_cmp(g, one) == 0);

      // Failed: g == n
      if (mpz_cmp(g, n) == 0) {
        mpz_clears(a, s, g, u, v, one, zero, tmp, NULL);
        pollardRho(n, f);
      }

      // Found factor.
      mpz_set(f, g);
      mpz_clears(a, s, g, u, v, one, zero, tmp, NULL);
    }
  
    int pollardRhoI(int n) {
      if (isPropPrime(n)) return n;
      
      Random rnd;
      int a = rnd.getRange(1, n - 3),
        s = rnd.getRange(0, n - 1);    

      int g, u, v;    
      u = v = s;
    
      do {
        u = funcI(u, a, n);
        v = funcI(funcI(v, a, n), a, n);
        g = gcd(mod(u - v, n), n);
      } while (g == 1);

      if (g == n) {
        return pollardRhoI(n);
      }
    
      return g;
    }
  }
}
