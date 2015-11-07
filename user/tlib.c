#include "types.h"
#include "user.h"

#define PGSIZE		4096

int
thread_create(void (*start_routine)(void*), void *arg)
{
	void *tmp, *stack;
	if((tmp = malloc(2 * PGSIZE)) == 0)
		return -1;
	//TODO: optimize this to free all the allocated space
	stack = (void *)((uint)tmp + (PGSIZE - (uint)tmp % PGSIZE));
	return clone(start_routine, arg, stack);
}

int
thread_join()
{
	void *stack;
	int ret = join(&stack);
	free(stack);
	return ret;
}

void
lock_init(lock_t *lk)
{

}

void
lock_acquire(lock_t *lk)
{

}

void
lock_release(lock_t *lk)
{

}
