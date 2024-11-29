#include "s21_string.h"

// helper functions
static int s21_isdigit(char c);
static int s21_atoi(const char *str);

static void convert_whole_num_to_string(int64_t value, char *ret, int base);
static void convert_unsigned_num_to_string(uint64_t value, char *ret, int base);
static bool is_integer_specifier(char c);
static bool is_all_zeroes(char *buff);
static void prepend_ox(char *buff, flags f);
static void convert_double_to_string(long double value, char *ret, flags f);
static void prepend_mantiss(char *str, int pow, char sign);
static void remove_trailing_zeroes(char *buff);

// parse format
static const char *parse_flags(const char *format, flags *f);
static const char *parse_width(const char *format, flags *f, va_list va);
static const char *parse_precision(const char *format, flags *f, va_list va);
static const char *parse_length(const char *format, flags *f);

// parse valueues
static void handle_valueue(flags f, char *buff, va_list va);
static void parse_integer(flags, char *buff, va_list va);
static void parse_unsigned(flags f, char *buff, va_list va);
static void parse_octal(flags f, char *buff, va_list va);
static void parse_hexadecimal(flags f, char *buff, va_list va);
static void parse_character(flags f, char *buff, va_list va);
static void parse_string(flags f, char *buff, va_list va);
static void parse_pointer(flags f, char *buff, va_list va);
static void parse_float(flags f, char *buff, va_list va);
static void parse_mantissa(flags f, char *buff, va_list va);
static void parse_float_g_G(flags f, char *buff, va_list va);

// format valueues
static void format_precision(char *buff, flags f);
static void format_flags(char *buff, flags f);
static void format_gG_precision(char *buff, int precision);
static void format_wchar(flags f, char *buff, wchar_t w_c);
static void format_char(flags f, char *buff, char c);
static void format_string(flags f, char *buff, char *str);
static void format_wide_string(flags f, char *buff, wchar_t *wstr);

// string functions
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);
void *s21_memmove(void *dst, const void *src, s21_size_t len);
void to_upper(char *str);

int s21_sprintf(char *str, const char *format, ...) {
  flags flag = {0};
  va_list va;
  va_start(va, format);
  char *str_beginning = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flag, 0, sizeof(flags));
    }

    format = parse_flags(format, &flag);
    format = parse_width(format, &flag, va);
    format = parse_precision(format, &flag, va);
    format = parse_length(format, &flag);

    flag.specifier = *format;
    format++;

    char buff[BUFF_SIZE] = {'\0'};
    handle_valueue(flag, buff, va);
    for (int i = 0; buff[i]; i++, str++) *str = buff[i];

    if (flag.specifier == 'n'){
      int *ret = va_arg(va, int *);
      *ret = str - str_beginning;
    }
  }

  *str = '\0';
  va_end(va);
  return str - str_beginning;
}

const char *parse_flags(const char *format, flags *flag) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '0':
        flag->zero = true;
        break;
      case '-':
        flag->minus = true;
        break;
      case '+':
        flag->plus = true;
        break;
      case ' ':
        flag->space = true;
        break;
      case '#':
        flag->hash = true;
        break;
    }
    format++;
  }
  return format;
}

const char *parse_width(const char *format, flags *flag, va_list va) {
  if (*format == '*') {
    format++;
    flag->width = va_arg(va, int);
  } else if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    flag->width = s21_atoi(tmp);
  }
  return format;
}

const char *parse_precision(const char *format, flags *flag, va_list va) {
  if (*format == '.') {
    flag->is_precision_set = true;
    format++;
  }

  if (*format == '*') {
    format++;
    flag->precision = va_arg(va, int);
  }
  if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++)
      tmp[i] = *format;               // push digits in tmp
    flag->precision = s21_atoi(tmp);  // reverse and num to
  }
  return format;
}

const char *parse_length(const char *format, flags *flag) {
  switch (*format) {
    case 'h':
      flag->length = 'h';
      format++;
      break;
    case 'l':
      flag->length = 'l';
      format++;
      break;
    case 'L':
      flag->length = 'L';
      format++;
  }
  return format;
}

