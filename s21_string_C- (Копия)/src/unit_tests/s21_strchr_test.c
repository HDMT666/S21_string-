#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strchr_matches_strchr_with_existing_character) {
  const char *str = "Zaibal Verter";
  int c = 'V';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_nonexistent_character) {
  const char *str = "Zaibal Verter";
  int c = 'Z';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_null_character) {
  const char *str = "Zaibal Verter";
  int c = '\0';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_empty_string) {
  const char *str = "";
  int c = 'A';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_single_character_string) {
  const char *str = "X";
  int c = 'X';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_multiple_occurrences) {
  const char *str = "EEE VERTER LOH";
  int c = 'O';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_null_terminator_in_middle) {
  const char *str = "Salam\0-_-_-_";
  int c = '_';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_null_terminator_at_end) {
  const char *str = "Pidor, Verter\0";
  int c = '\0';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_case_sensitive_comparison) {
  const char *str = "UUUF Kefteme";
  int c = 'u';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

START_TEST(test_s21_strchr_matches_strchr_with_case_insensitive_comparison) {
  const char *str = "UUU kakie barkhatnie";
  int c = 'K';

  char *s21_result = s21_strchr(str, c);
  char *strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_result, strchr_result);
}
END_TEST

Suite *strchr_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strchr\033[0m");

  TCase *test_case = tcase_create("strchr");
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_existing_character);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_nonexistent_character);
  tcase_add_test(test_case, test_s21_strchr_matches_strchr_with_null_character);
  tcase_add_test(test_case, test_s21_strchr_matches_strchr_with_empty_string);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_single_character_string);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_multiple_occurrences);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_null_terminator_in_middle);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_null_terminator_at_end);
  tcase_add_test(test_case,
                 test_s21_strchr_matches_strchr_with_case_sensitive_comparison);
  tcase_add_test(
      test_case,
      test_s21_strchr_matches_strchr_with_case_insensitive_comparison);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strchr_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}