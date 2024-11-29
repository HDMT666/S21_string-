#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  if (str1 != s21_NULL && str2 != s21_NULL) {
    s21_size_t len1 = s21_strlen(str1);
    s21_size_t len2 = s21_strlen(str2);
    /*Если дошли до конца или в result что то есть то выходим из цикла*/
    for (s21_size_t i = 0; i < len1 && !result; ++i) {
      for (s21_size_t j = 0; j < len2; ++j) {
        if (str1[i] == str2[j]) {  // Если найдено совпадение символов
          result = (char *)&str1[i];  // Устанавливаем указатель-результат на
                                      // текущий символ в str1
          break;  // Прерываем внутренний цикл, так как нашли совпадение
        }
      }
    }
  }

  return result;
}
