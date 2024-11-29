#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strcspn_matches_strcspn_with_no_common_characters) {
  const char *str = "Verter";
  const char *reject = "-_-";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_reject_at_beginning) {
  const char *str = "AUF";
  const char *reject = "-_-";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_reject_at_end) {
  const char *str = "Kefteme";
  const char *reject = "100%)";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_reject_in_middle) {
  const char *str = "Verter pls 100%)";
  const char *reject = "-_-";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_empty_str_and_reject) {
  const char *str = "";
  const char *reject = "";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_empty_reject) {
  const char *str = "Verter pls 100%)";
  const char *reject = "";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_empty_str) {
  const char *str = "";
  const char *reject = "-_-";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_same_str_and_reject) {
  const char *str = "Verter";
  const char *reject = "Verter";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_multiple_reject_characters) {
  const char *str = "AUF";
  const char *reject = "-_-123";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_large_str_and_reject) {
  const char *str = "Verter pls 100%)";
  const char *reject = "XYZ";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

START_TEST(test_s21_strcspn_matches_strcspn_with_large_reject) {
  const char *str = "Verter";
  const char *reject = "XYZXYZXYZXYZ";
  s21_size_t s21_result = s21_strcspn(str, reject);
  s21_size_t strcspn_result = strcspn(str, reject);
  ck_assert_int_eq(s21_result, strcspn_result);
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strcspn\033[0m");

  TCase *test_case = tcase_create("strcspn");
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_no_common_characters);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_reject_at_beginning);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_reject_at_end);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_reject_in_middle);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_empty_str_and_reject);
  tcase_add_test(test_case, test_s21_strcspn_matches_strcspn_with_empty_str);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_same_str_and_reject);
  tcase_add_test(
      test_case,
      test_s21_strcspn_matches_strcspn_with_multiple_reject_characters);
  tcase_add_test(test_case,
                 test_s21_strcspn_matches_strcspn_with_large_str_and_reject);
  tcase_add_test(test_case, test_s21_strcspn_matches_strcspn_with_large_reject);
  suite_add_tcase(suite, test_case);
  tcase_add_test(test_case, test_s21_strcspn_matches_strcspn_with_empty_reject);

  return suite;
}

int main() {
  Suite *suite = strcspn_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}