#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_s21_memcpy_matches_memcpy) {
  char src[] = "SALAM";
  char dest[sizeof(src)];

  void *s21_result = s21_memcpy(dest, src, sizeof(src));
  void *memcpy_result = memcpy(dest, src, sizeof(src));

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_zero_length) {
  char src[] = "Verter";
  char dest[sizeof(src)];

  void *s21_result = s21_memcpy(dest, src, 0);
  void *memcpy_result = memcpy(dest, src, 0);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_overlapping_memory) {
  char src[] = "KEFTEME";
  char dest[sizeof(src)];

  // Заполняем dest перед копированием для воспроизведения перекрытия памяти
  memset(dest, 'X', sizeof(src));

  void *s21_result = s21_memcpy(dest + 1, src, sizeof(src) - 1);
  void *memcpy_result = memcpy(dest + 1, src, sizeof(src) - 1);

  ck_assert_ptr_eq(s21_result, dest + 1);
  ck_assert_mem_eq(dest + 1, memcpy_result, sizeof(src) - 1);
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_large_memory_blocks) {
  s21_size_t size = 1 << 20;  // 1 MB
  char *src = malloc(size);
  char *dest = malloc(size);

  memset(src, 'A', size);

  void *s21_result = s21_memcpy(dest, src, size);
  void *memcpy_result = memcpy(dest, src, size);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, size);

  free(src);
  free(dest);
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_different_data_types) {
  int src[] = {1, 2, 3, 4, 5};
  int dest[sizeof(src) / sizeof(int)];

  void *s21_result = s21_memcpy(dest, src, sizeof(src));
  void *memcpy_result = memcpy(dest, src, sizeof(src));

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_char_pointers) {
  const char *src = "Hello, Zaibal!";
  char dest[strlen(src) + 1];

  void *s21_result = s21_memcpy(dest, src, strlen(src) + 1);
  void *memcpy_result = memcpy(dest, src, strlen(src) + 1);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, strlen(src) + 1);
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_large_data) {
  s21_size_t size = 1 << 20;  // 1 MB
  char *src = malloc(size);
  char *dest = malloc(size);

  memset(src, 'A', size);

  void *s21_result = s21_memcpy(dest, src, size);
  void *memcpy_result = memcpy(dest, src, size);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, size);

  free(src);
  free(dest);
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_aligned_pointers) {
  int src[] = {1, 2, 3, 4, 5};
  int dest[sizeof(src) / sizeof(int)];

  void *s21_result = s21_memcpy(dest, src, sizeof(src));
  void *memcpy_result = memcpy(dest, src, sizeof(src));

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_unaligned_pointers) {
  int src[] = {1, 2, 3, 4, 5};
  int *dest = (int *)((char *)malloc(sizeof(src) + sizeof(int)) + 1);

  void *s21_result = s21_memcpy(dest, src, sizeof(src));
  void *memcpy_result = memcpy(dest, src, sizeof(src));

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));

  free((char *)dest - 1);
}
END_TEST

START_TEST(test_s21_memcpy_matches_memcpy_with_zero_size) {
  char src[] = "Kefteme";
  char dest[sizeof(src)];

  void *s21_result = s21_memcpy(dest, src, 0);
  void *memcpy_result = memcpy(dest, src, 0);

  ck_assert_ptr_eq(s21_result, dest);
  ck_assert_mem_eq(dest, memcpy_result, sizeof(src));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *suite = suite_create("\033[32ms21_memcpy\033[0m");

  TCase *test_case = tcase_create("memcpy");
  tcase_add_test(test_case, test_s21_memcpy_matches_memcpy);
  tcase_add_test(test_case, test_s21_memcpy_matches_memcpy_with_zero_length);
  tcase_add_test(test_case,
                 test_s21_memcpy_matches_memcpy_with_overlapping_memory);
  tcase_add_test(test_case,
                 test_s21_memcpy_matches_memcpy_with_large_memory_blocks);
  tcase_add_test(test_case,
                 test_s21_memcpy_matches_memcpy_with_different_data_types);
  tcase_add_test(test_case, test_s21_memcpy_matches_memcpy_with_char_pointers);
  tcase_add_test(test_case, test_s21_memcpy_matches_memcpy_with_large_data);
  tcase_add_test(test_case,
                 test_s21_memcpy_matches_memcpy_with_aligned_pointers);
  tcase_add_test(test_case,
                 test_s21_memcpy_matches_memcpy_with_unaligned_pointers);
  tcase_add_test(test_case, test_s21_memcpy_matches_memcpy_with_zero_size);
  suite_add_tcase(suite, test_case);

  return suite;
}

int main() {
  Suite *suite = memcpy_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}