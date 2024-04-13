#ifndef STACK_SENTRY_H
#define STACK_SENTRY_H

/*
 * This stack doesn't own data.
 */

typedef struct stack_s stack_t;

/* Lifetime managment. */
stack_t *
stack_create(int limit);

void
stack_destroy(stack_t *s);

/* Modifiers. */
int
stack_push(stack_t *s, void *data);

int
stack_pop(stack_t *s);

/* State. */
int
stack_top(stack_t *s, void **data);

int
stack_is_empty(stack_t *s);

int
stack_is_full(stack_t *s);

#endif /* STACK_SENTRY_H */

