all: mytest.o

mytest.o: mytest.c
	gcc -Wall -Wextra -std=c99 mytest.c sll.c dll.c queue.c stack.c integer.c -o testing

clean:
	rm -f mytest.o
	rm -f testing

test: testing
	./testing