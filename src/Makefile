CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: cat 

cat: cat.o flag_handlers.o parser.o
	$(CC) cat.o flag_handlers.o parser.o -o cat

cat.o: cat.c
	$(CC) $(CFLAGS) cat.c

flag_handlers.o: flag_handlers.c
	$(CC) $(CFLAGS) flag_handlers.c
	
parser.o: parser.c
	$(CC) $(CFLAGS) parser.c
	
commit:
	git pull
	git add .
	git commit -m "update"
	git push

clean:
	rm -rf *.o cat

rebuild: clean all
	
.PHONY: format
format:
	clang-format -i *.c *.h
