#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_insert_valid_input) {
  const char *src = "Hello, world!";
  const char *str = "OpenAI, ";
  s21_size_t start_index = 7;

  const char *expected_output = "Hello, OpenAI, world!";

  void *result = s21_insert(src, str, start_index);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *inserted_str = (char *)result;
  ck_assert_str_eq(inserted_str, expected_output);

  free(inserted_str);
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  const char *src = "";
  const char *str = "Hello";
  s21_size_t start_index = 0;

  const char *expected_output = "Hello";

  void *result = s21_insert(src, str, start_index);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *inserted_str = (char *)result;
  ck_assert_str_eq(inserted_str, expected_output);

  free(inserted_str);
}
END_TEST

START_TEST(test_s21_insert_empty_str) {
  const char *src = "Hello, world!";
  const char *str = " ";
  s21_size_t start_index = 7;

  const char *expected_output = "Hello,  world!";

  void *result = s21_insert(src, str, start_index);

  ck_assert_msg(result != NULL, "Result should not be NULL");

  char *inserted_str = (char *)result;
  ck_assert_str_eq(inserted_str, expected_output);

  free(inserted_str);
}
END_TEST

START_TEST(test_s21_insert_start_index_out_of_bounds) {
  const char *src = "Hello, world!";
  const char *str = " OpenAI";
  s21_size_t start_index = 15;

  void *result = s21_insert(src, str, start_index);

  ck_assert_msg(result == NULL, "Result should be NULL");
}
END_TEST

Suite *insert_suite(void) {
  Suite *suite = suite_create("\033[32ms21_insert\033[0m");

  TCase *test_case = tcase_create("insert");

  tcase_add_test(test_case, test_s21_insert_valid_input);
  tcase_add_test(test_case, test_s21_insert_empty_src);
  tcase_add_test(test_case, test_s21_insert_empty_str);
  tcase_add_test(test_case, test_s21_insert_start_index_out_of_bounds);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = insert_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}