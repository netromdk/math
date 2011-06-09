#ifndef MATH_ERATOSTHENES_H
#define MATH_ERATOSTHENES_H

#include <vector>
using namespace std;

namespace Math {
  namespace Sieve {
    /**
     * Finds the primes in the range [2, max]. It is assumed that max
     * is even and >= 4.
     */
    vector<int> eratosthenesRange(int max);
    
    /**
     * Finds the primes in the range [min, max]. It is assumed that
     * min, max are even, with max > min, min > P = floor(sqrt(max)),
     * B | (max - min). Requires a table of pi(P) primes, p_k <= P.
     *
     * Segmented version if !(min == 2 && max >= 4).
     */    
    vector<int> eratosthenesRange(int min, int max);
  }
}

#endif // MATH_ERATOSTHENES_H