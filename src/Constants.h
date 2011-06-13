#ifndef MATH_CONSTANTS_H
#define MATH_CONSTANTS_H

#include <gmp.h>

namespace Math {
  /**
   * Euler's constant.
   */
  const double E = 2.71828182845904523536028747135266249775724709369995;

  /**
   * Pi constant.
   */
  const double PI = 3.14159265358979323846264338327950288419716939937510;

  void eCnst(mpf_t e);
}

#endif // MATH_CONSTANTS_H
