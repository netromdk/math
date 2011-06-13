#include "Exp.h"
#include "Constants.h"

namespace Math {
  void exp(uint n, mpf_t r) {
    mpf_t tmp;
    mpf_init(tmp);
    eCnst(tmp); // set E.
    mpf_pow_ui(r, tmp, n); // e^n
    mpf_clear(tmp);
  }

  void exp(uint n, mpz_t r) {
    mpf_t tmp;
    mpf_init(tmp);
    exp(n, tmp);
    mpz_set_f(r, tmp);
    mpf_clear(tmp);
  }
  
  void exp(const mpz_t n, mpz_t r) {
    mpf_t tmp;
    mpf_init(tmp);
    exp(mpz_get_ui(n), tmp);
    mpz_set_f(r, tmp);
    mpf_clear(tmp);
  }
}
