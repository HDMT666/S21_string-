#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL ;

  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    s21_size_t len_result = len_src + len_str + 1;

    if (start_index <= len_src) {
      result = malloc(len_result * sizeof(char));

      if (result) {
        // Копирование подстроки из строки src до start_index
        s21_memcpy(result, src, start_index);

        // Добавление строки str
        s21_memcpy(result + start_index, str, len_str);

        // Копирование оставшейся части строки src после start_index
        s21_memcpy(result + start_index + len_str, src + start_index,
                   len_src - start_index);

        // Завершение новой строки нулевым символом
        result[len_result - 1] = '\0';
      }
    }
  }

  return (void *)result;
}