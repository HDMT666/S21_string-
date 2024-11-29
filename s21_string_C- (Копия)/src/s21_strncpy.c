#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  // Копирование символов из src в dest до достижения n символов или символа
  // конца строки в src
  for (; i < n && src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }
  // Если достигнут конец строки в src, но еще не скопировано n символов,
  // добавляем нулевой символ в dest
  if (src[i] == '\0' && n > 0 && n > s21_strlen(src)) dest[i] = '\0';
  return dest;
}