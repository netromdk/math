#include "SquareFree.h"

namespace Math {
  bool isSquareFree(const mpz_t n) {
    mpz_t d, p, tmp;
    mpz_inits(d, p, tmp, NULL);
    
    for (mpz_set_ui(d, 2);; mpz_add_ui(d, d, 1)) {
      mpz_mul(p, d, d);
      if (mpz_cmp(p, n) >= 0) {
        mpz_clears(d, p, tmp, NULL);          
        return true;
      }

      mpz_mod(tmp, n, p);
      if (mpz_cmp_ui(tmp, 0) == 0) {
        mpz_clears(d, p, tmp, NULL);          
        return false;        
      }
    }
  }
  
  bool isSquareFreeI(int n) {
    for (int d = 2, p;; d++) {
      p = d * d;
      if (p >= n) return true;
      if (n % p == 0) return false;      
    }
  }
}
