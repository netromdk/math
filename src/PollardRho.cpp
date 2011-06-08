#include "Mod.h"
#include "GCD.h"
#include "PollardRho.h"

namespace Math {
  namespace {
    int fI(int x, int a, int n) {
      return mod(x * x + a, n);
    }
  }
  
  int pollardRhoI(int n) {
    int a = 1, s = 2, g, u, v;
    u = v = s;
    
    do {
      u = fI(u, a, n);
      v = fI(fI(v, a, n), a, n);
      g = gcd(mod(u - v, n), n);
    } while (g == 1);

    if (g == n) {
      return pollardRhoI(n);
    }
    
    return g;
  }
}
