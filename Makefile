SHELL := /bin/bash

# app name
name = app
name_release = $(name).release
name_debug = $(name).debug
name_test = $(name).test
name_profraw = $(name).profraw
name_profdata = $(name).profdata
name_coverage_txt = $(name).coverage.txt
name_coverage_html = $(name).coverage.html
src_path = ./src

# compiler config
CC = clang
CFLAGS = -std=iso9899:1990 -ansi -Weverything -Wall -Wextra -Werror -Wpedantic -I./includes
LDFLAGS = -I./includes

# sources and entry point
src = $(shell find $(src_path) -name *.c ! -name *_test.c ! -name main.c)
src_main = $(shell find $(src_path) -name main.c)
obj = $(src:.c=.o)
obj_main = $(src_main:.c=.o)

# test sources and entry point
src_test = $(shell find $(src_path) -name *_test.c)
obj_test = $(src_test:.c=.o)

# files to clean up
trash = $(obj) $(name_profraw) $(name_profdata) $(name_coverage_html) $(name_coverage_txt)

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
test: CFLAGS += -g -fprofile-instr-generate -fcoverage-mapping
test: LDFLAGS += -g -fprofile-instr-generate -fcoverage-mapping
test: $(name_test)
$(name_test): $(obj_test) $(obj)
	$(CC) $(LDFLAGS) -o $(name_test) $^

# run tests
check: $(name_test)
	LLVM_PROFILE_FILE="$(name_profraw)" ./$(name_test)

# profraw recipie
$(name_profraw): check

# coverage recipie
coverage: coverage_report coverage_check

# collect and report coverage
coverage_report: $(name_profraw)
	llvm-profdata merge -sparse $(name_profraw) -o $(name_profdata)
	llvm-cov report $(name_test) -instr-profile=$(name_profdata) | tee $(name_coverage_txt)
	llvm-cov show -format=html $(name_test) -instr-profile=$(name_profdata) > $(name_coverage_html)


# check for minimum coverage
coverage_check: $(name_profraw)
	awk 'BEGIN {exit ('$(shell grep TOTAL $(name_coverage_txt) | grep -Po '^(TOTAL\s+)(\d+\s+)(\d+\s+)\d+\.\d+' | grep -Po '\d+\.\d+')' <= '80.0')}'	

# make object files from source code
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# remove old build files
clean:
	rm -rf $(trash)

.ONESHELL:
