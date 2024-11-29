#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ch_dest = (unsigned char *)dest;
  const unsigned char *ch_src = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; ++i) {
    ch_dest[i] = ch_src[i];
  }

  return dest;
}
