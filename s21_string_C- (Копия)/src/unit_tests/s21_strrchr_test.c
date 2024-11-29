#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strrchr_returns_last_occurrence_of_character) {
  const char *str = "Verter";
  int ch = 'e';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_null_when_character_not_found) {
  const char *str = "Verter";
  int ch = 'x';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_null_with_empty_str) {
  const char *str = "";
  int ch = 'e';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_last_occurrence_with_null_character) {
  const char *str = "Verter";
  int ch = '\0';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_last_occurrence_with_single_character) {
  const char *str = "e";
  int ch = 'e';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_null_with_single_character) {
  const char *str = "e";
  int ch = 'x';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_last_occurrence_with_multiple_characters) {
  const char *str = "Verter pls 100%)";
  int ch = 'p';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_returns_null_with_multiple_characters) {
  const char *str = "Verter pls 100%)";
  int ch = 'x';
  char *s21_result = s21_strrchr(str, ch);
  char *strrchr_result = strrchr(str, ch);
  ck_assert_ptr_eq(s21_result, strrchr_result);
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strrchr\033[0m");

  TCase *test_case = tcase_create("strrchr");
  tcase_add_test(test_case,
                 test_s21_strrchr_returns_last_occurrence_of_character);
  tcase_add_test(test_case,
                 test_s21_strrchr_returns_null_when_character_not_found);
  tcase_add_test(test_case, test_s21_strrchr_returns_null_with_empty_str);
  tcase_add_test(test_case,
                 test_s21_strrchr_returns_last_occurrence_with_null_character);
  tcase_add_test(
      test_case,
      test_s21_strrchr_returns_last_occurrence_with_single_character);
  tcase_add_test(test_case,
                 test_s21_strrchr_returns_null_with_single_character);
  tcase_add_test(
      test_case,
      test_s21_strrchr_returns_last_occurrence_with_multiple_characters);
  tcase_add_test(test_case,
                 test_s21_strrchr_returns_null_with_multiple_characters);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strrchr_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}