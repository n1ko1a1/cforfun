SRCMODULES = datastrucs/list.c datastrucs/page.c datastrucs/hashtable.c
default_target = main.c
ifeq (run_unit_tests, $(MAKECMDGOALS))
SRCMODULES = test/list_test.c test/hashtable_test.c datastrucs/page.c datastrucs/list.c datastrucs/hashtable.c
default_target = test/main.c
endif
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -Wall -g -ansi -pedantic
CC = gcc

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@	

prog: $(default_target) $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean:
	bash clean.sh . .o .mk .out .exe prog

run: prog
	./prog

run_unit_tests: prog
	./prog
