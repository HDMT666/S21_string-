#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest == NULL || src == NULL) return NULL;  // Проверка на NULL

  s21_size_t max_dest_len = s21_strlen(dest);  // Находим длину dest
  s21_size_t i = 0;

  // Пока не встретится символ конца строки и пока не будет добавлено n символов.
  while (*src != '\0' && i < n) {
    dest[max_dest_len + i] = src[i];  // Добавляем символы из src в конец dest
    ++i;
  }
  
  dest[max_dest_len + i] = '\0';  // Добавляем завершающий символ конца строки

  return dest;
}

