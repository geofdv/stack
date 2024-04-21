#include <assert.h>
#include <stddef.h> /* for NULL */

#include "list.h"

#define lengthof(a) \
	sizeof(a) / sizeof(a[0])

#define use_as(ptr, type) \
	*(type *)(ptr)

static void
test1()
{
	list_t *l;

	l = list_create();
	assert(list_is_empty(l) == 1);
	assert(list_length(l) == 0);

	list_destroy(l);
}

static void
test2()
{
	list_t *l;

	void *data;
	int retcode;

	l = list_create();
	assert(list_is_empty(l) == 1);
	assert(list_length(l) == 0);

	data = NULL;
	retcode = list_front(l, &data);
	assert(retcode == -1);

	retcode = list_pop_front(l);
	assert(retcode == -1);

	list_destroy(l);
}

static void
test3()
{
	int nums[] = {1, 2, 3};
	int n = lengthof(nums);	

	list_t *l;

	int i;
	int retcode;

	l = list_create();

	for (i = 0; i < n; i++) {
		retcode = list_push_front(l, &nums[i]);
		assert(retcode == 0);

		assert(list_is_empty(l) == 0);
		assert(list_length(l) == i + 1);
	}

	i = 0;
	while (list_is_empty(l) == 0) {

		void *elem_addr = NULL;

		retcode = list_front(l, &elem_addr);
		assert(retcode == 0);
		assert(elem_addr != NULL);

		assert(use_as(elem_addr, int) == nums[n - i - 1]);

		retcode = list_pop_front(l);
		assert(retcode == 0);
		i++;
	}

	list_destroy(l);
}

int
main()
{
	test1();
	test2();
	test3();

	return 0;
}
