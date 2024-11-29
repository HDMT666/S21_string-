#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ch = (unsigned char *)
      str;  // Преобразуем указатель void *str в unsigned char *
  unsigned char value =
      (unsigned char)c;  // Преобразуем символ int (c) в unsigned char

  /* Если указатель (ch) на (str) не равен NULL И (c)
   * больше или равно нулю И (c) меньше или равен s21_UCHAR_MAX тогда мы
   * меняем ch[i] на символ переданный в качетве аргумента */
  for (s21_size_t i = 0; i < n; ++i) {
    *(ch + i) = value;
  }

  return ch;
}
