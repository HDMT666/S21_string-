#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strstr_finds_substring_in_string) {
  const char *str = "Verter pls 100%)";
  const char *substr = "pls";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

START_TEST(test_s21_strstr_returns_null_with_empty_substring) {
  const char *str = "AUF";
  const char *substr = "";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

START_TEST(test_s21_strstr_returns_null_when_substring_not_found) {
  const char *str = "Verter pls 100%)";
  const char *substr = "AUF";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

START_TEST(test_s21_strstr_returns_same_pointer_for_full_string_and_substring) {
  const char *str = "Verter";
  const char *substr = "Verter";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

START_TEST(
    test_s21_strstr_returns_same_pointer_when_substring_is_null_character) {
  const char *str = "Verter";
  const char *substr = "\0";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

START_TEST(
    test_s21_strstr_returns_null_when_both_string_and_substring_are_null_character) {
  const char *str = "\0";
  const char *substr = "\0";
  char *s21_result = s21_strstr(str, substr);
  char *strstr_result = strstr(str, substr);
  ck_assert_ptr_eq(s21_result, strstr_result);
}
END_TEST

Suite *strstr_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strstr\033[0m");

  TCase *test_case = tcase_create("strstr");
  tcase_add_test(test_case, test_s21_strstr_finds_substring_in_string);
  tcase_add_test(test_case, test_s21_strstr_returns_null_with_empty_substring);
  tcase_add_test(test_case,
                 test_s21_strstr_returns_null_when_substring_not_found);
  tcase_add_test(
      test_case,
      test_s21_strstr_returns_same_pointer_for_full_string_and_substring);
  tcase_add_test(
      test_case,
      test_s21_strstr_returns_same_pointer_when_substring_is_null_character);

  tcase_add_test(
      test_case,
      test_s21_strstr_returns_null_when_both_string_and_substring_are_null_character);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strstr_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}