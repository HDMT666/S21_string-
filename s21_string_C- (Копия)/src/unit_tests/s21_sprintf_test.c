#include <check.h>
#include <stdio.h>

#include "../s21_string.h"

// START_TEST(test_no_args) {
//   char result[20];
//   char assert[20];
//   s21_sprintf(result, "Zdarova Zaibal!");
//   sprintf(assert, "Zdarova Zaibal!");
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

// START_TEST(sprintf_D_0) {
//   char our[20];
//   char original[20];
//   s21_sprintf(our, " %d%d%d%d", -4, 8, 15, 16);
//   sprintf(original, " %d%d%d%d", -4, 8, 15, 16);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_1) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%d|", 555);
//   sprintf(original, "|%d|", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(D_11) {
//   char our[50];
//   char original[50];
//   int d = 2147483;
//   s21_sprintf(our, "Count: % d", d);
//   sprintf(original, "Count: % d", d);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(D_minus) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-d", 0);
//   sprintf(original, "%-d", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(LD_1) {
//   char our[200];
//   char original[200];
//   s21_sprintf(our, "%ld", 100000000000000000);
//   sprintf(original, "%ld", 100000000000000000);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(d_plus) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%+d", 0);
//   sprintf(original, "%+d", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(HD_1) {
//   char our[100];
//   char original[100];
//   short int x = 400;
//   s21_sprintf(our, "%hd", x);
//   sprintf(original, "%hd", x);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_2) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%d|", -555);
//   sprintf(original, "|%d|", -555);
//   ck_assert_str_eq(our, original);
// }

// START_TEST(sprintf_D_3) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%-20.18d|\n", -555);
//   sprintf(original, "|%-20.18d|\n", -555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_4) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%20.2d|\n", -555);
//   sprintf(original, "|%20.2d|\n", -555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_6) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%.10d|\n", 555);
//   sprintf(original, "|%.10d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_7) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%.010d|\n", 555);
//   sprintf(original, "|%.010d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_D_12) {
//   char result[20];
//   char assert[20];
//   s21_sprintf(result, "Count: %1.1d", 69);
//   sprintf(assert, "Count: %1.1d", 69);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

