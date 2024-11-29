#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last;  // Статическая переменная для хранения состояния между
                      // вызовами функции
  char *token;  // Результат функции - указатель на найденный токен
  char *ref;  // Указатель на текущую позицию в строке str
  int is_initialized = 1;  // Флаг, указывающий, инициализирована ли функция

  // Проверяем, инициализирована ли функция и определяем начальное значение ref
  if ((ref = str) == s21_NULL && (ref = last) == s21_NULL) {
    is_initialized = 0;
  }

  // Пропускаем начальные символы, совпадающие с символами из delim
  for (int i = 0; is_initialized && *ref && delim[i]; i++) {
    if (*ref == delim[i]) {
      ref++;
      i = -1;  // Сбрасываем i до -1, чтобы в следующей итерации было i=0
    }
  }

  // Проверяем, инициализирована ли функция и достигнут конец строки
  if (is_initialized && *ref == '\0') {
    ref = s21_NULL;
    last = s21_NULL;
    is_initialized = 0;
  }
  token = ref;  // Запоминаем найденный токен

  // Ищем символы из delim, чтобы разделить токены
  while (is_initialized && *ref) {
    for (size_t i = 0; delim[i]; i++) {
      if (*ref == delim[i]) {
        is_initialized = 0;
        *ref = '\0';  // Заменяем разделительный символ нулевым символом
        ref++;
        if (*ref == '\0') {
          ref = s21_NULL;
        }
        last = ref;  // Запоминаем позицию начала следующего токена
        break;
      }
    }

    if (is_initialized) {
      ref++;

      if (*ref == '\0') {
        last = s21_NULL;
      }
    }
  }

  return token;  // Возвращаем найденный токен
}
