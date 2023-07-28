bin = test.out
src = $(shell find . -type f -name *.c)
obj = $(patsubst %.c,%.o,$(src))
trash = $(shell find . -type f  -regex '^.*[\.so|\.out|\.o]$$')

CFLAGS = -std=c89 -Wall -Werror -I./include -I../lib/include
LDFLAGS = -L../lib 
LIBS = -lmycode

all: release

release: CFLAGS += -O3 -s
release: test_execution

debug: CFLAGS += -g
debug: test_execution

test_execution: $(lib_deb)  $(bin)
	 LD_LIBRARY_PATH=../lib ./$(bin)

%.out: $(obj)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

clean: 
	$(RM) $(trash)

