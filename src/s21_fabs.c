#include "s21_math.h"

long double s21_fabs(long double x) {
  if (!S21_ISNAN(x)) {
    x = x < 0 ? -x : x;
  }
  return x;
}
