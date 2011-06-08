#include "Mod.h"
#include "GCD.h"
#include "Random.h"
#include "PollardRho.h"

namespace Math {
  namespace {
    int fI(int x, int a, int n) {
      return mod(x * x + a, n);
    }
  }
  
  int pollardRhoI(int n) {
    int a, s, g, u, v;

    Random rnd;
    a = rnd.getRange(1, n - 3);
    s = rnd.getRange(0, n - 1);    
    
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
