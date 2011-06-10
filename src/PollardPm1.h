#ifndef MATH_POLLARD_P_MINUS_ONE_H
#define MATH_POLLARD_P_MINUS_ONE_H

namespace Math {
  namespace Fac {
    /**
     * Finds a nontrivial factor of composite number n until search
     * bound reaches maxB, if given, otherwise it loops. If found it
     * saves it in f.
     */
    bool pollardPm1I(int n, int *f, int maxB = 0);
  }
}

#endif // MATH_POLLARD_P_MINUS_ONE_H
