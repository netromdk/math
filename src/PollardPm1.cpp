#include <cmath>
#include <vector>
using namespace std;

#include "GCD.h"
#include "LCM.h"
#include "Mod.h"
#include "PollardPm1.h"

namespace Math {
  namespace Fac {
    bool pollardPm1I(int n, int *f, int maxB) {
      int B = log10(n);
      int m = lcmRange(1, B);
      
      for (; (maxB > 0 ? B < maxB : true);
           B++, m = lcm(m, B)) {
        for (int a = 2; a < m; a++) {
          int x = mod(pow((double) a, (double) m) - 1, n);
          int g = gcd(x, n);

          if (g > 1) {
            if(f) *f = g;
            return true;
          }
        }
      }
      
      return false;
    }
  }
}
