#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *arr_cpy = s21_NULL;
  if (str != s21_NULL) {
    arr_cpy = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    if (arr_cpy) {
      s21_strncpy(arr_cpy, str, s21_strlen(arr_cpy) + 1);
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        arr_cpy[i] =
            str[i] >= 'A' && str[i] <= 'Z' ? str[i] + ('a' - 'A') : str[i];
      }
    }
  }

  return (void *)arr_cpy;
}
