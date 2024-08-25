#include "../s21_math.h"

#include <check.h>
#include <math.h>

START_TEST(abs_normal_numbers) {
  int x = 1;
  int y = -1;
  int z = 0;
  ck_assert_int_eq(s21_abs(x), abs(x));
  ck_assert_int_eq(s21_abs(y), abs(y));
  ck_assert_int_eq(s21_abs(z), abs(z));
}
END_TEST

START_TEST(abs_big_numbers) {
  int x = 1234567891;
  int y = -1234567891;
  int z = 7.123456;
  int t = -7.123456;
  ck_assert_int_eq(s21_abs(x), abs(x));
  ck_assert_int_eq(s21_abs(y), abs(y));
  ck_assert_int_eq(s21_abs(z), abs(z));
  ck_assert_int_eq(s21_abs(t), abs(t));
}
END_TEST

START_TEST(abs_special_cases) {
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(+0), abs(+0));
}
END_TEST

int t1(void) {
  Suite *s1 = suite_create("s21_abs");
  TCase *tc1_1 = tcase_create("s21_abs");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, abs_normal_numbers);
  tcase_add_test(tc1_1, abs_big_numbers);
  tcase_add_test(tc1_1, abs_special_cases);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(fabs1) { ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001)); }
END_TEST

START_TEST(fabs2) {
  ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
}
END_TEST

START_TEST(fabs3) {
  ck_assert_ldouble_eq(s21_fabs(-2147483600.543), fabs(-2147483600.543));
}
END_TEST

START_TEST(fabs4) {
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
}
END_TEST

START_TEST(fabs5) {
  ck_assert_ldouble_eq(s21_fabs(-5.53151413431), fabs(-5.53151413431));
}
END_TEST

START_TEST(fabs6) {
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
}
END_TEST

START_TEST(fabs7) {
  double a = -9519359135915.53151413431;
  ck_assert_ldouble_eq_tol(s21_fabs(a), fabs(a), S21_EPS);
}
END_TEST

START_TEST(fabs8) {
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(fabs9) { ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY)); }
END_TEST

START_TEST(fabs10) {
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
}
END_TEST

int t2(void) {
  Suite *s1 = suite_create("s21_fabs");
  TCase *tc1_1 = tcase_create("s21_fabs");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, fabs1);
  tcase_add_test(tc1_1, fabs2);
  tcase_add_test(tc1_1, fabs3);
  tcase_add_test(tc1_1, fabs4);
  tcase_add_test(tc1_1, fabs5);
  tcase_add_test(tc1_1, fabs6);
  tcase_add_test(tc1_1, fabs7);
  tcase_add_test(tc1_1, fabs8);
  tcase_add_test(tc1_1, fabs9);
  tcase_add_test(tc1_1, fabs10);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(floor1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor2) { ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21)); }
END_TEST

START_TEST(floor3) { ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91)); }
END_TEST

START_TEST(floor4) { ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21)); }
END_TEST

START_TEST(floor5) { ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91)); }
END_TEST

START_TEST(floor6) {
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(INFINITY));
}
END_TEST

START_TEST(floor7) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(floor8) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(floor9) { ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01)); }
END_TEST

START_TEST(floor10) { ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01)); }
END_TEST

START_TEST(floor11) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor12) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(floor13) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

START_TEST(floor14) { ck_assert_ldouble_eq(s21_floor(-1), floor(-1)); }
END_TEST

START_TEST(floor15) { ck_assert_ldouble_eq(s21_floor(1), floor(1)); }
END_TEST

int t3(void) {
  Suite *s1 = suite_create("s21_floor");
  TCase *tc1_1 = tcase_create("s21_floor");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, floor1);
  tcase_add_test(tc1_1, floor2);
  tcase_add_test(tc1_1, floor3);
  tcase_add_test(tc1_1, floor4);
  tcase_add_test(tc1_1, floor5);
  tcase_add_test(tc1_1, floor6);
  tcase_add_test(tc1_1, floor7);
  tcase_add_test(tc1_1, floor8);
  tcase_add_test(tc1_1, floor9);
  tcase_add_test(tc1_1, floor10);
  tcase_add_test(tc1_1, floor11);
  tcase_add_test(tc1_1, floor12);
  tcase_add_test(tc1_1, floor13);
  tcase_add_test(tc1_1, floor14);
  tcase_add_test(tc1_1, floor15);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(ceil_1) { ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01)); }
END_TEST

START_TEST(ceil_2) { ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01)); }
END_TEST

START_TEST(ceil_3) { ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY)); }
END_TEST

START_TEST(ceil_4) {
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceil_5) { ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12)); }
END_TEST

START_TEST(ceil_6) {
  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceil_7) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil_8) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(ceil_9) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(ceil_11) { ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0)); }
END_TEST

START_TEST(ceil_12) { ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21)); }
END_TEST

START_TEST(ceil_13) { ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91)); }
END_TEST

START_TEST(ceil_14) { ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21)); }
END_TEST

START_TEST(ceil_15) { ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91)); }
END_TEST

START_TEST(ceil_16) {
  ck_assert_ldouble_eq(s21_ceil(DBL_MAX), (long double)ceil(DBL_MAX));
}
END_TEST

int t4(void) {
  Suite *s1 = suite_create("s21_ceil");
  TCase *tc1_1 = tcase_create("s21_ceil");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, ceil_1);
  tcase_add_test(tc1_1, ceil_2);
  tcase_add_test(tc1_1, ceil_3);
  tcase_add_test(tc1_1, ceil_4);
  tcase_add_test(tc1_1, ceil_5);
  tcase_add_test(tc1_1, ceil_6);
  tcase_add_test(tc1_1, ceil_7);
  tcase_add_test(tc1_1, ceil_8);
  tcase_add_test(tc1_1, ceil_9);
  tcase_add_test(tc1_1, ceil_11);
  tcase_add_test(tc1_1, ceil_12);
  tcase_add_test(tc1_1, ceil_13);
  tcase_add_test(tc1_1, ceil_14);
  tcase_add_test(tc1_1, ceil_15);
  tcase_add_test(tc1_1, ceil_16);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(fmod1) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
}
END_TEST

START_TEST(fmod2) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
}
END_TEST

START_TEST(fmod3) {
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(fmod4) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
}
END_TEST

START_TEST(fmod5) { ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3)); }
END_TEST

