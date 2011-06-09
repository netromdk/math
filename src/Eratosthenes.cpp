#include <iostream> //rem
using namespace std;//rem

#include <cmath>

#include "Mod.h"
#include "PrimeTable.h"
#include "EulerTotient.h"
#include "Eratosthenes.h"

namespace Math {
  namespace Sieve {
    void eratosthenesRange(const mpz_t max, vector<mpz_t*> &primes) {
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

      // Put all the found prime numbers into the vector.
      for (size_t i = 0; i < buf.size(); i++) {
        // If buf[i] > 0
        if (mpz_cmp_ui(*buf[i], 0) > 0) {
          primes.push_back(buf[i]);
        }

        // Clean up the ones we don't need.
        else {
          mpz_clear(*buf[i]);
          delete[] buf[i];
        }
      }
      
      buf.clear();
      mpz_clears(i, j, p, tmp, NULL);
    }

    void eratosthenesRange(const mpz_t min, const mpz_t max,
                           vector<mpz_t*> &primes) {
      if (mpz_cmp_ui(min, 2) == 0 && mpz_cmp_ui(max, 4) >= 0) {
        eratosthenesRange(max, primes);
        return;
      }

      mpz_t P, tot;
      mpz_inits(P, tot, NULL);
      mpz_sqrt(P, max);
      totient(P, tot);

      // Calculate offsets.
      vector<mpz_t*> q;
      mpz_t i, tmp;
      mpz_inits(i, tmp, NULL);
      for (mpz_set_ui(i, 0); mpz_cmp(i, tot) < 0; mpz_add_ui(i, i, 1)) {
         // Skip 2 because it is even.
        int pk = PRIME_TABLE[mpz_get_ui(i) + 1];

        // tmp = min + pk + 1
        mpz_add_ui(tmp, min, pk);
        mpz_add_ui(tmp, tmp, 1);

        // tmp = ceil(-1 * (tmp / 2))
        mpz_cdiv_q_ui(tmp, tmp, 2);
        mpz_mul_si(tmp, tmp, -1);
        mpz_mod_ui(tmp, tmp, pk);

        mpz_t *tmp_ = new mpz_t[1];
        mpz_init(*tmp_);
        mpz_set(*tmp_, tmp);
        q.push_back(tmp_);
      }

      // Find B such that B | (max - min).
      mpz_sub(tmp, max, min);
      mpz_t B, tmp2;
      mpz_inits(B, tmp2, NULL);
      mpz_sqrt(B, tmp);
      mpz_sub_ui(B, B, 1);
      while (true) {
        mpz_add_ui(B, B, 1);
        mpz_mod(tmp2, tmp, B);
        if (mpz_cmp_ui(tmp2, 0) == 0) {
          break;
        }
      }

      // Process blocks and strike out the multiples which are not
      // primes.
      vector<mpz_t*> b;
      mpz_t T, tmp3;
      mpz_inits(T, tmp3, NULL);
      mpz_set(T, min);
      while (mpz_cmp(T, max) < 0) {
        for (mpz_set_ui(tmp, 0); mpz_cmp(tmp, B) < 0; mpz_add_ui(tmp, tmp, 1)) {
          mpz_t *tmp_ = new mpz_t[1];
          mpz_init(*tmp_);
          mpz_set_ui(*tmp_, 1);
          b.push_back(tmp_);
        }

        for (mpz_set_ui(tmp, 0); mpz_cmp(tmp, tot) < 0; mpz_add_ui(tmp, tmp, 1)) {
          int pk = PRIME_TABLE[mpz_get_ui(tmp) + 1];
          // j = q[k]
          mpz_set(tmp2, *q[mpz_get_ui(tmp)]);
          for (; mpz_cmp(tmp2, B) < 0; mpz_add_ui(tmp2, tmp2, pk)) {
            // b[j] = 0
            mpz_set_ui(*b[mpz_get_ui(tmp2)], 0);
          }

          // q[k] = mod(q[k] - B, pk);
          mpz_sub(tmp3, *q[mpz_get_ui(tmp)], B);
          mpz_mod_ui(*q[mpz_get_ui(tmp)], tmp3, pk);
        }

        for (mpz_set_ui(tmp, 0); mpz_cmp(tmp, B) < 0; mpz_add_ui(tmp, tmp, 1)) {
          // b[j] == 1
          if (mpz_cmp_ui(*b[mpz_get_ui(tmp)], 1) == 0) {
            // Found next prime...

            // p = T + 1 + (2 * j)
            mpz_add_ui(tmp2, T, 1);
            mpz_mul_ui(tmp3, tmp, 2);
            mpz_add(tmp2, tmp2, tmp3);

            if (mpz_cmp(tmp2, max) <= 0) {
              mpz_t *tmp_ = new mpz_t[1];
              mpz_init(*tmp_);
              mpz_set(*tmp_, tmp2);
              primes.push_back(tmp_);
            }
          }
        }

        // T += 2 * B
        mpz_mul_ui(tmp3, B, 2);
        mpz_add(T, T, tmp3);
      }

      // Clean up b and q vector.
      for (size_t j = 0; j < b.size(); j++) {
        mpz_clear(*b[j]);
        delete[] b[j];
      }

      for (size_t j = 0; j < q.size(); j++) {
        mpz_clear(*q[j]);
        delete[] q[j];
      }      

      mpz_clears(P, tot, i, B, tmp, tmp2, T, tmp3, NULL);
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
