#include <assert.h>
#include <stddef.h>

#include "stack.h"

#define lengthof(a) \
	sizeof(a) / sizeof(a[0])

#define use_as(ptr, type) \
	*(type *)(ptr)

static void
test_creation()
{
	stack_t *s;

	s = stack_create();
	
	assert(stack_is_empty(s) == 1);
	assert(stack_length(s) == 0);

	stack_destroy(s);
}

static void
test_usage()
{
	int nums[] = {1, 2, 3};
	int n = lengthof(nums);	

	stack_t *s;

	int i;
	int retcode;

	s = stack_create();

	for (i = 0; i < n; i++) {
		retcode = stack_push(s, &nums[i]);
		assert(retcode == 0);
		assert(stack_is_empty(s) == 0);
	}

	assert(stack_length(s) == n);

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
	test_creation();
	test_usage();

	return 0;
}