START_TEST(fmod6) { ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21)); }
END_TEST

START_TEST(fmod7) {
  ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
}
END_TEST

START_TEST(fmod8) {
  ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
}
END_TEST

START_TEST(fmod9) {
  ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
}
END_TEST

START_TEST(fmod10) {
  ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
}
END_TEST

START_TEST(fmod11) {
  ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
}
END_TEST

START_TEST(fmod12) { ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9)); }
END_TEST

START_TEST(fmod13) { ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5)); }
END_TEST

START_TEST(fmod14) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(fmod15) {
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(fmod16) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
  ck_assert_ldouble_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(fmod17) {
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmod(0, 0));
}
END_TEST

START_TEST(fmod18) {
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
  ck_assert_ldouble_nan(fmod(2.45, 0));
}
END_TEST

int t5(void) {
  Suite *s1 = suite_create("s21_fmod");
  TCase *tc1_1 = tcase_create("s21_fmod");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, fmod1);
  tcase_add_test(tc1_1, fmod2);
  tcase_add_test(tc1_1, fmod3);
  tcase_add_test(tc1_1, fmod4);
  tcase_add_test(tc1_1, fmod5);
  tcase_add_test(tc1_1, fmod6);
  tcase_add_test(tc1_1, fmod7);
  tcase_add_test(tc1_1, fmod8);
  tcase_add_test(tc1_1, fmod9);
  tcase_add_test(tc1_1, fmod10);
  tcase_add_test(tc1_1, fmod11);
  tcase_add_test(tc1_1, fmod12);
  tcase_add_test(tc1_1, fmod13);
  tcase_add_test(tc1_1, fmod14);
  tcase_add_test(tc1_1, fmod15);
  tcase_add_test(tc1_1, fmod16);
  tcase_add_test(tc1_1, fmod17);
  tcase_add_test(tc1_1, fmod18);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(acos1) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos2) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), S21_EPS);
}
END_TEST

START_TEST(acos3) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), S21_EPS);
}
END_TEST

START_TEST(acos4) {
  ck_assert_ldouble_eq_tol(s21_acos(0.8660254047234567),
                           acos(0.8660254047234567), S21_EPS);
}
END_TEST

START_TEST(acos5) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), S21_EPS);
}
END_TEST

START_TEST(acos6) {
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), S21_EPS);
}
END_TEST

START_TEST(acos7) {
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cos(INFINITY));
}
END_TEST

START_TEST(acos8) {
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cos(-INFINITY));
}
END_TEST

START_TEST(acos9) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.8660254047234567),
                           acos(-0.8660254047234567), S21_EPS);
}
END_TEST

START_TEST(acos10) {
  ck_assert_ldouble_nan(s21_acos(-21.1));
  ck_assert_ldouble_nan(acos(-21.1));
}
END_TEST

START_TEST(acos11) {
  ck_assert_ldouble_nan(s21_acos(21.1));
  ck_assert_ldouble_nan(acos(21.1));
}
END_TEST

START_TEST(acos12) {
  ck_assert_ldouble_nan(s21_acos(174.532925199433));
  ck_assert_ldouble_nan(acos(174.532925199433));
}
END_TEST

START_TEST(acos13) {
  double num = NAN;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

int t6(void) {
  Suite *s1 = suite_create("s21_acos");
  TCase *tc1_1 = tcase_create("s21_acos");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, acos1);
  tcase_add_test(tc1_1, acos2);
  tcase_add_test(tc1_1, acos3);
  tcase_add_test(tc1_1, acos4);
  tcase_add_test(tc1_1, acos5);
  tcase_add_test(tc1_1, acos6);
  tcase_add_test(tc1_1, acos7);
  tcase_add_test(tc1_1, acos8);
  tcase_add_test(tc1_1, acos9);
  tcase_add_test(tc1_1, acos10);
  tcase_add_test(tc1_1, acos11);
  tcase_add_test(tc1_1, acos12);
  tcase_add_test(tc1_1, acos13);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(asin1) {
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
}
END_TEST

START_TEST(asin2) {
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
}
END_TEST

START_TEST(asin3) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(asin(NAN));
}
END_TEST

START_TEST(asin4) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), S21_EPS);
}
END_TEST

START_TEST(asin5) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), S21_EPS);
}
END_TEST

START_TEST(asin6) {
  ck_assert_ldouble_nan(s21_asin(-21.1));
  ck_assert_ldouble_nan(asin(-21.1));
}
END_TEST

START_TEST(asin7) {
  ck_assert_ldouble_nan(s21_asin(21.1));
  ck_assert_ldouble_nan(asin(21.1));
}
END_TEST

START_TEST(asin8) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), S21_EPS);
}
END_TEST

START_TEST(asin9) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), S21_EPS);
}
END_TEST

START_TEST(asin10) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.8660254047234567),
                           asin(-0.8660254047234567), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_asin(0.8660254047234567),
                           asin(0.8660254047234567), S21_EPS);
}
END_TEST

START_TEST(asin11) {
  ck_assert_ldouble_nan(s21_acos(174.532925199433));
  ck_assert_ldouble_nan(acos(174.532925199433));
}
END_TEST

int t7(void) {
  Suite *s1 = suite_create("s21_asin");
  TCase *tc1_1 = tcase_create("s21_asin");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, asin1);
  tcase_add_test(tc1_1, asin2);
  tcase_add_test(tc1_1, asin3);
  tcase_add_test(tc1_1, asin4);
  tcase_add_test(tc1_1, asin5);
  tcase_add_test(tc1_1, asin6);
  tcase_add_test(tc1_1, asin7);
  tcase_add_test(tc1_1, asin8);
  tcase_add_test(tc1_1, asin9);
  tcase_add_test(tc1_1, asin10);
  tcase_add_test(tc1_1, asin11);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(atan1) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_2) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), S21_EPS);
}
END_TEST

START_TEST(atan3) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), S21_EPS);
}
END_TEST

START_TEST(atan4) {
  ck_assert_ldouble_eq_tol(s21_atan(0.8660254047234567),
                           atan(0.8660254047234567), S21_EPS);
}
END_TEST

START_TEST(atan5) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), S21_EPS);
}
END_TEST

START_TEST(atan6) {
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), S21_EPS);
}
END_TEST

START_TEST(atan7) {
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
}
END_TEST

START_TEST(atan8) {
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
}
END_TEST

