#include <cstddef>

#include "Smooth.h"
#include "PollardRho.h"

namespace Math {
  namespace Fac {
    bool isSmooth(const mpz_t n, const mpz_t B, mpz_t *C) {
      vector<mpz_t*> facs;
      pollardRhoFactor(n, facs);

      mpz_t max;
      mpz_init(max);
      mpz_set_ui(max, 0);
      for (size_t i = 0; i < facs.size(); i++) {
        mpz_t *fac = facs[i];
        if (mpz_cmp(*fac, max) > 0) {
          mpz_set(max, *fac);
        }
      }

      if (mpz_cmp(max, B) <= 0) {
        mpz_clear(max);
        return true;
      }

      if (C) mpz_set(*C, max);

      mpz_clear(max);
      return false;      
    }
    
    bool isSmoothI(int n, int B, int *C) {
      vector<int> facs;
      pollardRhoFactorI(n, facs);

      int max = 0;
      for (size_t i = 0; i < facs.size(); i++) {
        int fac = facs[i];
        if (fac > max) max = fac;
      }

      if (max <= B) return true;

      if (C) *C = max;
      return false;
    }
  }
}
