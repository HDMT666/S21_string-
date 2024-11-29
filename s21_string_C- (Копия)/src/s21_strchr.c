#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  unsigned char value = (unsigned char)c;  // приведение int к беззнаковому типу
  /*Переменная size в данном контексте используется для определения размера
   * строки str, включая завершающий нулевой символ ('\0').*/
  s21_size_t size = s21_strlen(str) + 1;
  /*Сразу ставим NULL т.к Возвращаемое значение:
  Указатель на искомый символ, если он найден в строке str, иначе NULL.*/
  char *result = s21_NULL;
  for (s21_size_t i = 0; i < size; ++i) {
    if (str[i] == value) {
      result = (char *)&str[i];  // Записываем позицию в result приведенный в
                                 // тип char*
      break;
    }
  }
  return result;
}
