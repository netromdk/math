#include "GCD.h"
#include "EulerTotient.h"

namespace Math {
  int totient(int n) {
    int coprimes = 0;
  
    for (int i = 1; i <= n; i++) {
      if (gcd(i, n) == 1) {
        coprimes++;
      }
    }
  
    return coprimes;    
  }
}
