#include <check.h>
#include <string.h>
#include <stdio.h>
#include "../s21_string.h"

void check_result(int s21_result, int strncmp_result) {
    if (s21_result == strncmp_result) {
        printf("0 "); // Тест пройден
    } else if (s21_result < strncmp_result) {
        printf("-1 "); // s21_strncmp меньше
    } else {
        printf("1 "); // s21_strncmp больше
    }
}

START_TEST(test_s21_strncmp_matches_strncmp_with_equal_strings) {
    const char *str1 = "SALAM";
    const char *str2 = "SALAM";
    s21_size_t n = 5;

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_different_strings) {
    const char *str1 = "SALAM";
    const char *str2 = "Verte";
    s21_size_t n = 5;

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_prefix_match) {
    const char *str1 = "SALAM";
    const char *str2 = "SALAM, Verte";
    s21_size_t n = 5;

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_matches_strncmp_with_empty_strings) {
    const char *str1 = "";
    const char *str2 = "";
    s21_size_t n = 1;

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_first_string_shorter) {
    const char *str1 = "SAL";
    const char *str2 = "SALAM";
    s21_size_t n = 4;  // Сравниваем 4 символа

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_second_string_shorter) {
    const char *str1 = "SALAM";
    const char *str2 = "SAL";
    s21_size_t n = 4;  // Сравниваем 4 символа

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

START_TEST(test_s21_strncmp_with_zero_length) {
    const char *str1 = "SALAM";
    const char *str2 = "XYZ";
    s21_size_t n = 0;  // Ничего не сравниваем

    int s21_result = s21_strncmp(str1, str2, n);
    int strncmp_result = strncmp(str1, str2, n);

    check_result(s21_result, strncmp_result);
}
END_TEST

Suite *s21_strncmp_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_strncmp");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_s21_strncmp_matches_strncmp_with_equal_strings);
    tcase_add_test(tc_core, test_s21_strncmp_matches_strncmp_with_different_strings);
    tcase_add_test(tc_core, test_s21_strncmp_matches_strncmp_with_prefix_match);
    tcase_add_test(tc_core, test_s21_strncmp_matches_strncmp_with_empty_strings);
    tcase_add_test(tc_core, test_s21_strncmp_first_string_shorter);
    tcase_add_test(tc_core, test_s21_strncmp_second_string_shorter);
    tcase_add_test(tc_core, test_s21_strncmp_with_zero_length);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = s21_strncmp_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
