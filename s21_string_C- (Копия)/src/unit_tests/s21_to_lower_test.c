#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_to_lower_test) {
  char str1[] = "I'M jUST a rEGULAR eVERY DAy";
  char str2[] = "SALAMVERTERPIDOR";
  char str3[] = "";
  char str4[] = "A";
  char *str = s21_to_lower(str1);

  if (str) {
    ck_assert_str_eq(str, "i'm just a regular every day");
    free(str);
  }

  str = s21_to_lower(str2);

  if (str) {
    ck_assert_str_eq(str, "salamverterpidor");
    free(str);
  }

  str = s21_to_lower(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_lower(str4);

  if (str) {
    ck_assert_str_eq(str, "a");
    free(str);
  }
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s = suite_create("\033[32ms21_to_lower\033[0m");
  TCase *tc = tcase_create("to_lower");

  tcase_add_test(tc, s21_to_lower_test);

  suite_add_tcase(s, tc);
  return s;
}

int main() {
  Suite *suite = to_lower_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failures == 0 ? 0 : 1;
}