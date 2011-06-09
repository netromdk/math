#ifndef MATH_SMOOTH_H
#define MATH_SMOOTH_H

namespace Math {
  namespace Fac {
    /**
     * Checks if n is B-smooth. Otherwise, if C is specified then that
     * will be the actual smoothness bound.
     */
    bool isSmoothI(int n, int B, int *C = NULL);
  }
}

#endif // MATH_SMOOTH_H
