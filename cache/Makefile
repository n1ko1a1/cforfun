SRCMODULES = mods/list/list.c mods/page/page.c
default_target = main.c
ifeq (run_unit_tests, $(MAKECMDGOALS))
SRCMODULES = test/impl/list_test.c mods/page/page.c mods/list/list.c
default_target = test/impl/main.c
endif
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -Wall -g -ansi -pedantic

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
	bash clean.sh . o mk out exe

run: prog
	./prog

run_unit_tests: prog
	./prog
