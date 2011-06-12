#include <gmp.h>

#include "Common.h"

namespace Math {
  bool isPropPrime(const mpz_t n) {
    return mpz_probab_prime_p(n, 10) > 0;
  }
  
  bool isPropPrime(int n) {
    mpz_t num;
    mpz_init(num);
    mpz_set_ui(num, n);
    bool propPrime = (mpz_probab_prime_p(num, 10) > 0);
    mpz_clear(num);
    return propPrime;
  }

  void dump(const mpz_t n, std::string msg, bool newline) {
    gmp_printf("%s%Zd%s", (msg.size() > 0 ? (msg + " ").c_str() : ""),
               n, (newline ? "\n" : ""));
  }

  bool mpz_less_than_p(const mpz_t *a, const mpz_t *b) {
    return mpz_cmp(*a, *b) < 0;    
  }
}
