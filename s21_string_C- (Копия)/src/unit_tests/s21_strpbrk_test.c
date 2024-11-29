#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strpbrk_matches_strpbrk_with_no_common_characters) {
  const char *str = "Verter";
  const char *accept = "-_-";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_accept_at_beginning) {
  const char *str = "AUF";
  const char *accept = "-_-";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_accept_at_end) {
  const char *str = "Kefteme";
  const char *accept = "100%)";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_accept_in_middle) {
  const char *str = "Verter pls 100%)";
  const char *accept = "-_-";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_empty_str_and_accept) {
  const char *str = "";
  const char *accept = "";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_empty_accept) {
  const char *str = "Verter pls 100%)";
  const char *accept = "";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_empty_str) {
  const char *str = "";
  const char *accept = "-_-";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_same_str_and_accept) {
  const char *str = "Verter";
  const char *accept = "Verter";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result = strpbrk(str, accept);
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_null_str) {
  const char *str = s21_NULL;
  const char *accept = "-_-";
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result =
      (str != s21_NULL && accept != s21_NULL) ? strpbrk(str, accept) : s21_NULL;
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_null_accept) {
  const char *str = "Verter pls 100%)";
  const char *accept = s21_NULL;
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result =
      (str != s21_NULL && accept != s21_NULL) ? strpbrk(str, accept) : s21_NULL;
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

START_TEST(test_s21_strpbrk_matches_strpbrk_with_null_str_and_accept) {
  const char *str = s21_NULL;
  const char *accept = s21_NULL;
  char *s21_result = s21_strpbrk(str, accept);
  char *strpbrk_result =
      (str != s21_NULL && accept != s21_NULL) ? strpbrk(str, accept) : s21_NULL;
  ck_assert_ptr_eq(s21_result, strpbrk_result);
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strpbrk\033[0m");

  TCase *test_case = tcase_create("strpbrk");
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_no_common_characters);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_accept_at_beginning);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_accept_at_end);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_accept_in_middle);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_empty_str_and_accept);
  tcase_add_test(test_case, test_s21_strpbrk_matches_strpbrk_with_empty_str);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_same_str_and_accept);
  tcase_add_test(test_case, test_s21_strpbrk_matches_strpbrk_with_null_str);
  tcase_add_test(test_case, test_s21_strpbrk_matches_strpbrk_with_null_accept);
  tcase_add_test(test_case,
                 test_s21_strpbrk_matches_strpbrk_with_null_str_and_accept);
  tcase_add_test(test_case, test_s21_strpbrk_matches_strpbrk_with_empty_accept);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strpbrk_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}