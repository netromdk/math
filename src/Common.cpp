#include <gmp.h>

#include "Common.h"

namespace Math {
  bool isPropPrime(int n) {
    mpz_t num;
    mpz_init(num);
    mpz_set_ui(num, n);
    bool propPrime = (mpz_probab_prime_p(num, 10) > 0);
    mpz_clear(num);
    return propPrime;
  }
}
