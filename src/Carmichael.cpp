#include "Carmichael.h"
#include "SquareFree.h"
#include "PollardRho.h"

namespace Math {
  namespace Fac {
    bool isCarmichael(const mpz_t n) {
      if (!isSquareFree(n)) return false;

      vector<mpz_t*> facs;
      pollardRhoFactor(n, facs);

      mpz_t tmp, tmp2;
      mpz_inits(tmp, tmp2, NULL);
      mpz_sub_ui(tmp, n, 1);
      
      for (size_t i = 0; i < facs.size(); i++) {
        mpz_sub_ui(tmp2, *facs[i], 1);
        mpz_mod(tmp2, tmp, tmp2);
        if (mpz_cmp_ui(tmp2, 0) != 0) {
          mpz_clears(tmp, tmp2, NULL);
          for (size_t j = 0; j < facs.size(); j++) {
            mpz_clear(*facs[j]);
            delete[] facs[j];
          }
          return false;
        }

        mpz_clear(*facs[i]);
        delete[] facs[i];
      }

      mpz_clears(tmp, tmp2, NULL);
      return true;
    }
    
    bool isCarmichaelI(int n) {
      if (!isSquareFreeI(n)) return false;

      vector<int> facs;
      pollardRhoFactorI(n, facs);

      for (size_t i = 0; i < facs.size(); i++) {
        if ((n-1) % (facs[i]-1) != 0) return false;
      }
      
      return true;
    }
  }
}
