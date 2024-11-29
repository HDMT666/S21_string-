#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *ch = (unsigned char *)
      str;  // Преобразуем указатель void *str в unsigned char *
  unsigned char value =
      (unsigned char)c;  // Преобразуем символ int (c) в unsigned char
  void *result =
      s21_NULL;  // Инициализируем указатель result значением s21_NULL

  for (s21_size_t i = 0; i < n; ++i) {
    if (ch[i] == value) {
      result = (void *)&ch[i];
      break;  // Если нашли первое вхождение то выходим из цикла
    }
  }

  return result;
}