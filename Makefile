CC=gcc
CFLAGS=-fsanitize=address -Wall -Werror -std=gnu11 -g -lm

tests: linked_list.c tests.c 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f tests