#include <iostream> //rem
using namespace std;//rem

#include <cmath>

#include "Mod.h"
#include "PrimeTable.h"
#include "EulerTotient.h"
#include "Eratosthenes.h"

namespace Math {
  namespace Sieve {
    vector<mpz_t*> eratosthenesRange(const mpz_t max) {
      vector<mpz_t*> buf;
      mpz_t i, j, p, tmp;
      mpz_inits(i, j, p, tmp, NULL);
      
      // Loop 2 -> max-1
      for (mpz_set_ui(i, 2); mpz_cmp(i, max) < 0; mpz_add_ui(i, i, 1)) {
        mpz_t *tmp0 = new mpz_t[1];
        mpz_init(*tmp0);
        mpz_set(*tmp0, i);
        buf.push_back(tmp0);
      }

      // Loop p=2 -> p*p <= max
      for (mpz_set_ui(p, 2), mpz_set_ui(j, 0);
           mpz_mul(tmp, p, p), mpz_cmp(tmp, max) <= 0;) {
        // Loop i=j+p -> i < buf.size()
        for (mpz_add(tmp, j, p); mpz_cmp_ui(tmp, buf.size()) < 0;
             mpz_add(tmp, tmp, p)) {
          // buf[i] = 0
          mpz_set_ui(*buf[mpz_get_ui(tmp)], 0);
        }

        // Loop i=j+1 -> i < buf.size()        
        for (mpz_add_ui(tmp, j, 1); mpz_cmp_ui(tmp, buf.size()) < 0;
             mpz_add_ui(tmp, tmp, 1)) {
          // If buf[i] > 0
          if (mpz_cmp_ui(*buf[mpz_get_ui(tmp)], 0) > 0) {
            // p = buf[i]
            mpz_set(p, *buf[mpz_get_ui(tmp)]);
            mpz_set(j, tmp);
            break;
          }
        }
      }

      vector<mpz_t*> res;
      
      // Put all the found prime numbers into the vector.
      for (size_t i = 0; i < buf.size(); i++) {
        // If buf[i] > 0
        if (mpz_cmp_ui(*buf[i], 0) > 0) {
          res.push_back(buf[i]);
        }

        // Clean up the ones we don't need.
        else {
          mpz_clear(*buf[i]);
          delete[] buf[i];
        }
      }
      
      buf.clear();
      mpz_clears(i, j, p, tmp, NULL);
      return res;
    }
    
    vector<int> eratosthenesRangeI(int max) {
      vector<int> buf;
      for (int i = 2; i < max; i++) {
        buf.push_back(i);
      }

      for (int p = 2, j = 0; p * p <= max;) {
        for (size_t i = j + p; i < buf.size(); i += p) {
          buf[i] = 0;
        }
    
        for (size_t i = j + 1; i < buf.size(); i++) {
          if (buf[i] > 0) {
            p = buf[i];
            j = i;
            break;
          }
        }
      }

      vector<int> res;

      // Put all the found prime numbers into the vector.
      for (size_t i = 0; i < buf.size(); i++) {
        if (buf[i] > 0) {
          res.push_back(buf[i]);
        }
      }

      return res;      
    }
    
    vector<int> eratosthenesRangeI(int min, int max) {
      // Don't use the segmented version in this case.
      if (min == 2 && max >= 4) {
        return eratosthenesRangeI(max);
      }
      
      int P = floor(sqrt(max));
      int tot = totient(P);

      // Calculate offsets.
      vector<int> q;
      for (int i = 0; i < tot; i++) {
        int pk = PRIME_TABLE[i + 1]; // Skip 2 because it is even.
        int qk = ceil(-1.0 * ((double) (min + 1 + pk) / 2.0));

        qk = mod(qk, pk);
        q.push_back(qk);
      }

      // Find B such that B | (max - min).
      int diff = max - min, B = floor(sqrt(diff)) - 1;
      while (mod(diff, ++B) != 0);

      // Process blocks and strike out the multiples which are not
      // primes.
      vector<int> b(B, 1), res;
      int T = min;
      while (T < max) {
        // This loop is essentially not required the first time.
        for (int j = 0; j < B; j++) {
          b[j] = 1;
        }

        for (int k = 0; k < tot; k++) {
          int pk = PRIME_TABLE[k + 1];
          for (int j = q[k]; j < B; j += pk) {
            b[j] = 0;
          }

          q[k] = mod(q[k] - B, pk);
        }

        for (int j = 0; j < B; j++) {
          if (b[j] == 1) {
            // Found next prime...
            int p = T + (2 * j) + 1;
            if (p <= max) {
              res.push_back(p);
            }
          }
        }

        T += 2 * B;
      }

      return res;      
    }
  }
}
