#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memchr_matches_memchr) {
  char str[] = "Zdarova Zaibal";
  int character = 'a';
  s21_size_t size = strlen(str);

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_zero_length) {
  char str[] = "";
  int character = 'A';
  s21_size_t size = 0;

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_null_terminator) {
  char str[] = "Verter Zaibal -_-";
  int character = '\0';
  s21_size_t size = strlen(str) + 1;

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_large_memory_blocks) {
  s21_size_t size = 1 << 20;  // 1 MB
  char *block = malloc(size);
  memset(block, 'A', size);
  block[size - 1] = 'B';
  int character = 'B';

  void *s21_result = s21_memchr(block, character, size);
  void *memchr_result = memchr(block, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
  free(block);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_unsigned_char) {
  unsigned char str[] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFB};
  int character = 0xFD;
  s21_size_t size = sizeof(str);

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_special_characters) {
  char str[] = "Hello, \nWorld!";
  int character = '\n';
  s21_size_t size = strlen(str);

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_character_zero) {
  char str[] = "Hello, World!";
  int character = 0;
  s21_size_t size = strlen(str);

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

START_TEST(test_s21_memchr_matches_memchr_with_large_character_set) {
  char str[256];
  for (int i = 0; i < 256; i++) {
    str[i] = (char)i;
  }
  int character = 127;
  s21_size_t size = sizeof(str);

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);
}
END_TEST

// Этот тест использует большой блок памяти размером 1 MB и заполняет его
// повторяющимся набором символов от 0 до 255. Затем он ищет определенный символ
// (127) в этом блоке и сравнивает результаты
START_TEST(
    test_s21_memchr_matches_memchr_with_large_character_set_and_large_size) {
  char *str = malloc(1 << 20);  // 1 MB
  for (int i = 0; i < (1 << 20); i++) {
    str[i] = (char)(i % 256);
  }
  int character = 127;
  s21_size_t size = 1 << 20;  // 1 MB

  void *s21_result = s21_memchr(str, character, size);
  void *memchr_result = memchr(str, character, size);

  ck_assert_ptr_eq(s21_result, memchr_result);

  free(str);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *suite = suite_create("\033[32ms21_memchr\033[0m");

  TCase *test_case = tcase_create("memchr");

  tcase_add_test(test_case, test_s21_memchr_matches_memchr);
  tcase_add_test(test_case, test_s21_memchr_matches_memchr_with_zero_length);
  tcase_add_test(test_case,
                 test_s21_memchr_matches_memchr_with_null_terminator);
  tcase_add_test(test_case,
                 test_s21_memchr_matches_memchr_with_large_memory_blocks);
  tcase_add_test(test_case, test_s21_memchr_matches_memchr_with_unsigned_char);
  tcase_add_test(test_case, test_s21_memchr_matches_memchr_with_character_zero);
  tcase_add_test(test_case,
                 test_s21_memchr_matches_memchr_with_large_character_set);
  tcase_add_test(test_case,
                 test_s21_memchr_matches_memchr_with_special_characters);
  tcase_add_test(
      test_case,
      test_s21_memchr_matches_memchr_with_large_character_set_and_large_size);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = memchr_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}