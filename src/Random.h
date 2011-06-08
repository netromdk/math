#ifndef MATH_RANDOM_H
#define MATH_RANDOM_H

#ifdef WIN32
#include <windows.h>
#include <Wincrypt.h>
#else
#include <fstream>
#endif

#include "PTypes.h"

namespace Math {
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
