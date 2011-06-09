#include "GCD.h"
#include "EulerTotient.h"

namespace Math {
  int totient(int n) {
    int coprimes = 0;
  
    for (int i = 1; i <= n; i++) {
      if (gcd(i, n) == 1) {
        coprimes++;
      }
    }
  
    return coprimes;    
  }

  void totient(const mpz_t n, mpz_t tot) {
    mpz_t i, tmp;
    mpz_inits(i, tmp, NULL);
    mpz_set_ui(tot, 0);

    for (mpz_set_ui(i, 1); mpz_cmp(i, n) <= 0; mpz_add_ui(i, i, 1)) {
      mpz_gcd(tmp, i, n);
      if (mpz_cmp_ui(tmp, 1) == 0) {
        mpz_add_ui(tot, tot, 1);
      }
    }

    mpz_clears(i, tmp, NULL);
  }
}