void handle_valueue(flags flag, char *buff, va_list va) {
  if (flag.specifier == 'd' || flag.specifier == 'i')
    parse_integer(flag, buff, va);
  else if (flag.specifier == 'u')
    parse_unsigned(flag, buff, va);
  else if (flag.specifier == 'o')
    parse_octal(flag, buff, va);
  else if (flag.specifier == 'x' || flag.specifier == 'X')
    parse_hexadecimal(flag, buff, va);
  else if (flag.specifier == '%')
    buff[0] = '%';
  else if (flag.specifier == 'c')
    parse_character(flag, buff, va);
  else if (flag.specifier == 's')
    parse_string(flag, buff, va);
  else if (flag.specifier == 'p')
    parse_pointer(flag, buff, va);
  else if (flag.specifier == 'f')
    parse_float(flag, buff, va);
  else if (flag.specifier == 'e' || flag.specifier == 'E')
    parse_mantissa(flag, buff, va);
  else if (flag.specifier == 'g' || flag.specifier == 'G')
    parse_float_g_G(flag, buff, va);
  if (flag.specifier == 'G' || flag.specifier == 'E' || flag.specifier == 'X')
    to_upper(buff);
}

void parse_integer(flags flag, char *buff, va_list va) {
  int64_t value = va_arg(va, int64_t);

  switch (flag.length) {
    case 0:
      value = (int32_t)value;
      break;
    case 'h':
      value = (int16_t)value;
  }
  convert_whole_num_to_string(value, buff, 10);
  format_precision(buff, flag);
  format_flags(buff, flag);
}

void convert_whole_num_to_string(int64_t value, char *ret, int base) {
  char tmp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;

  bool negative = value < 0 ? 1 : 0;
  value = negative ? -value : value;

  if (value == 0) tmp[index] = '0';

  while (value > 0) {
    index--;
    tmp[index] = "0123456789abcdef"[value % base];
    value /= base;
  }
  for (int j = 0; tmp[index]; index++, j++) {
    if (negative && j == 0) {
      ret[j++] = '-';
    }

    ret[j] = tmp[index];
  }
}

