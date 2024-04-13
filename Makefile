CC = gcc
CFLAGS = -std=c89 -Wall -Werror -g3 -pedantic -DLINUX -D_GNU_SOURCE 
SRCMODULES = list.c stack.c
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

list: list_test.c list.c
	$(CC) $(INCLUDES) $(CFLAGS) $^ -o $@

stack: stack_test.c ${OBJMODULES}
	$(CC) $(INCLUDES) $(CFLAGS) $^ -o $@

run_tests: list stack
	./list && ./stack

mem_check_list: list
	valgrind ./list --leak-check=full -s

mem_check_stack: stack
	valgrind ./stack --leak-check=full -s

ifneq (clean, $(SRCMODULES))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean:
	rm -f *.o list stack
