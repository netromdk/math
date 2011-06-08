#ifdef WIN32
#include <windows.h>
#include <Wincrypt.h>
#else
#include <fstream>
#endif

#ifndef MATH_RANDOM_H
#define MATH_RANDOM_H

namespace Math {
  class Random {
  public:
    Random();
    ~Random();

    unsigned char getByte();
    unsigned long getInt32();
    unsigned long long getInt64();  

  private:
#ifdef WIN32
    HCRYPTPROV hProv;
#else
    std::ifstream in;
#endif  
  };
}

#endif // MATH_RANDOM_H