START_TEST(atan9) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.8660254047234567),
                           atan(-0.8660254047234567), S21_EPS);
}
END_TEST

START_TEST(atan10) {
  ck_assert_ldouble_eq_tol(s21_atan(-1000000000000000), atan(-1000000000000000),
                           S21_EPS);
}
END_TEST

START_TEST(atan11) {
  ck_assert_ldouble_eq_tol(s21_atan(10.123456), atan(10.123456), S21_EPS);
}
END_TEST

int t8(void) {
  Suite *s1 = suite_create("s21_atan");
  TCase *tc1_1 = tcase_create("s21_atan");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, atan1);
  tcase_add_test(tc1_1, atan_2);
  tcase_add_test(tc1_1, atan3);
  tcase_add_test(tc1_1, atan4);
  tcase_add_test(tc1_1, atan5);
  tcase_add_test(tc1_1, atan6);
  tcase_add_test(tc1_1, atan7);
  tcase_add_test(tc1_1, atan8);
  tcase_add_test(tc1_1, atan9);
  tcase_add_test(tc1_1, atan10);
  tcase_add_test(tc1_1, atan11);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

START_TEST(sqrt_1) {
  ck_assert_double_nan(s21_sqrt(-0.01));
  ck_assert_double_nan(sqrt(-0.01));
}
END_TEST

START_TEST(sqrt_2) { ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY)); }
END_TEST

START_TEST(sqrt_3) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_4) {
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(sqrt_5) {
  ck_assert_double_nan(s21_sqrt(-231.41));
  ck_assert_double_nan(sqrt(-231.41));
}
END_TEST

START_TEST(sqrt_6) {
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     0.0001,
                       21345678, 7432,      0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), 0.000001);
  }
}
END_TEST

Suite *suite_sqrt(void) {
  Suite *s = suite_create("suite_sqrt");
  TCase *tc1_1 = tcase_create("sqrt_tc");

  tcase_add_test(tc1_1, sqrt_1);
  tcase_add_test(tc1_1, sqrt_2);
  tcase_add_test(tc1_1, sqrt_3);
  tcase_add_test(tc1_1, sqrt_4);
  tcase_add_test(tc1_1, sqrt_5);
  tcase_add_test(tc1_1, sqrt_6);

  suite_add_tcase(s, tc1_1);
  return s;
}

START_TEST(pow_1) {
  double base = 4590.789;
  double exp = 14.1;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  ck_assert_float_eq(ours_res, orig_res);
  if (s21_fabs(orig_res - ours_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_2) {
  double base = INFINITY;
  double exp = 1.1;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isinf(ours_res) && isinf(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_3) {
  double base = NAN;
  double exp = 1.1;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isnan(ours_res) && isnan(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_4) {
  double base = NAN;
  double exp = NAN;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isnan(ours_res) && isnan(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_5) {
  double base = 0.001;
  double exp = NAN;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isnan(ours_res) && isnan(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_6) {
  double base = INFINITY;
  double exp = INFINITY;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isinf(ours_res) && isinf(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_7) {
  double base = INFINITY;
  double exp = INFINITY;
  long double orig_res = pow(base, exp), ours_res = s21_pow(base, exp);
  int succ = 0;
  if (isinf(ours_res) && isinf(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.0;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_11) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  long double base = -0;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_17) {
  long double base = -1;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = S21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  long double base = S21_NAN;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  long double base = 0.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = -S21_INF;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_26) {
  long double base = -S21_INF;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_27) {
  long double base = -S21_INF;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = -S21_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = S21_INF;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

START_TEST(pow_30) {
  long double base = S21_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), S21_TST);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), S21_TST);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), S21_TST);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), S21_TST);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           S21_TST);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), S21_TST);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), S21_TST);
}
END_TEST

START_TEST(pow_38) {
  long double orig_res = pow(2.1234567e-7, -2.45e4),
              ours_res = s21_pow(2.1234567e-7, -2.45e4);
  int succ = 0;
  if (isinf(ours_res) && isinf(orig_res)) succ = 1;
  ck_assert_int_eq(1, succ);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), S21_TST);
}
END_TEST

START_TEST(pow_40) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(-0, exp));
  ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), S21_TST);
}
END_TEST

START_TEST(pow_43) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(+0, exp));
  ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_44) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), S21_TST);
}
END_TEST

START_TEST(pow_45) {
  long double exp = -S21_INF;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), S21_TST);
}
END_TEST

START_TEST(pow_47) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), S21_TST);
}
END_TEST

START_TEST(pow_48) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), S21_TST);
}
END_TEST

START_TEST(pow_49) {
  long double exp = S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), S21_TST);
}
END_TEST

START_TEST(pow_50) {
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), S21_TST);
}
END_TEST

START_TEST(pow_51) {
  long double exp = S21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), S21_TST);
}
END_TEST

START_TEST(pow_52) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), S21_TST);
}
END_TEST

START_TEST(pow_53) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), S21_TST);
}
END_TEST

START_TEST(pow_54) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), S21_TST);
}
END_TEST

START_TEST(pow_55) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), S21_TST);
}
END_TEST

START_TEST(pow_56) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(S21_NAN, exp));
  ck_assert_double_nan(pow(S21_NAN, exp));
}
END_TEST

START_TEST(pow_57) {
  long double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(S21_INF, exp));
  ck_assert_ldouble_infinite(pow(S21_INF, exp));
}
END_TEST

START_TEST(pow_58) {
  long double exp = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, exp), pow(-S21_INF, exp), S21_TST);
}
END_TEST

START_TEST(pow_59) {
  double exp = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, exp));
  ck_assert_ldouble_infinite(pow(-S21_INF, exp));
}
END_TEST

START_TEST(pow_60) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(S21_INF, exp);
    res2 = s21_pow(S21_INF, exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}
END_TEST

START_TEST(pow_61) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, S21_INF);
    res2 = s21_pow(base, S21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, S21_INF);
    res2 = s21_pow(base, S21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, -S21_INF);
    res2 = s21_pow(base, -S21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}
END_TEST

START_TEST(pow_64) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, -S21_INF);
    res2 = s21_pow(base, -S21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}
END_TEST

START_TEST(pow_65) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}
END_TEST

START_TEST(pow_66) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}
END_TEST

START_TEST(pow_67) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-S21_INF, exp);
      res2 = s21_pow(-S21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, S21_TST);
}

