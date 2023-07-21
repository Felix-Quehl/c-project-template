SHELL := /bin/bash

name = libexample.a

src = $(shell find . -name '*.c')
obj = $(src:.c=.o)

all: release

release: flags += -O3 -s
release: $(name)

debug: flags += -g
debug: $(name)

$(name): $(obj)
	ar rcs $@ $^

%.o : %.c
	gcc -c -std=c89  $(flags) -Wall -Wextra -Werror -Wpedantic -I./include -o $@ $<

clean:
	rm -rf $(shell find . -name '*.o' -o -name '*.a')

.ONESHELL:
