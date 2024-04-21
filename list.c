#include <stdlib.h>

#include "list.h"

typedef struct node_s node_t;

struct list_s {
	node_t *head;
	int len;
};

struct node_s {
	void *data;
	node_t *next;
};

static node_t *
node_create(node_t *next, void *data);

static void
node_destroy(node_t *node);

list_t *
list_create()
{
	list_t *l;

	l = malloc(sizeof(*l));
	if (l == NULL) {
		return NULL;
	}

	l->head = NULL;
	l->len = 0;

	return l;
}

void
list_destroy(list_t *l)
{
	node_t *cur_node;

	if (l == NULL) {
		return ;
	}

	cur_node = l->head;

	while (cur_node != NULL) {
		node_t *tmp = cur_node;
		cur_node = cur_node->next;
		node_destroy(tmp);
	}

	free(l);
}

int
list_push_front(list_t *l, void *data)
{
	node_t *new_head;

	if (l == NULL) {
		return -1;
	}

	new_head = node_create(l->head, data);
	if (new_head == NULL) {
		return -1;
	}

	l->head = new_head;
	l->len++;

	return 0;
}

int
list_pop_front(list_t *l)
{
	node_t *old_head;

	if (l == NULL) {
		return -1;
	}

	if (list_is_empty(l) == 1) {
		return -1;
	}

	old_head = l->head;
	l->head = old_head->next;

	node_destroy(old_head);

	l->len--;

	return 0;
}

int
list_front(list_t *l, void **data)
{
	if (l == NULL) {
		return -1;
	}

	if (data == NULL) {
		return -1;
	}

	if (list_is_empty(l) == 1) {
		return -1;
	}

	*data = l->head->data;

	return 0;
}

int
list_length(list_t *l)
{
	return l == NULL ? 0 : l->len;
}

int
list_is_empty(list_t *l)
{
	return list_length(l) == 0;
}

static node_t *
node_create(node_t *next, void *data)
{
	node_t *n;

	n = malloc(sizeof(*n));
	if (n == NULL) {
		return NULL;
	}

	n->next = next;
	n->data = data;

	return n;
}

static void
node_destroy(node_t *node)
{
	free(node);
}

