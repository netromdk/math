#include "GCD.h"

namespace Math {
  int gcd(int a, int b) {
    for (;;) {
      a = a % b;
      if (a == 0) return b;
    
      b = b % a;
      if (b == 0) return a;
    }
  }
}
