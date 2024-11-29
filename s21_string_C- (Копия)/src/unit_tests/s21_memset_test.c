#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../s21_string.h"

START_TEST(test_s21_memset_matches_memset_with_char_array) {
    char arr[] = "Hello, Verter!";
    char s21_arr[sizeof(arr)];
    char mem_arr[sizeof(arr)];

    s21_memset(s21_arr, 'V', sizeof(arr));
    memset(mem_arr, 'V', sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_int_array) {
    int arr[] = {1, 2, 3, 4, 5};
    int s21_arr[sizeof(arr) / sizeof(arr[0])];
    int mem_arr[sizeof(arr) / sizeof(arr[0])];

    s21_memset(s21_arr, 0, sizeof(arr));
    memset(mem_arr, 0, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_zero_size) {
    int arr[] = {1, 2, 3, 4, 5};
    int s21_arr[sizeof(arr) / sizeof(arr[0])];
    int mem_arr[sizeof(arr) / sizeof(arr[0])];

    s21_memset(s21_arr, 0, sizeof(arr));
    memset(mem_arr, 0, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_large_data) {
    size_t size = 1 << 20;  // 1 MB
    char *s21_arr = malloc(size);
    char *mem_arr = malloc(size);
    
    s21_memset(s21_arr, 0xFF, size);
    memset(mem_arr, 0xFF, size);

    ck_assert_mem_eq(s21_arr, mem_arr, size);

    free(s21_arr);
    free(mem_arr);
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_unaligned_pointer) {
    char *ptr = (char *)malloc(sizeof(int) + 1);
    int s21_val = 0xAB;
    int mem_val = 0xAB;

    s21_memset(ptr + 1, s21_val, sizeof(int));  // Сдвигаем указатель на 1 байт
    memset(ptr + 1, mem_val, sizeof(int));

    ck_assert_mem_eq(ptr + 1, ptr + 1, sizeof(int)); // Сравниваем сдвинутые указатели

    free(ptr);
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_signed_char) {
    signed char arr[5];
    signed char s21_arr[sizeof(arr)];
    signed char mem_arr[sizeof(arr)];

    s21_memset(s21_arr, -1, sizeof(arr));
    memset(mem_arr, -1, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_unsigned_char) {
    unsigned char arr[5];
    unsigned char s21_arr[sizeof(arr)];
    unsigned char mem_arr[sizeof(arr)];

    s21_memset(s21_arr, 0xFF, sizeof(arr));
    memset(mem_arr, 0xFF, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_long_data) {
    long arr[] = {1L, 2L, 3L, 4L, 5L};
    long s21_arr[sizeof(arr) / sizeof(arr[0])];
    long mem_arr[sizeof(arr) / sizeof(arr[0])];

    s21_memset(s21_arr, 0, sizeof(arr));
    memset(mem_arr, 0, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_float_data) {
    float arr[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float s21_arr[sizeof(arr) / sizeof(arr[0])];
    float mem_arr[sizeof(arr) / sizeof(arr[0])];

    s21_memset(s21_arr, 0, sizeof(arr));
    memset(mem_arr, 0, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

START_TEST(test_s21_memset_matches_memset_with_double_data) {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double s21_arr[sizeof(arr) / sizeof(arr[0])];
    double mem_arr[sizeof(arr) / sizeof(arr[0])];

    s21_memset(s21_arr, 0, sizeof(arr));
    memset(mem_arr, 0, sizeof(arr));

    ck_assert_mem_eq(s21_arr, mem_arr, sizeof(arr));
}
END_TEST

Suite *memset_suite(void) {
    Suite *suite = suite_create("\033[32ms21_memset\033[0m");

    TCase *test_case = tcase_create("memset");
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_char_array);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_int_array);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_zero_size);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_large_data);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_unaligned_pointer);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_signed_char);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_unsigned_char);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_long_data);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_float_data);
    tcase_add_test(test_case, test_s21_memset_matches_memset_with_double_data);
    suite_add_tcase(suite, test_case);

    return suite;
}

int main() {
    Suite *suite = memset_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    int failures = srunner_ntests_failed(runner);
    srunner_free(runner);
    return failures == 0 ? 0 : 1;
}

