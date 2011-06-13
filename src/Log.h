#ifndef MATH_LOGARITHM_H
#define MATH_LOGARITHM_H

#include <gmp.h>

namespace Math {
  namespace {
    /**
     * Computes the number of digits left of the decimal point minus
     * one using base b (10 pr. default).
     */
    int digits(const mpf_t n, int b = 10);
  }

  /**
   * Calculate the logarithm of n using base b and save it in l.
   */
  void log(const mpf_t n, mpf_t l, mpf_t b);

  /**
   * Calculate the natural logarithm of n and save it in l.
   */
  void ln(const mpf_t n, mpf_t l);

  /**
   * Calculate the binary logarithm of n and save it in l.
   */
  void log2(const mpf_t n, mpf_t l);

  /**
   * Calculate the logarithm of n base 10 and save it in l. prec
   * denotes the decimal points of accuracy to calculate.
   */  
  void log10(const mpf_t n, mpf_t l, int prec = 32);

  void log(const mpz_t n, mpz_t l, mpz_t b);
  void ln(const mpz_t n, mpz_t l);  
  void log2(const mpz_t n, mpz_t l);
  void log10(const mpz_t n, mpz_t l, int prec = 32);
}

#endif // MATH_LOGARITHM_H
