#include <cstddef>

#include "Smooth.h"
#include "PollardRho.h"

namespace Math {
  namespace Fac {
    bool isSmoothI(int n, int B, int *C) {
      vector<int> facs;
      pollardRhoFactorI(n, facs);

      int max = 0;
      for (size_t i = 0; i < facs.size(); i++) {
        int fac = facs[i];
        if (fac > max) max = fac;
      }

      if (max <= B) return true;

      if (C) *C = max;
      return false;
    }
  }
}