END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), S21_TST);
}
END_TEST

START_TEST(pow_70) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), S21_TST);
}
END_TEST

START_TEST(pow_71) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), S21_TST);
}
END_TEST

START_TEST(pow_72) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), S21_TST);
}
END_TEST

START_TEST(pow_73) {
  long double base = -0;
  long double exp = S21_INF;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, S21_TST);
}
END_TEST

START_TEST(pow_74) {
  long double exp;
  long double base = -0;
  long double res;
  long double res1;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, S21_TST);
}
END_TEST

START_TEST(pow_75) {
  long double base = 16.161435;
  long double exp = 12.0;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), S21_TST);
}
END_TEST

Suite *suite_pow_1(void) {
  Suite *s1 = suite_create("suite_pow_1");
  TCase *tc1 = tcase_create("pow_tc_1");

  tcase_add_test(tc1, pow_1);
  tcase_add_test(tc1, pow_2);
  tcase_add_test(tc1, pow_3);
  tcase_add_test(tc1, pow_4);
  tcase_add_test(tc1, pow_5);
  tcase_add_test(tc1, pow_6);
  tcase_add_test(tc1, pow_7);
  tcase_add_test(tc1, pow_8);
  tcase_add_test(tc1, pow_9);
  tcase_add_test(tc1, pow_10);
  tcase_add_test(tc1, pow_11);
  tcase_add_test(tc1, pow_12);
  tcase_add_test(tc1, pow_13);
  tcase_add_test(tc1, pow_14);
  tcase_add_test(tc1, pow_15);
  tcase_add_test(tc1, pow_16);
  tcase_add_test(tc1, pow_17);
  tcase_add_test(tc1, pow_18);
  tcase_add_test(tc1, pow_19);
  tcase_add_test(tc1, pow_20);
  tcase_add_test(tc1, pow_21);
  tcase_add_test(tc1, pow_22);
  tcase_add_test(tc1, pow_23);
  tcase_add_test(tc1, pow_24);
  tcase_add_test(tc1, pow_25);
  tcase_add_test(tc1, pow_26);
  tcase_add_test(tc1, pow_27);
  tcase_add_test(tc1, pow_28);
  tcase_add_test(tc1, pow_29);
  tcase_add_test(tc1, pow_30);
  tcase_add_test(tc1, pow_31);
  tcase_add_test(tc1, pow_32);
  tcase_add_test(tc1, pow_33);
  tcase_add_test(tc1, pow_34);
  tcase_add_test(tc1, pow_35);
  tcase_add_test(tc1, pow_36);
  tcase_add_test(tc1, pow_37);
  tcase_add_test(tc1, pow_38);
  tcase_add_test(tc1, pow_39);
  tcase_add_test(tc1, pow_40);
  tcase_add_test(tc1, pow_41);
  tcase_add_test(tc1, pow_42);
  tcase_add_test(tc1, pow_43);
  tcase_add_test(tc1, pow_44);
  tcase_add_test(tc1, pow_45);
  tcase_add_test(tc1, pow_46);
  tcase_add_test(tc1, pow_47);
  tcase_add_test(tc1, pow_48);
  tcase_add_test(tc1, pow_49);
  tcase_add_test(tc1, pow_50);
  tcase_add_test(tc1, pow_51);
  tcase_add_test(tc1, pow_52);
  tcase_add_test(tc1, pow_53);
  tcase_add_test(tc1, pow_54);
  tcase_add_test(tc1, pow_55);
  tcase_add_test(tc1, pow_56);
  tcase_add_test(tc1, pow_57);
  tcase_add_test(tc1, pow_58);
  tcase_add_test(tc1, pow_59);
  tcase_add_test(tc1, pow_60);
  tcase_add_test(tc1, pow_61);
  tcase_add_test(tc1, pow_62);
  tcase_add_test(tc1, pow_63);
  tcase_add_test(tc1, pow_64);
  tcase_add_test(tc1, pow_65);
  tcase_add_test(tc1, pow_66);
  tcase_add_test(tc1, pow_67);
  tcase_add_test(tc1, pow_68);
  tcase_add_test(tc1, pow_69);
  tcase_add_test(tc1, pow_70);
  tcase_add_test(tc1, pow_71);
  tcase_add_test(tc1, pow_72);
  tcase_add_test(tc1, pow_73);
  tcase_add_test(tc1, pow_74);
  tcase_add_test(tc1, pow_75);

  suite_add_tcase(s1, tc1);
  return s1;
}

START_TEST(test_pos_1) {
  double num = 134.5;
  double p = 1.4;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_pos_2) {
  double num = 134.5;
  double p = 20.5e-34;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_pow_1) {
  double num = 563.23;
  double p = -42.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_num_odd_int_pow) {
  double num = -10.1;
  double p = -3.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_num_int_pow) {
  double num = -10.1;
  double p = 2.;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_num_fract_pow) {
  double num = -10.1;
  double p = -1.5;
  ck_assert_ldouble_nan(s21_pow(num, p));
}
END_TEST

START_TEST(test_fractional_pow) {
  double num = 10.1;
  double p = 0.123;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_fractional_pow_neg_num) {
  double num = -27.45;
  double p = 1.0 / 3.0;
  ck_assert_ldouble_nan(s21_pow(num, p));
}
END_TEST

START_TEST(test_zero_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = 0;
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(nums[i], p), s21_pow(nums[i], p), S21_TST);
}
END_TEST

START_TEST(test_one_num) {
  double num = 1.0;
  double p[7] = {1, 1.23, -1.23, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  int i = _i;
  ck_assert_ldouble_eq_tol(pow(num, p[i]), s21_pow(num, p[i]), S21_TST);
}
END_TEST

START_TEST(test_one_power) {
  double num = 12.34;
  double p = 1;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_nan_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = S21_NAN;
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(nums[i], p));
}
END_TEST

START_TEST(test_nan_num) {
  double num = S21_NAN;
  double p[8] = {1, -1, -11.1, 11.1, S21_INF, -S21_INF, S21_NAN, -S21_NAN};
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(num, p[i]));
}
END_TEST

START_TEST(test_neg_nan_power) {
  double nums[6] = {1.12, -34.45, S21_NAN, -S21_NAN, S21_INF, -S21_INF};
  double p = -S21_NAN;
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(nums[i], p));
}
END_TEST

START_TEST(test_neg_nan_num) {
  double num = -S21_NAN;
  double p[8] = {1, -1, -11.1, 11.1, S21_INF, -S21_INF, S21_NAN, -S21_NAN};
  int i = _i;
  ck_assert_ldouble_nan(s21_pow(num, p[i]));
}
END_TEST

START_TEST(test_zero_neg_pow) {
  double num = 0;
  double p = -12;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}

START_TEST(test_zero_pos_pow) {
  double num = 0;
  double p = 12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}

START_TEST(test_minus_one_inf_pow) {
  double num = -1;
  ck_assert_ldouble_eq_tol(pow(num, S21_INF), s21_pow(num, S21_INF), S21_TST);
}

START_TEST(test_fract_num_neg_inf_pow) {
  double num = 0.123;
  double p = -S21_INF;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_fract_num_pos_inf_pow) {
  double num = 0.123;
  double p = S21_INF;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_num_neg_pos_pow) {
  double num = 13;
  double p = -S21_INF;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_fract_num_pos_pow) {
  double num = -0;
  double p = 12;
  ck_assert_ldouble_eq(pow(num, p), s21_pow(num, p));
}
END_TEST

START_TEST(test_num_inf_pow) {
  double num = 13;
  double p = S21_INF;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_pos_inf_neg_pow) {
  double num = S21_INF;
  double p = -12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_inf_pos_pow) {
  double num = -S21_INF;
  double p = -13;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_neg_inf_pos_odd_pow) {
  double num = -S21_INF;
  double p = 13;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(test_neg_inf_neg_pow) {
  double num = -S21_INF;
  double p = -12;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(test_pos_inf_pos_pow) {
  double num = S21_INF;
  double p = 12;
  ck_assert_ldouble_infinite(s21_pow(num, p));
  ck_assert_ldouble_infinite(pow(num, p));
}
END_TEST

START_TEST(maximum) {
  double num = DBL_MAX;
  double p = -10;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

START_TEST(minimum) {
  double num = DBL_MIN;
  double p = 10;
  ck_assert_ldouble_eq_tol(pow(num, p), s21_pow(num, p), S21_TST);
}
END_TEST

Suite *suite_pow_2(void) {
  Suite *s2 = suite_create("suite_pow_2");
  TCase *tc2 = tcase_create("pow_tc_2");

  tcase_add_test(tc2, test_pos_1);
  tcase_add_test(tc2, test_pos_2);
  tcase_add_test(tc2, test_neg_pow_1);
  tcase_add_test(tc2, test_neg_num_odd_int_pow);
  tcase_add_test(tc2, test_neg_num_int_pow);
  tcase_add_test(tc2, test_neg_num_fract_pow);
  tcase_add_test(tc2, test_fractional_pow);
  tcase_add_test(tc2, test_fractional_pow_neg_num);
  tcase_add_loop_test(tc2, test_zero_power, 0, 6);
  tcase_add_loop_test(tc2, test_one_num, 0, 7);
  tcase_add_test(tc2, test_one_power);
  tcase_add_loop_test(tc2, test_nan_power, 0, 6);
  tcase_add_loop_test(tc2, test_nan_num, 0, 8);
  tcase_add_loop_test(tc2, test_neg_nan_power, 0, 6);
  tcase_add_loop_test(tc2, test_neg_nan_num, 0, 8);
  tcase_add_test(tc2, test_zero_neg_pow);
  tcase_add_test(tc2, test_zero_pos_pow);
  tcase_add_test(tc2, test_minus_one_inf_pow);
  tcase_add_test(tc2, test_fract_num_neg_inf_pow);
  tcase_add_test(tc2, test_fract_num_pos_inf_pow);
  tcase_add_test(tc2, test_num_neg_pos_pow);
  tcase_add_test(tc2, test_fract_num_pos_pow);
  tcase_add_test(tc2, test_num_inf_pow);
  tcase_add_test(tc2, test_pos_inf_neg_pow);
  tcase_add_test(tc2, test_neg_inf_pos_pow);
  tcase_add_test(tc2, test_neg_inf_pos_odd_pow);
  tcase_add_test(tc2, test_neg_inf_neg_pow);
  tcase_add_test(tc2, test_pos_inf_pos_pow);

  tcase_add_test(tc2, maximum);
  tcase_add_test(tc2, minimum);

  suite_add_tcase(s2, tc2);
  return s2;
}

START_TEST(s21_pow_test1) {
  ck_assert_double_eq_tol(s21_pow(20, 0.4), pow(20, 0.4), 0.000001);
}
END_TEST

START_TEST(s21_pow_test2) {
  ck_assert_double_nan(s21_pow(-20, 0.4));
  ck_assert_double_nan(pow(-20, 0.4));
}
END_TEST

START_TEST(s21_pow_test3) {
  ck_assert_double_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test4) {
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test5) {
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_test6) {
  ck_assert_double_nan(s21_pow(INFINITY, NAN));
  ck_assert_double_nan(pow(INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test7) {
  ck_assert_double_nan(s21_pow(NAN, INFINITY));
  ck_assert_double_nan(pow(NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_test8) {
  ck_assert_double_nan(s21_pow(-INFINITY, NAN));
  ck_assert_double_nan(pow(-INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test9) {
  ck_assert_double_nan(s21_pow(NAN, -INFINITY));
  ck_assert_double_nan(pow(NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test10) {
  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test11) {
  ck_assert_double_eq(s21_pow(INFINITY, -INFINITY), pow(INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test12) {
  ck_assert_double_eq_tol(s21_pow(12.69, 0), pow(12.69, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test13) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 3), pow(-20.63, 3), 0.000001);
}
END_TEST

START_TEST(s21_pow_test14) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 6), pow(-20.63, 6), 0.000001);
}
END_TEST

START_TEST(s21_pow_test15) {
  ck_assert_double_eq_tol(s21_pow(-INFINITY, 0), pow(-INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test16) {
  ck_assert_double_eq_tol(s21_pow(INFINITY, 0), pow(INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test17) {
  ck_assert_double_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test18) {
  ck_assert_double_eq(s21_pow(0, -INFINITY), pow(0, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test19) {
  ck_assert_double_eq_tol(s21_pow(0, INFINITY), pow(0, INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_pow_test20) {
  ck_assert_double_nan(s21_pow(0, NAN));
  ck_assert_double_nan(pow(0, NAN));
}
END_TEST

START_TEST(s21_pow_test21) { ck_assert_double_eq(s21_pow(0, 0), pow(0, 0)); }
END_TEST

START_TEST(s21_pow_test22) {
  ck_assert_double_eq(s21_pow(16894.2629, 1545), pow(16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test23) {
  ck_assert_double_eq(s21_pow(16894.2629, -1545), pow(16894.2629, -1545));
}
END_TEST

START_TEST(s21_pow_test24) {
  ck_assert_double_eq(s21_pow(-16894.2629, 1545), pow(-16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test25) {
  ck_assert_double_eq(s21_pow(-16894.2629, -1545), pow(-16894.2629, -1545));
}
END_TEST

Suite *suite_pow_3(void) {
  Suite *s3;
  TCase *tc3;
  s3 = suite_create("suite_pow_3");
  tc3 = tcase_create("pow_tc_3");
  tcase_add_test(tc3, s21_pow_test1);
  tcase_add_test(tc3, s21_pow_test2);
  tcase_add_test(tc3, s21_pow_test3);
  tcase_add_test(tc3, s21_pow_test4);
  tcase_add_test(tc3, s21_pow_test5);
  tcase_add_test(tc3, s21_pow_test6);
  tcase_add_test(tc3, s21_pow_test7);
  tcase_add_test(tc3, s21_pow_test8);
  tcase_add_test(tc3, s21_pow_test9);
  tcase_add_test(tc3, s21_pow_test10);
  tcase_add_test(tc3, s21_pow_test11);
  tcase_add_test(tc3, s21_pow_test12);
  tcase_add_test(tc3, s21_pow_test13);
  tcase_add_test(tc3, s21_pow_test14);
  tcase_add_test(tc3, s21_pow_test15);
  tcase_add_test(tc3, s21_pow_test16);
  tcase_add_test(tc3, s21_pow_test17);
  tcase_add_test(tc3, s21_pow_test18);
  tcase_add_test(tc3, s21_pow_test19);
  tcase_add_test(tc3, s21_pow_test20);
  tcase_add_test(tc3, s21_pow_test21);
  tcase_add_test(tc3, s21_pow_test22);
  tcase_add_test(tc3, s21_pow_test23);
  tcase_add_test(tc3, s21_pow_test24);
  tcase_add_test(tc3, s21_pow_test25);

  suite_add_tcase(s3, tc3);
  return s3;
}

START_TEST(exp_0) {
  double x = 0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_1) {
  double x = 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_2) {
  double x = 2;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = 1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = -1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = 0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = -0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = 715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = -715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_10) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = 'A';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = -'N';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'V';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = +'B';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_17) { ck_assert_float_eq(s21_exp(2), exp(2)); }
END_TEST

START_TEST(exp_18) { ck_assert_float_eq(s21_exp(-750), exp(-750)); }
END_TEST

START_TEST(exp_19) { ck_assert_float_eq(s21_exp(-2), exp(-2)); }
END_TEST

START_TEST(exp_20) {
  double num = NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_21) {
  double num = INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_22) {
  double num = -INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_23) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_24) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), S21_TST);
}
END_TEST

START_TEST(exp_25) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_26) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

START_TEST(exp_27) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_28) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_29) {
  double x = -100;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_30) {
  double x = -1000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_31) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_32) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), S21_TST);
}
END_TEST

START_TEST(exp_33) {
  double num = 1000000;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite *suite_s21_exp(void) {
  Suite *s7;
  TCase *tc7;
  s7 = suite_create("s21_exp");

  tc7 = tcase_create("case_exp");

  tcase_add_test(tc7, exp_0);
  tcase_add_test(tc7, exp_1);
  tcase_add_test(tc7, exp_2);
  tcase_add_test(tc7, exp_3);
  tcase_add_test(tc7, exp_4);
  tcase_add_test(tc7, exp_5);
  tcase_add_test(tc7, exp_6);
  tcase_add_test(tc7, exp_7);
  tcase_add_test(tc7, exp_8);
  tcase_add_test(tc7, exp_9);
  tcase_add_test(tc7, exp_10);
  tcase_add_test(tc7, exp_11);
  tcase_add_test(tc7, exp_12);
  tcase_add_test(tc7, exp_13);
  tcase_add_test(tc7, exp_14);
  tcase_add_test(tc7, exp_15);
  tcase_add_test(tc7, exp_16);
  tcase_add_test(tc7, exp_17);
  tcase_add_test(tc7, exp_18);
  tcase_add_test(tc7, exp_19);
  tcase_add_test(tc7, exp_20);
  tcase_add_test(tc7, exp_21);
  tcase_add_test(tc7, exp_22);
  tcase_add_test(tc7, exp_23);
  tcase_add_test(tc7, exp_24);
  tcase_add_test(tc7, exp_25);
  tcase_add_test(tc7, exp_26);
  tcase_add_test(tc7, exp_27);
  tcase_add_test(tc7, exp_28);
  tcase_add_test(tc7, exp_29);
  tcase_add_test(tc7, exp_30);
  tcase_add_test(tc7, exp_31);
  tcase_add_test(tc7, exp_32);
  tcase_add_test(tc7, exp_33);

  suite_add_tcase(s7, tc7);
  return s7;
}

START_TEST(log_1) {
  double num = 456.789;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
  double num = NAN;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
  double num = 0.001;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
  double num = 0.4;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
  double num = -INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
  double num = INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));

  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), S21_TST);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), S21_TST);
}
END_TEST

START_TEST(log_10) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), S21_TST);
}
END_TEST

START_TEST(log_11) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_TST); }
END_TEST

