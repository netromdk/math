#include "LCM.h"
#include "GCD.h"

namespace Math {
  int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
  }

  int lcmRange(int min, int max) {
    int a = min;
    for (int i = min + 1; i <= max; i++) {
      a = lcm(a, i);
    }
    return a;
  }
}
