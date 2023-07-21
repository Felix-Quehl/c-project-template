SHELL := /bin/bash

name = test.o

src = $(shell find . -name '*.c')
obj = $(src:.c=.o)

all:  $(name)

$(name): $(obj)
	gcc -L../library -o $@ $^ -lexample

%.o : %.c
	gcc -std=c89 -g -c -Wall -Wextra -Werror -Wpedantic -I./include -I../library/include -o $@ $<

clean:
	rm -rf $(shell find . -name '*.o' -o -name '*.so')

.ONESHELL:
