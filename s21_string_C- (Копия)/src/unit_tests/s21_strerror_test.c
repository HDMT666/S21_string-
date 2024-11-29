#include <check.h>
#include <string.h>

#include "../s21_string.h"

int test_values[9] = {0, 1, -1, -2, 10, 150, -150, -30};

START_TEST(strerror_test_01) {
  for (int i = -200; i <= 200; i++) {
    // printf("i = %d\n",i);
    char *str1 = s21_strerror(i);
    char *str2 = strerror(i);
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_strerror_test) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(1);
  char *case10 = strerror(1);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(200);
  char *case8 = strerror(200);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  int err = -2;
  char *case11 = s21_strerror(err);
  char *case12 = strerror(err);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST

START_TEST(strerror_1) {
  int err_num = -5;
  ck_assert_str_eq(s21_strerror(err_num), strerror(err_num));
}
END_TEST

START_TEST(strerror_2) {
  for (int i = -300; i < 0; i++) {
    char *str1 = s21_strerror(i);
    char *str2 = strerror(i);
    ck_assert_str_eq(str1, str2);
  }
}

START_TEST(strerror_3) {
  int err_num = -10;
  ck_assert_str_eq(s21_strerror(err_num), strerror(err_num));
}
END_TEST

START_TEST(test_floor1) {
  ck_assert_str_eq(s21_strerror(test_values[_i]), strerror(test_values[_i]));
}
END_TEST

Suite *strerror_suite() {
  Suite *suite = suite_create("\033[32ms21_strerror\033[0m");
  TCase *tcase_core = tcase_create("strerror");

  tcase_add_test(tcase_core, strerror_test_01);
  tcase_add_test(tcase_core, strerror_1);
  tcase_add_test(tcase_core, strerror_2);
  tcase_add_test(tcase_core, strerror_3);
  tcase_add_test(tcase_core, s21_strerror_test);
  tcase_add_loop_test(tcase_core, test_floor1, 0, 8);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main() {
  Suite *suite = strerror_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}