START_TEST(log_12) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), S21_TST);
}
END_TEST

START_TEST(log_13) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), S21_TST);
}
END_TEST

START_TEST(log_14) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), S21_TST);
}
END_TEST

START_TEST(log_15) {
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), S21_TST);
}
END_TEST

START_TEST(log_16) {
  ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), S21_TST);
}
END_TEST

START_TEST(log_17) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           S21_TST);
}
END_TEST

START_TEST(log_18) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           S21_TST);
}
END_TEST

START_TEST(log_19) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           S21_TST);
}
END_TEST

START_TEST(log_20) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), S21_TST);
}
END_TEST

START_TEST(log_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), S21_TST);
}
END_TEST

START_TEST(log_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), S21_TST);
}
END_TEST

START_TEST(log_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), S21_TST);
}
END_TEST

START_TEST(log_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), S21_TST);
}
END_TEST

START_TEST(log_21) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), S21_TST);
}
END_TEST

START_TEST(log_22) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), S21_TST);
}
END_TEST

START_TEST(log_23) {
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(log(0));
}
END_TEST

START_TEST(log_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), S21_TST);
}
END_TEST

START_TEST(log_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), S21_TST);
}
END_TEST

START_TEST(log_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), S21_TST);
}
END_TEST

START_TEST(log_31) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), S21_TST);
}
END_TEST

