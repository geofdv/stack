#include <stdlib.h>

#include "stack.h"
#include "list.h"

struct stack_s {
	list_t *list;
};

stack_t *
stack_create()
{
	stack_t *s;

	s = malloc(sizeof(*s));
	if (s == NULL) {
		return NULL;
	}

	s->list = list_create();
	if (s->list == NULL) {
		free(s);
		return NULL;
	}

	return s;
}

void
stack_destroy(stack_t *s)
{
	if (s == NULL) {
		return ;
	}

	list_destroy(s->list);
	free(s);
}

int
stack_push(stack_t *s, void *data)
{
	int retcode;
	
	if (s == NULL) {
		return -1;
	}

	retcode = list_push_front(s->list, data);
	if (retcode == -1) {
		return -1;
	}

	return 0;
}

int
stack_pop(stack_t *s)
{
	int retcode;
	
	if (s == NULL) {
		return -1;
	}

	if (stack_is_empty(s) == 1) {
		return -1;
	}

	retcode = list_pop_front(s->list);
	if (retcode == -1) {
		return -1;
	}

	return 0; 
}

int
stack_top(stack_t *s, void **data)
{
	int retcode;
	
	if (s == NULL) {
		return -1;
	}

	if (stack_is_empty(s) == 1) {
		return -1;
	}

	retcode = list_front(s->list, data);
	if (retcode == -1) {
		return -1;
	}

	return 0; 

}

int
stack_is_empty(stack_t *s)
{
	return s == NULL ? 1 : list_is_empty(s->list);
}

int
stack_length(stack_t *s)
{
	return s == NULL ? 0 : list_length(s->list);
}

