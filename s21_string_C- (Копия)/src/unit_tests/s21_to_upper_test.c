#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_to_upper_valid_input) {
  const char *input = "hello, world!";
  const char *expected_output = "HELLO, WORLD!";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(test_s21_to_upper_empty_input) {
  const char *input = "";
  const char *expected_output = "";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(test_s21_to_upper_letters_and_numbers) {
  char input[] = "abc123abc";
  const char *expected_output = "ABC123ABC";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(test_s21_to_upper_uppercase_input) {
  char input[] = "ABShshsh";
  const char *expected_output = "ABSHSHSH";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(test_s21_to_upper_null_input) {
  const char *input = s21_NULL;

  void *result = s21_to_upper(input);

  ck_assert_msg(result == s21_NULL, "Result should be NULL");
}
END_TEST

START_TEST(test_s21_to_upper_all_upper_input) {
  const char *input = "HELLO, WORLD!";
  const char *expected_output = "HELLO, WORLD!";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(test_s21_to_upper_lowercase) {
  const char *input = "abs";
  const char *expected_output = "ABS";

  void *result = s21_to_upper(input);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *uppercase_str = (char *)result;
  ck_assert_str_eq(uppercase_str, expected_output);

  free(uppercase_str);
}
END_TEST

START_TEST(uppercase) {
  char *s21_str = "abc";

  ck_assert_str_eq(s21_to_upper(s21_str), "ABC");
}
END_TEST

START_TEST(Letter) {
  char *str1 = "Another\n one SenTenCE\t wWith\0 words";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "ANOTHER\n ONE SENTENCE\t WWITH");
  free(result);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s = suite_create("\033[32ms21_to_upper\033[0m");
  TCase *tc = tcase_create("to_upper");

  tcase_add_test(tc, test_s21_to_upper_valid_input);
  tcase_add_test(tc, test_s21_to_upper_empty_input);
  tcase_add_test(tc, test_s21_to_upper_letters_and_numbers);
  tcase_add_test(tc, test_s21_to_upper_uppercase_input);
  tcase_add_test(tc, test_s21_to_upper_null_input);
  tcase_add_test(tc, test_s21_to_upper_all_upper_input);
  tcase_add_test(tc, test_s21_to_upper_lowercase);
  tcase_add_test(tc, uppercase);
  tcase_add_test(tc, Letter);

  suite_add_tcase(s, tc);
  return s;
}

int main() {
  Suite *suite = to_upper_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_FORK);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}