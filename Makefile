CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pedantic
SRC = control.c

all: control

control: control.c
	${CC} ${CFLAGS} -o $@ control.c

.PHONY: clean 

clean:
	rm -f *.o control