void format_precision(char *buff, flags flag) {
  char tmp[BUFF_SIZE] = {'\0'};

  int sign = 0;
  int len = s21_strlen(buff);

  if (buff[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }

  if (flag.precision > len) {
    int index;
    for (index = sign; index < flag.precision - len + sign; index++)
      tmp[index] = '0';

    for (int i = sign; buff[i]; i++, index++) tmp[index] = buff[i];

    s21_strcpy(buff, tmp);
  }

  if (flag.is_precision_set && flag.precision == 0 &&
      is_integer_specifier(flag.specifier) && buff[0] == '0')
    buff[0] = '\0';
}

bool is_integer_specifier(char c) {
  char specs[] = {'d', 'i', 'o', 'u', 'x', 'X'};
  bool res = false;
  for (s21_size_t i = 0; i < sizeof(specs); i++) {
    if (specs[i] == c) {
      res = true;
      break;
    }
  }
  return res;
}

void format_flags(char *buff, flags flag) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (flag.plus && flag.specifier != 'u') {
    tmp[0] = buff[0] == '-' ? buff[0] : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (flag.space && buff[0] != '-' && flag.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (flag.width > (int)s21_strlen(buff)) {
    int index = flag.width - s21_strlen(buff);
    if (!flag.minus) {
      s21_memset(tmp, flag.zero ? '0' : ' ', index);
      s21_strcpy(tmp + index, buff);
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', index);
    }
    s21_strcpy(buff, tmp);
  }
}

void convert_unsigned_num_to_string(uint64_t value, char *ret, int base) {
  char buf[BUFF_SIZE + 1] = {'\0'};
  int index = BUFF_SIZE - 1;
  if (value == 0) {
    buf[index] = '0';
    index--;
  }

  for (; value && index; --index, value /= base)
    buf[index] = "0123456789abcdef"[value % base];
  for (int j = 0; buf[index + 1]; index++, j++) ret[j] = buf[index + 1];
}

void parse_unsigned(flags flag, char *buff, va_list va) {
  uint64_t value = va_arg(va, uint64_t);
  switch (flag.length) {
    case 'h':
      value = (uint16_t)value;
      break;
    case 'l':
      value = (uint64_t)value;
      break;
    case 0:
      value = (uint32_t)value;
  }
  convert_unsigned_num_to_string(value, buff, 10);
  format_precision(buff, flag);
  format_flags(buff, flag);
}

void parse_octal(flags flag, char *buff, va_list va) {
  buff[0] = '0';
  convert_whole_num_to_string(va_arg(va, int64_t), buff + flag.hash, 8);
  format_precision(buff, flag);
  format_flags(buff, flag);
}

bool is_all_zeroes(char *buff) {
  for (int i = 0; buff[i]; i++)
    if (buff[i] != '0') return false;
  return true;
}

void parse_hexadecimal(flags flag, char *buff, va_list va) {
  uint64_t value = va_arg(va, uint64_t);
  switch (flag.length) {
    case 0:
      value = (uint32_t)value;
      break;
    case 'h':
      value = (uint16_t)value;
      break;
    case 'l':
      value = (uint64_t)value;
      break;
  }
  convert_unsigned_num_to_string(value, buff, 16);
  format_precision(buff, flag);
  if (flag.hash) {
    prepend_ox(buff, flag);
  }
  format_flags(buff, flag);
}

void prepend_ox(char *buff, flags flag) {
  if (!is_all_zeroes(buff) || flag.specifier == 'p') {
    s21_memmove(buff + 2, buff, s21_strlen(buff));
    buff[0] = '0';
    buff[1] = 'x';
  }
}

void parse_character(flags flag, char *buff, va_list va) {
  if (flag.length == 'l') {
    wchar_t w_c;
    w_c = va_arg(va, wchar_t);
    format_wchar(flag, buff, w_c);
  } else {
    char ch;
    ch = va_arg(va, int);
    format_char(flag, buff, ch);
  }
}

void format_wchar(flags flag, char *buff, wchar_t w_c) {
  if (!flag.minus && flag.width) {
    char tmp[BUFF_SIZE] = {'\0'};
    wcstombs(tmp, &w_c, BUFF_SIZE);
    for (s21_size_t i = 0; i < flag.width - s21_strlen(tmp); i++) buff[i] = ' ';
    s21_strcat(buff, tmp);
  } else if (flag.width) {
    wcstombs(buff, &w_c, BUFF_SIZE);
    for (int i = s21_strlen(buff); i < flag.width; i++) buff[i] = ' ';
  } else {
    wcstombs(buff, &w_c, BUFF_SIZE);
  }
}
void format_char(flags flag, char *buff, char ch) {
  if (!flag.minus && flag.width) {
    for (int i = 0; i < flag.width; i++) {
      buff[i] = ' ';
      if (i == flag.width - 1) buff[i] = ch;
    }
  } else if (flag.width) {
    buff[0] = ch;
    for (int i = 1; i < flag.width; i++) buff[i] = ' ';
  } else {
    buff[0] = ch;
  }
}

void parse_string(flags flag, char *buff, va_list va) {
  if (flag.length == 'l') {
    wchar_t *wstr = va_arg(va, wchar_t *);
    format_wide_string(flag, buff, wstr);
  } else {
    char *str = va_arg(va, char *);
    format_string(flag, buff, str);
  }
}
void format_string(flags flag, char *buff, char *str) {
  char tmp[BUFF_SIZE] = {'\0'};
  s21_strcpy(tmp, str);
  if (flag.is_precision_set) tmp[flag.precision] = '\0';

  int shift = flag.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (flag.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}
void format_wide_string(flags flag, char *buff, wchar_t *wstr) {
  char tmp[BUFF_SIZE] = {'\0'};
  char str[BUFF_SIZE] = {'\0'};

  wcstombs(str, wstr, BUFF_SIZE);
  s21_strcpy(tmp, str);
  if (flag.is_precision_set) tmp[flag.precision] = '\0';

  int shift = flag.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (flag.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

void parse_pointer(flags flag, char *buff, va_list va) {
  convert_unsigned_num_to_string(va_arg(va, uint64_t), buff, 16);
  format_precision(buff, flag);
  prepend_ox(buff, flag);
  format_flags(buff, flag);
}

void parse_float(flags flag, char *buff, va_list va) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(va, long double);
  } else {
    value = va_arg(va, double);
  }

  if (!flag.is_precision_set) {
    flag.precision = 6;
  }

  convert_double_to_string(value, buff, flag);
  format_flags(buff, flag);
}
void convert_double_to_string(long double value, char *ret, flags flag) {
  char buff[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  bool negative = value < 0 ? 1 : 0;
  value = negative ? value * -1 : value;
  long double l = 0, r = modfl(value, &l);
  if (flag.precision == 0) {
    l = roundl(value);
    r = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < flag.precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < flag.precision; index--, i++) buff[index] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0;
         right /= 10, index--, i--)
      buff[index] = (int)(right % 10 + 0.05) + '0';
  }
  if ((flag.is_precision_set && flag.precision != 0) || (int)r ||
      (!flag.is_precision_set && value == 0) || s21_strlen(fractions))
    buff[index--] = '.';
  if (!left) {
    buff[index] = '0';
    index--;
  } else {
    for (; left; left /= 10, index--) buff[index] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[index + 1]; index++, i++) {
    if (negative && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[index + 1];
  }
}

void parse_mantissa(flags flag, char *buff, va_list va) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(va, long double);
  } else {
    value = va_arg(va, double);
  }
  int pow = 0;
  char sign = (int)value == 0 ? '-' : '+';

  if ((int)value - value) {
    while ((int)value == 0) {
      pow++;
      value *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)value / 10 != 0) {
    pow++;
    value /= 10;
  }

  if (!flag.is_precision_set) flag.precision = 6;
  convert_double_to_string(value, buff, flag);
  prepend_mantiss(buff, pow, sign);
  format_flags(buff, flag);
}

void prepend_mantiss(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = pow % 10 + '0';
  pow /= 10;
  str[len + 2] = pow % 10 + '0';
  str[len + 4] = '\0';
}

void parse_float_g_G(flags flag, char *buff, va_list va) {
  long double value = 0;
  if (flag.length == 'L') {
    value = va_arg(va, long double);
  } else {
    value = va_arg(va, double);
  }

  if (!flag.is_precision_set) {
    flag.precision = 6;
  }
  if (flag.precision == 0) flag.precision = 1;
  int precision = flag.precision;
  long double m_value = value;
  int pow = 0;
  if ((int)value - value) {
    while ((int)m_value == 0) {
      pow++;
      m_value *= 10;
    }
  }
  if (pow > 4) {
    flag.precision = 0;
    convert_double_to_string(m_value, buff, flag);
  } else {
    flag.precision = 10;
    convert_double_to_string(value, buff, flag);
  }
  format_gG_precision(buff, precision);
  if (pow > 4) prepend_mantiss(buff, pow, '-');
  remove_trailing_zeroes(buff);
  format_flags(buff, flag);
}

void remove_trailing_zeroes(char *buff) {
  int len = s21_strlen(buff);
  char *dot = s21_strchr(buff, '.');
  if (dot) {
    for (int i = len - 1; buff[i] != '.'; i--) {
      if (buff[i] == '0')
        buff[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0') dot[0] = '\0';
  }
}

void format_gG_precision(char *buff, int precision) {
  int sig_digs = 0;
  s21_size_t len = s21_strlen(buff);
  int not_zero_found = 0;
  for (s21_size_t i = 0; i < s21_strlen(buff); i++) {
    if ((buff[i] == '0' && !not_zero_found) || buff[i] == '.')
      continue;
    else
      not_zero_found = 1;

    if (s21_isdigit(buff[i]) && not_zero_found) {
      sig_digs++;
    }
    if (sig_digs == precision && i + 1 < len) {
      int next = buff[i + 1] == '.' ? 2 : 1;
      buff[i] = buff[i + next] - '0' > 5 ? (char)(buff[i] + 1) : buff[i];
      buff[i + 1] = '\0';
      break;
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

int s21_atoi(const char *str) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = 1;
      break;
    }
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i, j;

  for (i = 0; dest[i] != '\0'; i++)
    ;

  for (j = 0; src[j] != '\0'; j++) dest[i + j] = src[j];

  dest[i + j] = '\0';

  return dest;
}

char *s21_strcpy(char *dest, const char *src) {
  char *flag;
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  flag = dest;
  return flag;
}

void *s21_memmove(void *dst, const void *src, s21_size_t n) {
  unsigned char buffer[n];
  for (s21_size_t i = 0; i < n; i++) {
    buffer[i] = *((unsigned char *)(src) + i);
  }

  for (s21_size_t i = 0; i < n; i++) {
    *((unsigned char *)(dst) + i) = buffer[i];
  }
  return dst;
}

void to_upper(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = *str - 'a' + 'A';
    str++;
  }
}