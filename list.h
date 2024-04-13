#ifndef LIST_SENTRY_H
#define LIST_SENTRY_H

typedef struct list_s list_t;

list_t *
list_create();

void
list_destroy(list_t *l);

int
list_push_front(list_t *l, void *data);

int
list_pop_front(list_t *l);

int
list_front(list_t *l, void **data);

int
list_is_empty(list_t *l);

int
list_length(list_t *l);

#endif /* LIST_SENTRY_H */

