#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  s21_size_t len1 = s21_strlen(haystack);
  s21_size_t len2 = s21_strlen(needle);
  /* (i <= len1 - len2) например, предположим, что у нас есть строка haystack
   * длиной 10 символов, а подстрока needle имеет длину 5 символов. Если мы
   * дойдем до индекса 6 в строке haystack, то оставшиеся символы не могут
   * совпадать с подстрокой needle, так как длина оставшейся части меньше длины
   * needle. В этом случае можно прекратить дальнейшую проверку, так как полное
   * совпадение невозможно.*/
  for (s21_size_t i = 0; i <= len1 - len2; ++i) {
    // Проверяем, соответствует ли текущая позиция в haystack началу needle
    if (s21_strncmp(&haystack[i], needle, len2) == 0) {
      result = (char *)&haystack[i];
      break;  // Найдено соответствие, выходим из цикла
    }
  }
  return result;
}