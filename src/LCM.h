#ifndef MATH_LCM_H
#define MATH_LCM_H

namespace Math {
  int lcm(int a, int b);

  /**
   * It is assumed that |min - max| >= 2.
   */
  int lcmRange(int min, int max);
}

#endif // MATH_LCM_H
