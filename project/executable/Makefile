SHELL := /bin/bash

name = example

src = $(shell find . -name '*.c')
obj = $(src:.c=.o)

all: release


release: flags = -O3 -s
release: target = release
release: dependecy
release: $(name)

debug: flags = -g
debug: target = debug
debug: dependecy
debug: $(name)

$(name): $(obj)
	gcc -L../library -o $@ $^ -lexample

.PHONY: dependecy
dependecy:
	cd ../library && make clean $(target)

%.o : %.c
	gcc -std=c89 $(flags) -c -Wall -Wextra -Werror -Wpedantic -I./include -I../library/include -o $@ $<

clean: $(dependecy)
	rm -rf $(shell find . -name '*.o' -o -name '*.so')
	rm -f $(name)

.ONESHELL:
