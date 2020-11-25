# compiler config
CC = gcc
CFLAGS = -std=c89 -Wall -I./includes
LDFLAGS = 

# source, object and target
src = $(shell find ./src -name *.c)
obj = $(src:.c=.o)

# app name
name = app

# default build
all: release

# release target
release: target_name = $(name).release
release: target

# debug target
debug: CFLAGS += -g
debug: LDFLAGS += -g
debug: target_name = $(name).debug
debug: target

# link objects into program
target: $(obj)
	$(CC) $(LDFLAGS) -o $(target_name) $^

# make object files from source code
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# remove old build files
clean:
	rm -rf $(obj)
