#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t i = 0;

    // Если n равно 0, строки считаются равными
    if (n == 0) return 0;

    while (i < n) {
        // Проверяем, достигли конца одной из строк
        if (str1[i] == '\0' || str2[i] == '\0') {
            return (unsigned char)str1[i] - (unsigned char)str2[i]; // возвращаем разность символов
        }

        // Сравниваем символы
        if (str1[i] != str2[i]) {
            return (unsigned char)str1[i] - (unsigned char)str2[i]; // возвращаем разность символов
        }

        i++;
    }

    return 0; // Если все n символов равны
}
