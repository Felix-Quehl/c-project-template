bin = libmycode.so
src = $(shell find . -type f -name *.c)
obj = $(patsubst %.c,%.o,$(src))
trash = $(shell find . -type f  -regex '^.*[\.so|\.out|\.o]$$')

CFLAGS = -std=c89 -Wall -Werror -I./include

all: release

release: CFLAGS += -O3 -s
release: $(bin)

debug: CFLAGS += -g
debug: $(bin)

%.so: $(obj)
	$(CC) $(CFLAGS) --shared -fpic -o $@ $^

clean: 
	$(RM) $(trash)
