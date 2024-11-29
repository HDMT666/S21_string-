#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < len1; ++i) {
    int detected = 1;  // Флаг для отслеживания наличия совпадений символов
    for (s21_size_t j = 0; j < len2; ++j) {
      if (str1[i] == str2[j])
        detected = 0;  // Выключаем если нашлось совпадение
    }
    if (detected) len++;  // Увеличиваем счетчик, если символ не найден в str2
  }
  return len;
}