START_TEST(log_32) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), S21_TST);
}
END_TEST

START_TEST(log_33) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), S21_TST);
}
END_TEST

START_TEST(log_34) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), S21_TST);
}
END_TEST

Suite *suite_s21_log(void) {
  Suite *s11;
  TCase *tc11;
  s11 = suite_create("s21_log");
  tc11 = tcase_create("case_log");

  tcase_add_test(tc11, log_1);
  tcase_add_test(tc11, log_2);
  tcase_add_test(tc11, log_3);
  tcase_add_test(tc11, log_4);
  tcase_add_test(tc11, log_5);
  tcase_add_test(tc11, log_6);
  tcase_add_test(tc11, log_7);
  tcase_add_test(tc11, log_8);
  tcase_add_test(tc11, log_9);
  tcase_add_test(tc11, log_10);
  tcase_add_test(tc11, log_11);
  tcase_add_test(tc11, log_12);
  tcase_add_test(tc11, log_13);
  tcase_add_test(tc11, log_14);
  tcase_add_test(tc11, log_15);
  tcase_add_test(tc11, log_16);
  tcase_add_test(tc11, log_17);
  tcase_add_test(tc11, log_18);
  tcase_add_test(tc11, log_19);
  tcase_add_test(tc11, log_20);
  tcase_add_test(tc11, log_21);
  tcase_add_test(tc11, log_22);
  tcase_add_test(tc11, log_23);
  tcase_add_test(tc11, log_24);
  tcase_add_test(tc11, log_25);
  tcase_add_test(tc11, log_26);
  tcase_add_test(tc11, log_27);
  tcase_add_test(tc11, log_28);
  tcase_add_test(tc11, log_29);
  tcase_add_test(tc11, log_30);
  tcase_add_test(tc11, log_31);
  tcase_add_test(tc11, log_32);
  tcase_add_test(tc11, log_33);
  tcase_add_test(tc11, log_34);
  suite_add_tcase(s11, tc11);
  return s11;
}

START_TEST(sin_1) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_2) { ck_assert_float_eq(s21_sin(0), sin(0)); }
END_TEST

START_TEST(sin_3) {
  double num = 1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_4) {
  double num = -1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_5) {
  double num = 0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_6) {
  double num = -0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_7) {
  double num = NAN;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_8) {
  double num = INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_9) {
  double num = -INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_10) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), S21_TST);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sinl(-INFINITY));
}
END_TEST

START_TEST(sin_12) {
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sinl(INFINITY));
}
END_TEST

START_TEST(sin_13) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sinl(NAN));
}
END_TEST

START_TEST(sin_14) { ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), S21_TST); }
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), S21_TST);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), S21_TST);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), S21_TST);
}
END_TEST

START_TEST(sin_18) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), S21_TST);
}
END_TEST

START_TEST(sin_19) {
  ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), S21_TST);
}
END_TEST

START_TEST(sin_20) {
  ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), S21_TST);
}
END_TEST

START_TEST(sin_21) {
  ck_assert_double_eq_tol(s21_sin(-2 * M_PI), sin(-2 * M_PI), S21_TST);
}
END_TEST

START_TEST(sin_22) {
  ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), S21_TST);
}
END_TEST

START_TEST(sin_23) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          S21_TST);
}
END_TEST

START_TEST(sin_24) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          S21_TST);
}
END_TEST

START_TEST(sin_25) {
  ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), S21_TST);
}
END_TEST

Suite *suite_s21_sin(void) {
  Suite *s14;
  TCase *tc14;
  s14 = suite_create("s21_sin");
  tc14 = tcase_create("case_sin");

  tcase_add_test(tc14, sin_1);
  tcase_add_test(tc14, sin_2);
  tcase_add_test(tc14, sin_3);
  tcase_add_test(tc14, sin_4);
  tcase_add_test(tc14, sin_5);
  tcase_add_test(tc14, sin_6);
  tcase_add_test(tc14, sin_7);
  tcase_add_test(tc14, sin_8);
  tcase_add_test(tc14, sin_9);
  tcase_add_test(tc14, sin_10);
  tcase_add_test(tc14, sin_11);
  tcase_add_test(tc14, sin_12);
  tcase_add_test(tc14, sin_13);
  tcase_add_test(tc14, sin_14);
  tcase_add_test(tc14, sin_15);
  tcase_add_test(tc14, sin_16);
  tcase_add_test(tc14, sin_17);
  tcase_add_test(tc14, sin_18);
  tcase_add_test(tc14, sin_19);
  tcase_add_test(tc14, sin_20);
  tcase_add_test(tc14, sin_21);
  tcase_add_test(tc14, sin_22);
  tcase_add_test(tc14, sin_23);
  tcase_add_test(tc14, sin_24);
  tcase_add_test(tc14, sin_25);

  suite_add_tcase(s14, tc14);
  return s14;
}

START_TEST(cos_1) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
  double num = -0.999999;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
  double num = 628;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
  double num = NAN;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_7) {
  double num = INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_8) {
  double num = -INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_9) {
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cosl(x), S21_TST);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cosl(-INFINITY));
}
END_TEST

START_TEST(cos_11) {
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cosl(INFINITY));
}
END_TEST

START_TEST(cos_12) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cosl(NAN));
}
END_TEST

START_TEST(cos_13) {
  ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), S21_TST);
}
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), S21_TST);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), S21_TST);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), S21_TST);
}
END_TEST

START_TEST(cos_17) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), S21_TST);
}
END_TEST

START_TEST(cos_18) {
  ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), S21_TST);
}
END_TEST

START_TEST(cos_19) {
  ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), S21_TST);
}
END_TEST

START_TEST(cos_20) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                          S21_TST);
}
END_TEST

START_TEST(cos_21) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                          S21_TST);
}
END_TEST

