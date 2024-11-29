#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src) {
    if (trim_chars == s21_NULL) trim_chars = " \n\t";

    long unsigned int length = s21_strlen(src);
    result = calloc(length + 1, sizeof(char));
    if (result) {
      s21_size_t res_idx = 0;
      s21_size_t src_idx = 0;

      // Удаление слева
      while (src_idx < length && s21_strchr(trim_chars, (int)src[src_idx])) {
        src_idx++;
      }

      while (src_idx < length) {
        result[res_idx++] = src[src_idx++];
      }

      // Удаление справа
      while (res_idx > 0 && s21_strchr(trim_chars, (int)result[res_idx])) {
        res_idx--;
      }

      result[res_idx + 1] = '\0';
    }
  }

  return result;
}