#include "Mod.h"
#include "GCD.h"
#include "Random.h"
#include "Common.h"
#include "PollardRho.h"

namespace Math {
  namespace Fac {
    namespace {
      int fI(int x, int a, int n) {
        return mod(x * x + a, n);
      }
    }
  
    int pollardRhoI(int n) {
      // Return n if n is a probable-prime.
      if (isPropPrime(n)) return n;
      
      Random rnd;
      int a = rnd.getRange(1, n - 3),
        s = rnd.getRange(0, n - 1);    

      int g, u, v;    
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
}
