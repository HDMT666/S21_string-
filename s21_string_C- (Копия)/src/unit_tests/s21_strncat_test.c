#include <check.h>
#include <string.h>
#include <stdlib.h>

#include "../s21_string.h" // Убедитесь, что путь к вашей реализации s21_strncat правильный

// Тест: s21_strncat с пустым dest
START_TEST(test_s21_strncat_with_empty_dest) {
    char dest[10] = "";
    const char *src = "Salam";

    char *s21_result = s21_strncat(dest, src, 5);
    char expected_result[10] = "Salam"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с пустым src
START_TEST(test_s21_strncat_with_empty_src) {
    char dest[10] = "Pidor";
    const char *src = "";

    char *s21_result = s21_strncat(dest, src, 5);
    char expected_result[10] = "Pidor"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с полным объединением
START_TEST(test_s21_strncat_full_concatenation) {
    char dest[15] = "Hello";
    const char *src = "Kefte";

    char *s21_result = s21_strncat(dest, src, 5);
    char expected_result[15] = "HelloKefte"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с частичным объединением
START_TEST(test_s21_strncat_partial_concatenation) {
    char dest[15] = "Kefte";
    const char *src = "World";

    char *s21_result = s21_strncat(dest, src, 3);
    char expected_result[15] = "KefteWor"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с нулевым n
START_TEST(test_s21_strncat_zero_n) {
    char dest[15] = "Hello";
    const char *src = "Kefte";

    char *s21_result = s21_strncat(dest, src, 0);
    char expected_result[15] = "Hello"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с dest, не завершающимся нулем
START_TEST(test_s21_strncat_dest_not_null_terminated) {
    char dest[15] = {'H', 'e', 'l', 'l', 'o', '\0'};
    const char *src = "World";

    char *s21_result = s21_strncat(dest, src, 5);
    char expected_result[15] = "HelloWorld"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Тест: s21_strncat с dest и src, указывающими на один и тот же адрес
START_TEST(test_s21_strncat_same_pointer) {
    char str[15] = "Salam";
    char *dest = str;
    const char *src = str;

    char *s21_result = s21_strncat(dest, src, 5);
    char expected_result[15] = "SalamSalam"; // Ожидаемый результат

    ck_assert_ptr_eq(s21_result, dest);
    ck_assert_str_eq(dest, expected_result);
}
END_TEST

// Основная функция для создания набора тестов
Suite *strncat_suite(void) {
    Suite *suite = suite_create("s21_strncat");

    TCase *test_case = tcase_create("strncat");
    tcase_add_test(test_case, test_s21_strncat_with_empty_dest);
    tcase_add_test(test_case, test_s21_strncat_with_empty_src);
    tcase_add_test(test_case, test_s21_strncat_full_concatenation);
    tcase_add_test(test_case, test_s21_strncat_partial_concatenation);
    tcase_add_test(test_case, test_s21_strncat_zero_n);
    tcase_add_test(test_case, test_s21_strncat_dest_not_null_terminated);
    tcase_add_test(test_case, test_s21_strncat_same_pointer);
    suite_add_tcase(suite, test_case);

    return suite;
}

// Основная функция для запуска тестов
int main() {
    Suite *suite = strncat_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    int failures = srunner_ntests_failed(runner);
    srunner_free(runner);
    return failures == 0 ? 0 : 1;
}

