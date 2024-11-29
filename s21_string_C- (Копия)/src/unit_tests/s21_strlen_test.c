#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_strlen_empty_string) {
  const char *str = "";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_short_string) {
  const char *str = "Hello";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_long_string) {
  const char *str = "UUF KAKIE BARKHATNIE TIYAGI KEFTEME";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_whitespace) {
  const char *str = "   Hello, World!   ";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_null_byte) {
  const char *str = "Hello\0World";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_unicode_characters) {
  const char *str = "Привет, мир!";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_escape_sequence) {
  const char *str = "Hello\tWorld\n";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_special_characters) {
  const char *str = "!@#$%^&*()";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_multibyte_characters) {
  const char *str = "Э асаламу алейкум！";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_string_with_embedded_null_byte) {
  const char *str = "Hello\0World";
  s21_size_t expected = 5;
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *strlen_suite(void) {
  Suite *suite = suite_create("\033[32ms21_strlen\033[0m");

  TCase *test_case = tcase_create("strlen");
  tcase_add_test(test_case, test_strlen_empty_string);
  tcase_add_test(test_case, test_strlen_short_string);
  tcase_add_test(test_case, test_strlen_long_string);
  tcase_add_test(test_case, test_strlen_string_with_whitespace);
  tcase_add_test(test_case, test_strlen_string_with_null_byte);
  tcase_add_test(test_case, test_strlen_string_with_unicode_characters);
  tcase_add_test(test_case, test_strlen_string_with_escape_sequence);
  tcase_add_test(test_case, test_strlen_string_with_special_characters);
  tcase_add_test(test_case, test_strlen_string_with_multibyte_characters);
  tcase_add_test(test_case, test_strlen_string_with_embedded_null_byte);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = strlen_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}