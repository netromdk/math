#ifndef MATH_POLLARD_RHO_H
#define MATH_POLLARD_RHO_H

namespace Math {
  namespace Fac {
    namespace {
      int fI(int x, int a, int n);
    }

    /**
     * Finds a nontrivial factor of composite number n.
     */
    int pollardRhoI(int n);
  }
}

#endif // MATH_POLLARD_RHO_H
