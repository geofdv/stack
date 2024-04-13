#include <assert.h>
#include <stddef.h>

#include "stack.h"

#define lengthof(a) \
	sizeof(a) / sizeof(a[0])

#define use_as(ptr, type) \
	*(type *)(ptr)

static void
test1()
{
	stack_t *s;

	s = stack_create(10 /* max number of elems */);
	
	assert(stack_is_empty(s) == 1);
	assert(stack_is_full(s) == 0);

	stack_destroy(s);
}

static void
test2()
{
	int nums[] = {1, 2, 3};
	int n = lengthof(nums);	

	stack_t *s;
	int limit = n;

	int i;
	int retcode;

	s = stack_create(limit);

	for (i = 0; i < n; i++) {
		retcode = stack_push(s, &nums[i]);
		assert(retcode == 0);
		assert(stack_is_empty(s) == 0);
	}

	assert(stack_is_full(s) == 1);

	i = 0;
	while (stack_is_empty(s) == 0) {

		void *elem_addr = NULL;

		retcode = stack_top(s, &elem_addr);
		assert(retcode == 0);
		assert(elem_addr != NULL);

		assert(use_as(elem_addr, int) == nums[n - i - 1]);

		retcode = stack_pop(s);
		assert(retcode == 0);
		i++;
	}

	stack_destroy(s);
}

int
main()
{
	test1();
	test2();

	return 0;
}
