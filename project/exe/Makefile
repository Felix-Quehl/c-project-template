bin = hello.out
src = $(shell find . -type f -name *.c)
obj = $(patsubst %.c,%.o,$(src))
trash = $(shell find . -type f  -regex '^.*[\.so|\.out|\.o]$$')

CFLAGS = -std=c17 -Wall -Werror -I./include -I../lib/include
LDFLAGS = -L../lib
LIBS = -lmycode

all: release

release: CFLAGS += -O3 -s
release: $(lib_deb) $(bin)

debug: CFLAGS += -g
debug: $(lib_deb) $(bin)

%.out: $(obj)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

clean: 
	$(RM) $(trash)
