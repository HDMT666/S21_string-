#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memcmp_matches_memcmp) {
  char str1[] = "Zdarova Verter -_-";
  char str2[] = "Zdarova Verter -_-";
  s21_size_t size = strlen(str1) + 1;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_different_strings) {
  char str1[] = "HelloU";
  char str2[] = "Verter";
  s21_size_t size = strlen(str1) + 1;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_zero_length) {
  char str1[] = "Hello";
  char str2[] = "Zaibal";
  s21_size_t size = 0;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_large_memory_blocks) {
  s21_size_t size = 1 << 20;  // 1 MB
  char *block1 = malloc(size);
  char *block2 = malloc(size);
  memset(block1, 'A', size);
  memset(block2, 'B', size);

  int s21_result = s21_memcmp(block1, block2, size);
  int memcmp_result = memcmp(block1, block2, size);

  ck_assert_int_eq(s21_result, memcmp_result);

  free(block1);
  free(block2);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_partial_comparison) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, Verter!";
  s21_size_t size = 7;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_unsigned_char) {
  unsigned char str1[] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFB};
  unsigned char str2[] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFA};
  s21_size_t size = sizeof(str1);

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_special_characters) {
  char str1[] = "Hello, \nVerter!";
  char str2[] = "Hello, \tVerter!";
  s21_size_t size = strlen(str1) + 1;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_negative_result) {
  char str1[] = "abc";
  char str2[] = "def";
  s21_size_t size = strlen(str1) + 1;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST

START_TEST(test_s21_memcmp_matches_memcmp_with_positive_result) {
  char str1[] = "ALE TUT KEWF";
  char str2[] = "IDI TI VETER";
  s21_size_t size = strlen(str1) + 1;

  int s21_result = s21_memcmp(str1, str2, size);
  int memcmp_result = memcmp(str1, str2, size);

  ck_assert_int_eq(s21_result, memcmp_result);
}
END_TEST
Suite *memcmp_suite(void) {
  Suite *suite = suite_create("\033[32ms21_memcmp\033[0m");

  TCase *test_case = tcase_create("memcmp");
  tcase_add_test(test_case, test_s21_memcmp_matches_memcmp);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_different_strings);
  tcase_add_test(test_case, test_s21_memcmp_matches_memcmp_with_zero_length);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_large_memory_blocks);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_partial_comparison);
  tcase_add_test(test_case, test_s21_memcmp_matches_memcmp_with_unsigned_char);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_special_characters);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_negative_result);
  tcase_add_test(test_case,
                 test_s21_memcmp_matches_memcmp_with_positive_result);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = memcmp_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}