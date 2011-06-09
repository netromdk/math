#include <cmath>

#include "Mod.h"
#include "PrimeTable.h"
#include "EulerTotient.h"
#include "Eratosthenes.h"

namespace Math {
  namespace Sieve {
    vector<int> eratosthenesRange(int max) {
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
    
    vector<int> eratosthenesRange(int min, int max) {
      // Don't use the segmented version in this case.
      if (min == 2 && max >= 4) {
        return eratosthenesRange(max);
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