// START_TEST(sprintf_D_8) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%10d|\n", 555);
//   sprintf(original, "|%10d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_9) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%-10d|\n", 555);
//   sprintf(original, "|%-10d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_10) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%-10d|\n", -555);
//   sprintf(original, "|%-10d|\n", -555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_D_11) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%-+10d|\n", -555);
//   sprintf(original, "|%-+10d|\n", -555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST
// START_TEST(sprintf_D_12) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%-+10d|\n", 555);
//   sprintf(original, "|%-+10d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST
// START_TEST(sprintf_D_13) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "|%- 10d|\n", 555);
//   sprintf(original, "|%- 10d|\n", 555);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_S_1) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%10s|", "gdb");
//   sprintf(original, "|%10s|", "gdb");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(minus_S_1) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%-10s|", "gdb");
//   sprintf(original, "|%-10s|", "gdb");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(sprintf_S_2) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%10s|", "gdb gdb");
//   sprintf(original, "|%10s|", "gdb gdb");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(minus_S_2) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%-10s|", "abc abc");
//   sprintf(original, "|%-10s|", "abc abc");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(accuracy_S_1) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%.3s|", "gdb");
//   sprintf(original, "|%.3s|", "gdb");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(accuracy_S_2) {
//   char our[1024] = "\0";
//   char original[1024] = "\0";
//   s21_sprintf(our, "|%.05s|", "gdb");
//   sprintf(original, "|%.05s|", "gdb");
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(accuracy_S_3) {
//   char data[1024] = "\0";
//   char data1[1024] = "\0";
//   int our = s21_sprintf(data, "|%.010s|\n", "salam");
//   int original = sprintf(data1, "|%.010s|\n", "salam");
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(accuracy_S_4) {
//   char data[1024] = "\0";
//   char data1[1024] = "\0";
//   int our = s21_sprintf(data, "|%.10s|\n", "salam");
//   int original = sprintf(data1, "|%.10s|\n", "salam");
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(accuracy_S_5) {
//   char data[1024] = "\0";
//   char data1[1024] = "\0";
//   int our = s21_sprintf(data, "|%.3s| gdb gdb |%20s|\n", "SaLLam", "salam");
//   int original = sprintf(data1, "|%.3s| gdb gdb |%20s|\n", "SaLLam",
//   "salam"); ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_s_1) {
//   char str1[1024] = "\0";
//   char str2[1024] = "\0";

//   char *format = "%s";
//   char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_char_multy) {
//   char c = 'B';
//   char result[1024] = "\0";
//   char assert[1024] = "\0";
//   s21_sprintf(result, "Char: %c%c%c", c, c, c);
//   sprintf(assert, "Char: %c%c%c", c, c, c);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

// START_TEST(test_c_1) {
//   char data[1024] = "\0";
//   char data1[1024] = "\0";
//   int our = s21_sprintf(data, "%c", '1');
//   int original = sprintf(data1, "%c", '1');
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_c_2) {
//   char data[100];
//   char data1[100];
//   int our = s21_sprintf(data, "%c", 'A');
//   int original = sprintf(data1, "%c", 'A');
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_c_3) {
//   char data[100];
//   char data1[100];
//   int our = s21_sprintf(data, "%c", '.');
//   int original = sprintf(data1, "%c", '.');
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_c_4) {
//   char our[20] = {'\0'};
//   char original[20] = {'\0'};
//   char c = 'z';
//   s21_sprintf(our, "%lc", c);
//   sprintf(original, "%lc", c);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_c_5) {
//   char our[20];
//   char original[20];
//   char c = 'a';
//   s21_sprintf(our, "%-3c", c);
//   sprintf(original, "%-3c", c);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_i_1) {
//   char data[100];
//   char data1[100];
//   int our = s21_sprintf(data, "%i", 'a');
//   int original = sprintf(data1, "%i", 'a');
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_i_2) {
//   char data[100];
//   char data1[100];
//   int our = s21_sprintf(data, "%i", 1);
//   int original = sprintf(data1, "%i", 1);
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_i_3) {
//   char data[100];
//   char data1[100];
//   int our = s21_sprintf(data, "%i", 2147483647);
//   int original = sprintf(data1, "%i", 2147483647);
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(test_i_4) {
//   char our[40];
//   char original[40];
//   int i = 327710;
//   s21_sprintf(our, "%-+10.5i abc abc", i);
//   sprintf(original, "%-+10.5i abc abc", i);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_i_5) {
//   char our[40];
//   char original[40];
//   int i = 327710;
//   s21_sprintf(our, "%+10.5i end", i + 1);
//   sprintf(original, "%+10.5i end", i + 1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_scdi_1) {
//   char data[100], data1[100];
//   int our = s21_sprintf(data, "%s%c%+5.5d% 5.i", "Hello world", 'a', 5, 5);
//   int original = sprintf(data1, "%s%c%+5.5d% 5.i", "Hello world", 'a', 5, 5);
//   ck_assert_int_eq(our, original);
// }
// END_TEST

// START_TEST(LD_2) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%2.5ld", -100000000000);
//   sprintf(original, "%2.5ld", -100000000000);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_1) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%u", 0);
//   sprintf(original, "%u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_2) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%.u", 0);
//   sprintf(original, "%.u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_3) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%10.u", 0);
//   sprintf(original, "%10.u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_4) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%10.2u", 0);
//   sprintf(original, "%10.2u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_5) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-10.2u", 0);
//   sprintf(original, "%-10.2u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_6) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-.2u", 0);
//   sprintf(original, "%-.2u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_7) {
//   char our[200];
//   char original[200];
//   s21_sprintf(our, "%lu", 100000000000);
//   sprintf(original, "%lu", 100000000000);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_8) {
//   char our[100];
//   char original[100];
//   short int x = 400;
//   s21_sprintf(our, "%hu", x);
//   sprintf(original, "%hu", x);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_9) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-5u", 0);
//   sprintf(original, "%-5u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_10) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%5u", 0);
//   sprintf(original, "%5u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_11) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-u", 0);
//   sprintf(original, "%-u", 0);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_12) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%3.5u", 20);
//   sprintf(original, "%3.5u", 20);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_13) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%3.5lu", 100000000000);
//   sprintf(original, "%3.5lu", 100000000000);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_14) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%u", -1);
//   sprintf(original, "%u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_15) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%.u", -1);
//   sprintf(original, "%.u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_16) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%10.u", -1);
//   sprintf(original, "%10.u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_17) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%10.2u", -1);
//   sprintf(original, "%10.2u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_18) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-10.2u", -1);
//   sprintf(original, "%-10.2u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_19) {
//   char our[100];
//   char original[100];
//   s21_sprintf(our, "%-.2u", -1);
//   sprintf(original, "%-.2u", -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(flag_u_21) {
//   char our[100];
//   char original[100];
//   short int x = -400;
//   s21_sprintf(our, "%hu", x);
//   sprintf(original, "%hu", x);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_1) {
//   char our[40];
//   char original[40];
//   float f = -14.537;
//   s21_sprintf(our, "%.6f end", f);
//   sprintf(original, "%.6f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_2) {
//   char our[40];
//   char original[40];
//   float f = 14.537;
//   s21_sprintf(our, "%2.2f end", f);
//   sprintf(original, "%2.2f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_3) {
//   char our[40];
//   char original[40];
//   float f = 1.0010021;
//   s21_sprintf(our, "%f end", f);
//   sprintf(original, "%f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_4) {
//   char our[40];
//   char original[40];
//   float f = 0;
//   s21_sprintf(our, "%f end", f);
//   sprintf(original, "%f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_5) {
//   char our[40];
//   char original[40];
//   float f = 0.;
//   s21_sprintf(our, "%f end", f);
//   sprintf(original, "%f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_6) {
//   char our[40];
//   char original[40];
//   float f = -123.321;
//   s21_sprintf(our, "%f end", f);
//   sprintf(original, "%f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_7) {
//   char our[40];
//   char original[40];
//   float f = -.0000001;
//   s21_sprintf(our, "%f end", f);
//   sprintf(original, "%f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_8) {
//   char our[40];
//   char original[40];
//   float f = -.0000001;
//   s21_sprintf(our, "%10f end", f);
//   sprintf(original, "%10f end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_9) {
//   char our[40];
//   char original[40];
//   double f = -.0000001;
//   s21_sprintf(our, "%3.5lf end", f);
//   sprintf(original, "%3.5lf end", f);
//   ck_assert_str_eq(our, original);
// }
// END_TEST

// START_TEST(test_f_10) {
//   char our[40];
//   char original[40];
//   double f = 3.2;
//   s21_sprintf(our, "%+-3.5lf end", f);
//   sprintf(original, "%+-3.5lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_11) {
//   char our[40];
//   char original[40];
//   double f = 3.2;
//   s21_sprintf(our, "%- 3.5lf end", f);
//   sprintf(original, "%- 3.5lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_12) {
//   char our[40];
//   char original[40];
//   double f = -3.2;
//   s21_sprintf(our, "%- 3.5lf end", f);
//   sprintf(original, "%- 3.5lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_13) {
//   char our[40];
//   char original[40];
//   double f = -3.2;
//   s21_sprintf(our, "%- 3.lf end", f);
//   sprintf(original, "%- 3.lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_14) {
//   char our[40];
//   char original[40];
//   double f = -3.45;
//   s21_sprintf(our, "%- 3.lf end", f);
//   sprintf(original, "%- 3.lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_15) {
//   char our[40];
//   char original[40];
//   double f = -3.45;
//   s21_sprintf(our, "%3.lf end", f);
//   sprintf(original, "%3.lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_16) {
//   char our[40];
//   char original[40];
//   double f = -3.45;
//   s21_sprintf(our, "%3.1lf end", f);
//   sprintf(original, "%3.1lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_17) {
//   char our[40];
//   char original[40];
//   double f = -0.45;
//   s21_sprintf(our, "%.1lf end", f);
//   sprintf(original, "%.1lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_f_18) {
//   char our[40];
//   char original[40];
//   double f = -0.45;
//   s21_sprintf(our, "%.lf end", f);
//   sprintf(original, "%.lf end", f);
//   ck_assert_str_eq(our, original);
// }
// START_TEST(test_several_1) {
//   char our[40];
//   char original[40];
//   double f = -0.45;
//   s21_sprintf(our, "%.lf%10.u end", f, -1);
//   sprintf(original, "%.lf%10.u end", f, -1);
//   ck_assert_str_eq(our, original);
// }
// END_TEST
// Suite *suite_s21_sprintf(void) {
//   Suite *sprintf_suite;
//   TCase *test_core;
//   sprintf_suite = suite_create("s21_sprintf");
//   test_core = tcase_create("case_sprintf");
//   tcase_add_test(test_core, sprintf_D_0);
//   tcase_add_test(test_core, sprintf_D_1);
//   tcase_add_test(test_core, sprintf_D_2);
//   tcase_add_test(test_core, sprintf_D_3);
//   tcase_add_test(test_core, sprintf_D_4);
//   tcase_add_test(test_core, sprintf_D_6);
//   tcase_add_test(test_core, HD_1);
//   tcase_add_test(test_core, d_plus);
//   tcase_add_test(test_core, D_minus);
//   tcase_add_test(test_core, sprintf_D_7);
//   tcase_add_test(test_core, sprintf_D_8);
//   tcase_add_test(test_core, sprintf_D_9);
//   tcase_add_test(test_core, sprintf_D_10);
//   tcase_add_test(test_core, sprintf_D_11);
//   tcase_add_test(test_core, sprintf_D_12);
//   tcase_add_test(test_core, sprintf_D_13);
//   tcase_add_test(test_core, test_D_12);
//   tcase_add_test(test_core, sprintf_S_1);
//   tcase_add_test(test_core, minus_S_1);
//   tcase_add_test(test_core, sprintf_S_2);
//   tcase_add_test(test_core, test_s_1);
//   tcase_add_test(test_core, minus_S_2);
//   tcase_add_test(test_core, accuracy_S_1);
//   tcase_add_test(test_core, accuracy_S_2);
//   tcase_add_test(test_core, accuracy_S_3);
//   tcase_add_test(test_core, accuracy_S_4);
//   tcase_add_test(test_core, accuracy_S_5);
//   tcase_add_test(test_core, test_c_1);
//   tcase_add_test(test_core, test_c_2);
//   tcase_add_test(test_core, test_c_3);
//   tcase_add_test(test_core, test_c_4);
//   tcase_add_test(test_core, test_c_5);
//   tcase_add_test(test_core, test_char_multy);
//   tcase_add_test(test_core, test_i_1);
//   tcase_add_test(test_core, test_i_2);
//   tcase_add_test(test_core, test_i_3);
//   tcase_add_test(test_core, test_i_4);
//   tcase_add_test(test_core, test_i_5);
//   tcase_add_test(test_core, LD_1);
//   tcase_add_test(test_core, LD_2);
//   tcase_add_test(test_core, HD_1);
//   tcase_add_test(test_core, test_scdi_1);
//   tcase_add_test(test_core, flag_u_1);
//   tcase_add_test(test_core, flag_u_2);
//   tcase_add_test(test_core, flag_u_3);
//   tcase_add_test(test_core, flag_u_4);
//   tcase_add_test(test_core, flag_u_5);
//   tcase_add_test(test_core, flag_u_6);
//   tcase_add_test(test_core, flag_u_7);
//   tcase_add_test(test_core, flag_u_8);
//   tcase_add_test(test_core, flag_u_9);
//   tcase_add_test(test_core, flag_u_10);
//   tcase_add_test(test_core, flag_u_11);
//   tcase_add_test(test_core, flag_u_12);
//   tcase_add_test(test_core, flag_u_13);
//   tcase_add_test(test_core, flag_u_14);
//   tcase_add_test(test_core, flag_u_15);
//   tcase_add_test(test_core, flag_u_16);
//   tcase_add_test(test_core, flag_u_17);
//   tcase_add_test(test_core, flag_u_18);
//   tcase_add_test(test_core, flag_u_19);
//   tcase_add_test(test_core, flag_u_21);
//   tcase_add_test(test_core, test_f_1);
//   tcase_add_test(test_core, test_f_2);
//   tcase_add_test(test_core, test_f_3);
//   tcase_add_test(test_core, test_f_4);
//   tcase_add_test(test_core, test_f_5);
//   tcase_add_test(test_core, test_f_6);
//   tcase_add_test(test_core, test_f_7);
//   tcase_add_test(test_core, test_f_8);
//   tcase_add_test(test_core, test_f_9);
//   tcase_add_test(test_core, test_f_10);
//   tcase_add_test(test_core, test_f_11);
//   tcase_add_test(test_core, test_f_12);
//   tcase_add_test(test_core, test_f_13);
//   tcase_add_test(test_core, test_f_14);
//   tcase_add_test(test_core, test_f_15);
//   tcase_add_test(test_core, test_f_16);
//   tcase_add_test(test_core, test_f_17);
//   tcase_add_test(test_core, test_f_18);
//   tcase_add_test(test_core, D_11);
//   tcase_add_test(test_core, test_no_args);
//   tcase_add_test(test_core, test_several_1);
//   suite_add_tcase(sprintf_suite, test_core);
//   return sprintf_suite;
// }

// int main() {
//   Suite *suite = suite_s21_sprintf();
//   SRunner *runner = srunner_create(suite);
//   srunner_run_all(runner, CK_NORMAL);
//   int failures = srunner_ntests_failed(runner);
//   srunner_free(runner);
//   return failures == 0 ? 0 : 1;
// }

START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(null_ptr) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%p";
//   char *ptr = NULL;
//   ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format,
//   ptr));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);

  // hex = 0.0000334;
  // s21_sprintf(str1, format, hex);
  // sprintf(str2, format, hex);
  // ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(percent) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% % % % % % %d";

  ck_assert_int_eq(s21_sprintf(str1, format, 4), sprintf(str2, format, 4));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *suite = suite_create("\033[32ms21_sprintf\033[0m");
  TCase *tc = tcase_create("sprintf");
  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, precise_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, minus_width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, padding_int);
  tcase_add_test(tc, star_width_int);
  tcase_add_test(tc, star_precision_int);
  tcase_add_test(tc, many_flags_many_ints);
  tcase_add_test(tc, flags_long_int);
  tcase_add_test(tc, flags_short_int);
  tcase_add_test(tc, flags_another_long_int);
  tcase_add_test(tc, zero_precision_zero_int);
  tcase_add_test(tc, space_flag_int);
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_flags);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_many_flags);
  tcase_add_test(tc, unsigned_val_short);
  tcase_add_test(tc, unsigned_val_long);
  tcase_add_test(tc, unsigned_val_many);
  tcase_add_test(tc, octal);
  tcase_add_test(tc, octal_width);
  tcase_add_test(tc, octal_flags);
  tcase_add_test(tc, octal_precision);
  tcase_add_test(tc, octal_many_flags);
  tcase_add_test(tc, octal_short);
  tcase_add_test(tc, octal_long);
  tcase_add_test(tc, octal_many);
  tcase_add_test(tc, octal_zero);
  tcase_add_test(tc, octal_hash);
  tcase_add_test(tc, unsigned_zero);
  tcase_add_test(tc, hex_width);
  tcase_add_test(tc, hex_precision);
  tcase_add_test(tc, hex_many_flags);
  tcase_add_test(tc, hex_zero);
  tcase_add_test(tc, hex_huge);
  tcase_add_test(tc, hex_short);
  tcase_add_test(tc, hex_long);
  tcase_add_test(tc, hex_one_longer_width);
  tcase_add_test(tc, hex_two_longer_width);
  tcase_add_test(tc, one_char);
  tcase_add_test(tc, one_precision);
  tcase_add_test(tc, one_flags);
  tcase_add_test(tc, one_width);
  tcase_add_test(tc, one_many);
  tcase_add_test(tc, one_many_flags);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_precision);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, string_flags);
  tcase_add_test(tc, string_long);
  tcase_add_test(tc, string_many);
  tcase_add_test(tc, ptr);
  tcase_add_test(tc, ptr_width);
  tcase_add_test(tc, ptr_precision);
  // tcase_add_test(tc, null_ptr);
  tcase_add_test(tc, n_specifier);
  tcase_add_test(tc, string_width_huge);
  tcase_add_test(tc, float_precision);
  tcase_add_test(tc, float_width);
  tcase_add_test(tc, float_precision_zero);
  tcase_add_test(tc, float_precision_empty);
  tcase_add_test(tc, float_huge);
  tcase_add_test(tc, float_flags);
  tcase_add_test(tc, e_precision_zero);
  tcase_add_test(tc, e_precision_empty);
  tcase_add_test(tc, e_huge);
  tcase_add_test(tc, e_width);
  tcase_add_test(tc, e_flags);
  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, empty_format_and_parameters);
  tcase_add_test(tc, test_one_char);
  tcase_add_test(tc, test_many_char);
  tcase_add_test(tc, test_one_string);
  tcase_add_test(tc, test_many_string);
  tcase_add_test(tc, test_one_dec);
  tcase_add_test(tc, test_many_dec);
  tcase_add_test(tc, test_one_int);
  tcase_add_test(tc, test_many_int);
  tcase_add_test(tc, test_one_float);
  tcase_add_test(tc, test_one_unsigned_dec);
  tcase_add_test(tc, test_many_unsigned_dec);
  tcase_add_test(tc, test_one_char_with_alignment_left);
  tcase_add_test(tc, test_one_char_with_alignment_right);
  tcase_add_test(tc, test_many_char_with_alignment);
  tcase_add_test(tc, test_many_hex_lower);
  tcase_add_test(tc, test_many_hex_upper);
  tcase_add_test(tc, test_many_hex_lower_with_alignment);
  tcase_add_test(tc, test_many_hex_upper_with_alignment);
  tcase_add_test(tc, test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, test_many_hex_upper_with_width_star);
  tcase_add_test(tc, test_one_hex_lower_with_precision);
  tcase_add_test(tc, test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc, test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc, test_one_hex_lower_with_length);
  tcase_add_test(tc, test_one_hex_upper_with_length);
  tcase_add_test(tc, g_trailing_zero);
  tcase_add_test(tc, g_large);
  tcase_add_test(tc, g_small);
  tcase_add_test(tc, g_precision);
  tcase_add_test(tc, g_precision_zero);
  tcase_add_test(tc, g_precision_missing);
  tcase_add_test(tc, g_many_zeroes_in_front);
  tcase_add_test(tc, g_one_zero);
  tcase_add_test(tc, g_mantiss);
  tcase_add_test(tc, g_short_no_mantiss);
  tcase_add_test(tc, LG);
  tcase_add_test(tc, g_many);
  tcase_add_test(tc, g_zero);
  tcase_add_test(tc, percent);
  suite_add_tcase(suite, tc);
  return suite;
}

int main() {
  Suite *suite;
  int failed = 0;
  SRunner *runner;

  suite = suite_sprintf();
  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}