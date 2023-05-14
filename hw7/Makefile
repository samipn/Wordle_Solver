CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: businessdb test_functions

businessdb: command_util.o businessdb.o
	$(CC) command_util.o businessdb.o -o businessdb

test_functions: command_util.o test_functions.o
	$(CC) command_util.o test_functions.o -o test_functions

test_functions.o:
	$(CC) $(CFLAGS) -c test_functions.c 

command_util.o:
	$(CC) $(CFLAGS) -c command_util.c 

businessdb.o:
	$(CC) $(CFLAGS) -c businessdb.c 

clean:
	rm -f command_util.o businessdb.o test_functions.o businessdb test_functions

format:
	clang-format -i -style=file *.[ch]
