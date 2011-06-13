#include <sstream>
#include <iostream>//rem
using namespace std;

#include "Log.h"
#include "Constants.h"

namespace Math {
  namespace {
    int digits(const mpf_t n, int b) {
      mp_exp_t exp;
      char *str = mpf_get_str(NULL, &exp, b, 0, n);
      delete[] str;
      return exp - 1;
    }
  }

  void log(const mpf_t n, mpf_t l, mpf_t b) {
    // l = log10(n)/log10(b)
    mpf_t tmp, tmp2;
    mpf_inits(tmp, tmp2, NULL);
    log10(n, tmp);
    log10(b, tmp2);
    mpf_div(l, tmp, tmp2);
    mpf_clears(tmp, tmp2, NULL);            
  }  
  
  void ln(const mpf_t n, mpf_t l) {
    // l = log10(n)/log10(e)
    mpf_t e;
    mpf_init(e);
    eCnst(e);
    log(n, l, e);
    mpf_clear(e);
  } 

  void log2(const mpf_t n, mpf_t l) {
    // l = log10(n)/log10(2)
    mpf_t two;
    mpf_init(two);
    mpf_set_ui(two, 2);
    log(n, l, two);
    mpf_clear(two);
  }  

  void log10(const mpf_t n, mpf_t l, int prec) {
    // Approximate log10 to prec digits.
    // Ref.: http://www.brics.dk/RS/04/17/BRICS-RS-04-17.pdf
    mpf_t tmp, tmp2;
    mpf_inits(tmp, tmp2, NULL);
    mpf_set(tmp, n);

    stringstream res;
    for (int i = 0; i < prec + 1; i++) { 
      int d = digits(tmp);

      // m_(i+1) = (m_i / (10 ^ a_i)) ^ 10 
      mpf_set_ui(tmp2, 10);
      mpf_pow_ui(tmp2, tmp2, d);
      mpf_div(tmp2, tmp, tmp2);
      mpf_pow_ui(tmp, tmp2, 10);

      res << d;      
      if (i == 0) res << ".";
    }

    mpf_set_str(l, res.str().c_str(), 10);
    mpf_clears(tmp, tmp2, NULL);
  }

  void log(const mpz_t n, mpz_t l, mpz_t b) {
    mpf_t tmp, tmp2, tmp3;
    mpf_inits(tmp, tmp2, tmp3, NULL);
    mpf_set_z(tmp, n);
    mpf_set_z(tmp3, b);    
    log(tmp, tmp2, tmp3);
    mpz_set_f(l, tmp2);
    mpf_clears(tmp, tmp2, tmp3, NULL);            
  }
  
  void ln(const mpz_t n, mpz_t l) {
    mpf_t tmp, tmp2;
    mpf_inits(tmp, tmp2, NULL);
    mpf_set_z(tmp, n);
    ln(tmp, tmp2);
    mpz_set_f(l, tmp2);
    mpf_clears(tmp, tmp2, NULL);            
  }
  
  void log2(const mpz_t n, mpz_t l) {
    mpf_t tmp, tmp2;
    mpf_inits(tmp, tmp2, NULL);
    mpf_set_z(tmp, n);
    log2(tmp, tmp2);
    mpz_set_f(l, tmp2);
    mpf_clears(tmp, tmp2, NULL);        
  }
  
  void log10(const mpz_t n, mpz_t l, int prec) {
    mpf_t tmp, tmp2;
    mpf_inits(tmp, tmp2, NULL);
    mpf_set_z(tmp, n);
    log10(tmp, tmp2, prec);
    mpz_set_f(l, tmp2);
    mpf_clears(tmp, tmp2, NULL);    
  }
}
