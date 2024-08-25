#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF || x == -S21_INF)
#define S21_IS_FIN(x) !(S21_IS_NAN(x) || S21_IS_INF(x))

#define FST_FOR(x) for (int i = 0; i < x; i++)  // useful one
#define FST_IF(x, y) \
  if (x) return y;  // inside joke

#define S21_PI 3.14159265358979323846
#define S21_EPS 1e-9
#define S21_TST 1e-7

// s21_log
#define S21_E 2.7182818284590452353602874713526624L

// s21_exp
#define S21_LN2 0.693147180559945309417232

// s21_tan
#define S21_TAN_SPC 16331239353195370L

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sqrt(double num);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

#endif