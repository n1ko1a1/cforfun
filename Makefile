SRCMODULES = list.c page.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -Wall -g -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@	

prog: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean: 
	rm -f *.o *.mk prog

run:
	./prog
