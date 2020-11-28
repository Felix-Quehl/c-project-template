SHELL := /bin/bash

# app name
name = app
name_release = $(name).release
name_debug = $(name).debug
name_test = $(name).test
src_path = ./src

# compiler config
CC = gcc
WARNIGS= -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option
CFLAGS = $(WARNIGS) -std=c89 -I./includes
LDFLAGS = -I./includes

# sources and entry point
src = $(shell find $(src_path) -name *.c ! -name *_test.c ! -name main.c)
src_main = $(shell find $(src_path) -name main.c)
obj = $(src:.c=.o)
obj_gcda = $(src:.c=.gcda)
obj_gcno = $(src:.c=.gcno)
obj_main = $(src_main:.c=.o)

# test sources and entry point
src_test = $(shell find $(src_path) -name *_test.c)
obj_test = $(src_test:.c=.o)

# files to clean up
trash = $(shell find ./ -name "*.o")
trash += $(shell find ./ -name "*.gcov") 
trash += $(shell find ./ -name "*.gcno")
trash += $(shell find ./ -name "*.gcda")

# coverage script
define coverage_check  =
	total=$(grep -E '^[[:space:]]+[0-9|#]+' ./*.gcov | wc -l)
	coverd=$(grep -E '^[[:space:]]+[1-9]+' ./*.gcov | wc -l)
	converage=$(printf %.2f\\n "$((10**9 * $coverd*100/$total))e-9")
	printf "Coverage = %.2f%%\\n" $converage
	awk 'BEGIN {exit !('$converage' >= '80.0')}'
	exit $?
endef

# default build
all: release

# release target
release: CFLAGS += -O3
release: $(name_release)
$(name_release): $(obj_main) $(obj)
	$(CC) $(LDFLAGS) -o $(name_release) $^

# debug target
debug: CFLAGS += -g
debug: LDFLAGS += -g
debug: $(name_debug)
$(name_debug): $(obj_main) $(obj)
	$(CC) $(LDFLAGS) -o $(name_debug) $^

# test build
test: CFLAGS += -g -fprofile-arcs -ftest-coverage 
test: LDFLAGS += -g -fprofile-arcs -ftest-coverage
test: $(name_test)
$(name_test): $(obj_test) $(obj)
	$(CC) $(LDFLAGS) -o $(name_test) $^

# run tests
check: $(name_test)
	./$(name_test)

# collect and check code coverage
coverage: coverage_collection coverage_check coverage_move

# collect code coverage with gcov
coverage_collection: $(obj_gcda) $(obj_gcno)
	gcov $(src)

# check cover coverage with bash script
coverage_check: ; $(value coverage_check)

# moves goverage files into src sir
coverage_move:
	mv *.gcov $(src_path)

# make object files from source code
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# remove old build files
clean:
	rm -rf $(trash)

.ONESHELL:
