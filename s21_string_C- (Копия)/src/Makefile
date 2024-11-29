CC = gcc
FLAGS = -Wall -Werror -Wextra --std=c11
LIBS = -lcheck -lsubunit -lm -lgcov
FUNC_FILES_C = *.c
FUNC_FILES_O = *.o
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBNAME = s21_string.a
GLFLAGS = --coverage

all: s21_string.a

peer: 
	make clean
	make gcov_open

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_string.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o

test: all
	# make clean
	# make all
	$(CC) unit_tests/s21_memchr_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_memchr_test
	$(CC) unit_tests/s21_memcmp_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_memcmp_test
	$(CC) unit_tests/s21_memcpy_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_memcpy_test
	$(CC) unit_tests/s21_memset_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_memset_test
	$(CC) unit_tests/s21_strchr_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strchr_test
	$(CC) unit_tests/s21_strcspn_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strcspn_test
	$(CC) unit_tests/s21_strlen_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strlen_test
	$(CC) unit_tests/s21_strncat_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strncat_test
	$(CC) unit_tests/s21_strncmp_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strncmp_test
	$(CC) unit_tests/s21_strncpy_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strncpy_test
	$(CC) unit_tests/s21_strpbrk_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strpbrk_test
	$(CC) unit_tests/s21_strrchr_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strrchr_test
	$(CC) unit_tests/s21_strstr_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strstr_test
	$(CC) unit_tests/s21_strtok_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strtok_test
	$(CC) unit_tests/s21_strerror_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_strerror_test
	$(CC) unit_tests/s21_to_lower_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_to_lower_test
	$(CC) unit_tests/s21_to_upper_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_to_upper_test
	$(CC) unit_tests/s21_insert_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_insert_test
	$(CC) unit_tests/s21_trim_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_trim_test
	$(CC) unit_tests/s21_sprintf_test.c -L. s21_string.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sprintf_test
	make start_tests

start_tests:
	./s21_memchr_test
	./s21_memcmp_test
	./s21_memcpy_test
	./s21_memset_test
	./s21_strchr_test
	./s21_strcspn_test
	./s21_strlen_test
	./s21_strncat_test
	./s21_strncmp_test
	./s21_strncpy_test
	./s21_strpbrk_test
	./s21_strrchr_test
	./s21_strstr_test
	./s21_strtok_test
	./s21_strerror_test
	./s21_to_lower_test
	./s21_to_upper_test
	./s21_insert_test
	./s21_trim_test
	./s21_sprintf_test

gcov_report: clean build_object_files build_library test
	gcov $(FUNC_FILES_C)
	~/.local/bin/gcovr -r . --html --html-details -o s21_string.html

gcov_open: 
	make gcov_report
	@echo "Opening report..."
	xdg-open s21_string.html

clean:
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.a
	rm -f *.info
	rm -f *.html
	rm -f *.css
	rm -f s21_*_test

rebuild:
	make clean
	make

.PHONY: cl
cl:
	clang-format -n *.c *.h
	clang-format -n unit_tests/*.c *.h

.PHONY: cl-i
cl-i:
	clang-format -i *.c *.h
	clang-format -i unit_tests/*.c *.h

.PHONY: cpp
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c unit_tests/*.c

.PHONY: val
val:
	valgrind --tool=memcheck --leak-check=full ./s21_memchr_test
	valgrind --tool=memcheck --leak-check=full ./s21_memcmp_test
	valgrind --tool=memcheck --leak-check=full ./s21_memcpy_test
	valgrind --tool=memcheck --leak-check=full ./s21_memset_test
	valgrind --tool=memcheck --leak-check=full ./s21_strchr_test
	valgrind --tool=memcheck --leak-check=full ./s21_strcspn_test
	valgrind --tool=memcheck --leak-check=full ./s21_strlen_test
	valgrind --tool=memcheck --leak-check=full ./s21_strncat_test
	valgrind --tool=memcheck --leak-check=full ./s21_strncmp_test
	valgrind --tool=memcheck --leak-check=full ./s21_strncpy_test
	valgrind --tool=memcheck --leak-check=full ./s21_strpbrk_test
	valgrind --tool=memcheck --leak-check=full ./s21_strrchr_test
	valgrind --tool=memcheck --leak-check=full ./s21_strstr_test
	valgrind --tool=memcheck --leak-check=full ./s21_strtok_test
	valgrind --tool=memcheck --leak-check=full ./s21_strerror_test
	valgrind --tool=memcheck --leak-check=full ./s21_to_lower_test
	valgrind --tool=memcheck --leak-check=full ./s21_to_upper_test
	valgrind --tool=memcheck --leak-check=full ./s21_insert_test
	valgrind --tool=memcheck --leak-check=full ./s21_trim_test
	valgrind --tool=memcheck --leak-check=full ./s21_sprintf_test
