#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_strncpy_matches_strncpy_with_full_copy) {
  const char *src = "Verter";
  char dest[10] = "";
  s21_size_t n = 6;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_partial_copy) {
  const char *src = "Verter, -_-";
  char dest[10] = "";
  s21_size_t n = 6;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_null_terminator_in_src) {
  const char *src = "AUF\0Kefteme";
  char dest[10] = "";
  s21_size_t n = 10;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_null_padding) {
  const char *src = "Kefteme";
  char dest[10] = "12345";
  s21_size_t n = 10;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_empty_src) {
  const char *src = "";
  char dest[10] = "12345";
  s21_size_t n = 5;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_dest_larger_than_n) {
  const char *src = "Verter, pls 100%";
  char dest[20] = "123456789123456789";
  s21_size_t n = 5;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_dest_smaller_than_n) {
  const char *src = "Verter, -_-";
  char dest[15] = "";
  s21_size_t n = 10;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_src_same_pointer_as_dest) {
  char src[10] = "Verter";
  char dest[10] = "";
  size_t n = 6;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_n_greater_than_src_length) {
  const char *src = "Verter";
  char dest[10] = "";
  s21_size_t n = 10;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_n_less_than_src_length) {
  const char *src = "Verter, pls 100%";
  char dest[10] = "";
  s21_size_t n = 6;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_n_equal_to_zero) {
  const char *src = "Verter";
  char dest[10] = "";
  s21_size_t n = 0;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
}
END_TEST

START_TEST(test_s21_strncpy_matches_strncpy_with_dest_null_terminated) {
  const char *src = "Verter";
  char dest[10] = "12345";
  s21_size_t n = 6;

  char *s21_result = s21_strncpy(dest, src, n);
  char *strncpy_result = strncpy(dest, src, n);

  ck_assert_str_eq(s21_result, strncpy_result);
  ck_assert(dest[n] == '\0');
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strncpy\033[0m");

  TCase *test_case = tcase_create("strncpy");
  tcase_add_test(test_case, test_s21_strncpy_matches_strncpy_with_full_copy);
  tcase_add_test(test_case, test_s21_strncpy_matches_strncpy_with_partial_copy);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_null_terminator_in_src);
  tcase_add_test(test_case, test_s21_strncpy_matches_strncpy_with_null_padding);
  tcase_add_test(test_case, test_s21_strncpy_matches_strncpy_with_empty_src);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_dest_larger_than_n);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_dest_smaller_than_n);
  tcase_add_test(
      test_case,
      test_s21_strncpy_matches_strncpy_with_src_same_pointer_as_dest);
  tcase_add_test(
      test_case,
      test_s21_strncpy_matches_strncpy_with_n_greater_than_src_length);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_n_less_than_src_length);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_n_equal_to_zero);
  tcase_add_test(test_case,
                 test_s21_strncpy_matches_strncpy_with_dest_null_terminated);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strncpy_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}