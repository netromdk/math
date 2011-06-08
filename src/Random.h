#ifndef MATH_RANDOM_H
#define MATH_RANDOM_H

#ifdef WIN32
#include <windows.h>
#include <Wincrypt.h>
#else
#include <fstream>
#endif

#include <gmp.h>

#include "PTypes.h"

namespace Math {
  /**
   * Generates a random number between 0 and max-1 inclusive.
   */
  void randRange(mpz_t num, const mpz_t max);
  void randRange(mpz_t num, uint max);

  /**
   * Generates a random number between min and max, both inclusive.
   */
  void randRange(mpz_t num, const mpz_t min, const mpz_t max);
  void randRange(mpz_t num, uint min, uint max);      
  
  class Random {
  public:
    Random();
    ~Random();

    uchar getByte();
    ulong getInt32();
    ull getInt64();

    ulong getRange(ulong start, ulong end);

  private:
#ifdef WIN32
    HCRYPTPROV hProv;
#else
    std::ifstream in;
#endif  
  };
}

#endif // MATH_RANDOM_H
