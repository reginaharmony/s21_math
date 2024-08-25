#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_fabs(double x) { return x < 0 ? -x : x; }

long double s21_fmod(double x, double y) {
  if (y == 0.) return S21_NAN;
  if (S21_IS_INF(x)) return S21_NAN;
  return x - (int)(x / y) * y;
}

long double s21_ceil(double x) {
  if (!S21_IS_FIN(x) || x == DBL_MAX) return x;
  long double result = (long long int)x;
  return x > result ? result += 1 : result;
}

long double s21_floor(double x) {
  if (!S21_IS_FIN(x)) return x;
  long double result = (long long int)x;
  if (x < 0 && x != result) result--;
  return result;
}

long double s21_sqrt(double x) {
  if (x < 0) return S21_NAN;
  double precision = 1e-11;
  double start = 0;
  double end = x;
  if (x < 1) end = 1;
  while (end - start > precision) {
    double mid = (start + end) / 2;
    double square = mid * mid;
    if (square == x) return mid;
    if (square < x)
      start = mid;
    else
      end = mid;
  }
  return (start + end) / 2;
}

// common template for pow calculations
#define POW_CHK                     \
  int isNeg = 0;                    \
  if (exp < 0) exp = -exp, isNeg++; \
  long double result = 1;

long double s21_pow_fast(double base, double exp) {
  POW_CHK
  while (exp > 0) {
    if (exp >= 1)
      result *= base, exp -= 1;
    else
      base = s21_sqrt(base), exp *= 2;
  }
  return isNeg ? 1 / result : result;
}

long double s21_pow_cool(double base, double exp) {
  POW_CHK
  int intExp = (int)exp;
  while (intExp > 0) {
    result *= base;
    intExp--;
  }
  if (exp - (int)exp > 0) result *= s21_sqrt(base);
  return isNeg ? 1 / result : result;
}

long double s21_pow_exceptions(double base, double exp) {
  int base_nan = S21_IS_NAN(base);
  int base_fin = S21_IS_FIN(base);
  int exp_nan = S21_IS_NAN(exp);
  int exp_fin = S21_IS_FIN(exp);
  int exp_min = s21_fabs(exp - s21_floor(exp)) <= S21_EPS;

  if (base == DBL_MIN && exp > 0 && exp < DBL_MAX_EXP) return DBL_MIN;
  if (s21_fabs(exp) < S21_EPS) return 1;
  if (base_fin && !base_nan && s21_fabs(base + 1) < S21_EPS && !exp_fin &&
      !exp_nan)
    return 1;
  if (base_fin && !base_nan && s21_fabs(base - 1) < S21_EPS) return 1;
  if (s21_fabs(base) - 1 > S21_EPS && !exp_nan && !exp_fin && exp < 0)
    return +0;
  if (s21_fabs(base) - 1 < S21_EPS && !exp_nan && !exp_fin && exp > 0)
    return +0;
  if (!base_nan && !base_fin && base < 0 && exp_min && exp < 0 &&
      ((int)exp) % 2)
    return -0;
  if (s21_fabs(base) - 1 < S21_EPS && !exp_nan && !exp_fin && exp < 0)
    return S21_INF;
  if (s21_fabs(base) - 1 > S21_EPS && !exp_nan && !exp_fin && exp > 0)
    return S21_INF;
  if (base_nan || exp_nan) return S21_NAN;
  if (base_fin && s21_fabs(base) < S21_EPS && exp_fin &&
      ((exp_min && !(((int)exp) % 2)) || !exp_min)) {
    if (base == 0 && exp == 0) return 1;
    if (base == 0 && exp > 0) return 0;
    return S21_INF;
  }
  if (!base_nan && !base_fin && base < 0 &&
      ((!exp_min && exp > 0) || (exp_min && exp > 0 && !(((int)exp) % 2))))
    return S21_INF;
  return 69;
}

long double s21_pow(double base, double exp) {
  long double check = s21_pow_exceptions(base, exp);
  if (check != 69) return check;
  const double exp_threshold = 7;
  if (s21_fabs(exp) < exp_threshold) return s21_pow_fast(base, exp);
  return s21_pow_cool(base, exp);
}

long double s21_factorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return S21_INF;
  return x * s21_factorial(x - 1);
}

long double s21_exp(double x) {
  if (x == -S21_INF) return 0;
  long double result = 0;
  long double k = (long long int)(x / S21_LN2);
  long double r = x - k * S21_LN2;
  FST_FOR(10)
  result += s21_pow_cool(r, i) / s21_factorial(i);
  result *= s21_pow_cool(2, k);
  return result;
}

long double s21_log(double x) {
  int exp = 0;
  double result = 0;
  FST_IF(x == S21_INF, x)
  FST_IF(x == 0, -S21_INF)
  FST_IF(x < 0, S21_NAN)
  FST_IF(x == 1, 0)
  else {
    for (; x >= S21_E; x /= S21_E, exp++)
      ;
    FST_FOR(100) {
      double compare = 0;
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return (result + exp);
}

long double s21_sin(double x) {
  long double result = 0, upper = 0, lower = 0;
  x = s21_fmod(x, 2 * S21_PI);
  FST_FOR(12) {
    upper = s21_pow_fast(-1, i) * s21_pow_fast(x, 2 * i + 1);
    lower = s21_factorial(2 * i + 1);
    result += upper / lower;
  }
  return result;
}

long double s21_cos(double x) {
  if (x == S21_INF || x == -S21_INF || S21_IS_NAN(x)) return S21_NAN;
  return s21_sin(S21_PI / 2 - x);
}

long double s21_tan(double x) {
  if (x == S21_PI / 2 || x == -S21_PI / 2)
    return (x > 0) ? S21_TAN_SPC : -S21_TAN_SPC;
  return (s21_sin(x) / s21_cos(x));
}

long double s21_atan(double x) {
  if (S21_IS_INF(x)) return S21_PI / 2;
  if (x == 1 || x == -1) return x > 0. ? S21_PI / 4 : -S21_PI / 4;
  long double result = 0;
  if (x < -1 || x > 1) {
    int k = s21_fabs(x) > 1 ? -1 : 1;
    FST_FOR(100) {
      result +=
          (s21_pow(-1, i) * s21_pow(x, (1 * k + 2 * k * i))) / (1 + 2 * i);
    }
    result = (k == -1) ? (S21_PI * s21_fabs(x) / (2 * x) - result) : result;
  } else {
    for (int i = 1; i <= 110; i += 2) {
      result += s21_pow(-1, (i - 1) / 2) * s21_pow(x, i) / i;
    }
  }
  return result;
}

long double s21_asin(double x) {
  if (x > 1. || x < -1. || !S21_IS_FIN(x)) return S21_NAN;
  if (x == 1 || x == -1) return x > 0 ? S21_PI / 2 : -S21_PI / 2;
  return s21_atan(x / s21_sqrt(1 - x * x));
}

long double s21_acos(double x) { return (S21_PI / 2 - s21_asin(x)); }