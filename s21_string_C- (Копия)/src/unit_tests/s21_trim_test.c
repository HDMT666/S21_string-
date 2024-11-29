#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_trim) {
  // Empty src and trim_chars
  {
    char *result = s21_trim("", "");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test case with emtpy source string
  {
    char *result = s21_trim("", "abcdefg");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Test case with empty trim chars
  {
    char *result = s21_trim("one more message", "");
    ck_assert_str_eq(result, "one more message");
    free(result);
  }

  // Test case with src equal trim_chars
  {
    char *result = s21_trim("one more message", "one more message");
    ck_assert_str_eq(result, "");
    free(result);
  }

  // Another tests...
  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
    ck_assert_str_eq(result, "Abo+ba");
    free(result);
  }

  {
    char *result = s21_trim("Ab000cd0", "003");
    ck_assert_str_eq(result, "Ab000cd");
    free(result);
  }

  {
    char *result = s21_trim("DoNotTouch", "Not");
    ck_assert_str_eq(result, "DoNotTouch");
    free(result);
  }

  {
    char *result = s21_trim(" Good morning!    ", " ");
    ck_assert_str_eq(result, "Good morning!");
    free(result);
  }

  {
    char *result = s21_trim(" qwertyuiop ", NULL);
    ck_assert_str_eq(result, "qwertyuiop");
    free(result);
  }
}
END_TEST

Suite *trim_suite(void) {
  Suite *suite = suite_create("\033[32ms21_trim\033[0m");

  TCase *test_case = tcase_create("trim");

  tcase_add_test(test_case, test_trim);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = trim_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}