Suite *suite_s21_cos(void) {
  Suite *s15;
  TCase *tc15;
  s15 = suite_create("s21_cos");
  tc15 = tcase_create("case_cos");

  tcase_add_test(tc15, cos_1);
  tcase_add_test(tc15, cos_2);
  tcase_add_test(tc15, cos_3);
  tcase_add_test(tc15, cos_4);
  tcase_add_test(tc15, cos_5);
  tcase_add_test(tc15, cos_6);
  tcase_add_test(tc15, cos_7);
  tcase_add_test(tc15, cos_8);
  tcase_add_test(tc15, cos_9);
  tcase_add_test(tc15, cos_10);
  tcase_add_test(tc15, cos_11);
  tcase_add_test(tc15, cos_12);
  tcase_add_test(tc15, cos_13);
  tcase_add_test(tc15, cos_14);
  tcase_add_test(tc15, cos_15);
  tcase_add_test(tc15, cos_16);
  tcase_add_test(tc15, cos_17);
  tcase_add_test(tc15, cos_18);
  tcase_add_test(tc15, cos_19);
  tcase_add_test(tc15, cos_20);
  tcase_add_test(tc15, cos_21);

  suite_add_tcase(s15, tc15);
  return s15;
}

START_TEST(tan_1) { ck_assert_float_eq(s21_tan(-15.01), tan(-15.01)); }
END_TEST

START_TEST(tan_2) {
  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= S21_TST)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(tan_4) {
  double num = NAN;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_5) {
  double num = INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_6) {
  double num = -INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_7) {
  double x = 0;
  ck_assert_double_eq_tol(s21_tan(x), tanl(x), S21_TST);
}
END_TEST

START_TEST(tan_8) {
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tanl(-INFINITY));
}
END_TEST

START_TEST(tan_9) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tanl(INFINITY));
}
END_TEST

START_TEST(tan_10) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tanl(NAN));
}
END_TEST

START_TEST(tan_11) {
  ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), S21_TST);
}
END_TEST

START_TEST(tan_12) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), S21_TST);
}
END_TEST

START_TEST(tan_13) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), S21_TST);
}
END_TEST

START_TEST(tan_14) {
  ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), S21_TST);
}
END_TEST

START_TEST(tan_15) {
  ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), S21_TST);
}
END_TEST

START_TEST(tan_16) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), S21_TST);
}
END_TEST

START_TEST(tan_17) {
  ck_assert_double_eq_tol(s21_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), S21_TST);
}
END_TEST

START_TEST(tan_18) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                          S21_TST);
}
END_TEST

START_TEST(tan_19) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                          S21_TST);
}
END_TEST

START_TEST(tan_20) {
  ck_assert_double_eq_tol(s21_tan(S21_PI / 2), tanl(S21_PI / 2), S21_TST);
}
END_TEST

START_TEST(tan_21) {
  ck_assert_double_eq_tol(s21_tan(-S21_PI / 2), tanl(-S21_PI / 2), S21_TST);
}
END_TEST

Suite *suite_s21_tan(void) {
  Suite *s16;
  TCase *tc16;
  s16 = suite_create("s21_tan");
  tc16 = tcase_create("case_tan");

  tcase_add_test(tc16, tan_1);
  tcase_add_test(tc16, tan_2);
  tcase_add_test(tc16, tan_3);
  tcase_add_test(tc16, tan_4);
  tcase_add_test(tc16, tan_5);
  tcase_add_test(tc16, tan_6);
  tcase_add_test(tc16, tan_7);
  tcase_add_test(tc16, tan_8);
  tcase_add_test(tc16, tan_9);
  tcase_add_test(tc16, tan_10);
  tcase_add_test(tc16, tan_11);
  tcase_add_test(tc16, tan_12);
  tcase_add_test(tc16, tan_13);
  tcase_add_test(tc16, tan_14);
  tcase_add_test(tc16, tan_15);
  tcase_add_test(tc16, tan_16);
  tcase_add_test(tc16, tan_17);
  tcase_add_test(tc16, tan_18);
  tcase_add_test(tc16, tan_19);
  tcase_add_test(tc16, tan_20);
  tcase_add_test(tc16, tan_21);

  suite_add_tcase(s16, tc16);
  return s16;
}

int main(void) {
  t1();
  t2();
  t3();
  t4();
  t5();
  t6();
  t7();
  t8();

  Suite *s = suite_sqrt();
  Suite *s1 = suite_pow_1();
  Suite *s2 = suite_pow_2();
  Suite *s3 = suite_pow_3();
  Suite *s7 = suite_s21_exp();
  Suite *s11 = suite_s21_log();
  Suite *s14 = suite_s21_sin();
  Suite *s15 = suite_s21_cos();
  Suite *s16 = suite_s21_tan();
  SRunner *sr = srunner_create(s);
  SRunner *sr1 = srunner_create(s1);
  SRunner *sr2 = srunner_create(s2);
  SRunner *sr3 = srunner_create(s3);
  SRunner *sr7 = srunner_create(s7);
  SRunner *sr11 = srunner_create(s11);
  SRunner *sr14 = srunner_create(s14);
  SRunner *sr15 = srunner_create(s15);
  SRunner *sr16 = srunner_create(s16);

  int nf;
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  srunner_run_all(sr1, CK_NORMAL);
  nf = srunner_ntests_failed(sr1);
  srunner_free(sr1);
  srunner_run_all(sr2, CK_NORMAL);
  nf = srunner_ntests_failed(sr2);
  srunner_free(sr2);
  srunner_run_all(sr3, CK_NORMAL);
  nf = srunner_ntests_failed(sr3);
  srunner_free(sr3);
  srunner_run_all(sr7, CK_NORMAL);
  nf = srunner_ntests_failed(sr7);
  srunner_free(sr7);
  srunner_run_all(sr11, CK_NORMAL);
  nf = srunner_ntests_failed(sr11);
  srunner_free(sr11);
  srunner_run_all(sr14, CK_NORMAL);
  nf = srunner_ntests_failed(sr14);
  srunner_free(sr14);
  srunner_run_all(sr15, CK_NORMAL);
  nf = srunner_ntests_failed(sr15);
  srunner_free(sr15);
  srunner_run_all(sr16, CK_NORMAL);
  nf = srunner_ntests_failed(sr16);
  srunner_free(sr16);

  return nf == 0 ? 0 : 1;
}