#include "s21_math.h"

long double s21_pown(long double base, long double exp) {
  long double result = 1;
  if (exp > 0) {
    for (int i = 0; i < exp; i++) result *= base;
  } else if (exp < 0) {
    for (int i = 0; i < -exp; i++) result /= base;
  }
  return result;
}

long double s21_powq(long double base, long double exp) {
  long double result = base >= 0 ? s21_exp(exp * s21_log(base)) : S21_NAN;
  return result;
}

long double s21_pow(long double base, long double exp) {
  if ((base == S21_NEG_INF && exp == S21_NEG_INF) ||
      (s21_fabs(base) < S21_EPS && exp == S21_POS_INF))
    return 0;
  if ((base == S21_NEG_INF && exp == S21_POS_INF) ||
      (s21_fabs(base) < S21_EPS && exp < 0))
    return S21_POS_INF;
  long double result = 0;
  if ((long double)(long long int)exp == exp) {
    result = s21_pown(base, exp);
  } else {
    result = s21_powq(base, exp);
  }
  return result;
}
