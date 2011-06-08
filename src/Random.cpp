#include <iostream>
using namespace std;

#include "Random.h"

namespace Math {
  Random::Random() {
#ifdef WIN32
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0)) {
      cerr << "Could not acquire PROV_RSA_FULL crypt context!" << endl;

      // Try creating a new default container.
      if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET)) {
        cerr << "Could not acquire even when creating a new default container!" << endl;
      }
    }
#else
    in.open("/dev/urandom");
    if (!in.is_open()) {
      cerr << "Could not open /dev/urandom!" << endl;
    }
#endif
  }

  Random::~Random() {
#ifdef WIN32
    CryptReleaseContext(hProv, 0);
#else
    in.close();
#endif
  }  

  uchar Random::getByte() {
#ifdef WIN32
    BYTE data[1];
    CryptGenRandom(hProv, 1, data);
    return data[0];
#else
    return in.get();
#endif
  }

  union char_int32 {
    char chars[4];
    ulong n;
  };

  ulong Random::getInt32() {
    char_int32 rand_int;  
#ifdef WIN32
    CryptGenRandom(hProv, 4, (BYTE*) rand_int.chars);
#else
    for (int i = 0; i < 4; i++) {
      rand_int.chars[i] = in.get();
    }
#endif  
    return rand_int.n;
  }

  union char_int64 {
    char chars[8];
    ull n;
  };
                                 
  ull Random::getInt64() {
    char_int64 rand_int; 
#ifdef WIN32
    CryptGenRandom(hProv, 8, (BYTE*) rand_int.chars);
#else 
    for (int i = 0; i < 8; i++) {
      rand_int.chars[i] = in.get();
    }
#endif
    return rand_int.n;
  }

  ulong Random::getRange(ulong start, ulong end) {
    // Ignore if invalid input.
    if (start > end) {
      return 0;
    }

    ulong res = getInt32();
    while (res < start || res > end) {
      if (res < start) {
        res += (end - start) / 4;
      }
      
      if (res > end) {
        res %= (end + 1);
      }
    }    
      
    return res;
  }
}
