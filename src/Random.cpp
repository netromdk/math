#include <iostream>
using namespace std;

#include "Random.h"

namespace Math {
  void randRange(mpz_t num, const mpz_t max) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, Random().getInt64());
    mpz_urandomm(num, state, max);
    gmp_randclear(state);    
  }

  void randRange(mpz_t num, uint max) {
    mpz_t gmax;
    mpz_init(gmax);
    mpz_set_ui(gmax, max);
    randRange(num, gmax);
    mpz_clear(gmax);
  }

  void randRange(mpz_t num, const mpz_t min, const mpz_t max) {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, Random().getInt64());

    // Add one to max since it should first be from 0 to max (and not
    // max-1).
    mpz_t tmax;
    mpz_init(tmax);
    mpz_add_ui(tmax, max, 1); // tmax = max + 1
    
    mpz_urandomm(num, state, tmax);

    // While num < min or num > max get it into the interval.
    mpz_t tmp;
    mpz_init(tmp);
    while (mpz_cmp(num, min) < 0 || mpz_cmp(num, tmax) > 0) {
      if (mpz_cmp(num, min) < 0) {
        // Add (max - min) to num.
        mpz_sub(tmp, max, min);
        mpz_add(num, num, tmp);
      }

      if (mpz_cmp(num, tmax) > 0) {
        // num mod (tmax + 1).
        mpz_add_ui(tmp, tmax, 1);
        mpz_mod(num, num, tmp);
      }
    }

    mpz_clears(tmax, tmp, NULL);
    gmp_randclear(state);
  }
  
  void randRange(mpz_t num, uint min, uint max) {
    mpz_t gmin, gmax;
    mpz_inits(gmin, gmax, NULL);
    mpz_set_ui(gmin, min);    
    mpz_set_ui(gmax, max);
    randRange(num, gmin, gmax);
    mpz_clears(gmin, gmax, NULL);    
  }
  
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
