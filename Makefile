# app name
name = app
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
obj_main = $(src_main:.c=.o)

# test sources and entry point
src_test = $(shell find $(src_path) -name *_test.c)
obj_test = $(src_test:.c=.o)

# files to clean up
trash = $(shell find ./ -name "*.o")
trash += $(shell find ./ -name "*.gcov") 
trash += $(shell find ./ -name "*.gcno")
trash += $(shell find ./ -name "*.gcda")

# default build
all: release

# release target
release: CFLAGS += -O3
release: $(obj_main) $(obj)
	$(CC) $(LDFLAGS) -o $(name).release $^

# debug target
debug: CFLAGS += -g
debug: LDFLAGS += -g
debug: $(obj_main) $(obj)
	$(CC) $(LDFLAGS) -o $(name).debug $^

# test build
test: CFLAGS += -g -fprofile-arcs -ftest-coverage 
test: LDFLAGS += -g -fprofile-arcs -ftest-coverage 
test: $(obj_test) $(obj)
	$(CC) $(LDFLAGS) -o $(name).test $^

check: ./$(name).test
	./$(name).test

coverage: ./$(name).test
	gcov $(src) --no-output --function-summaries

# make object files from source code
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# remove old build files
clean:
	rm -rf $(trash)