#include "queue.h"
#include "arrayqueue.h"

ArrayQueue::ArrayQueue()
{
	tail = 0;
}

int ArrayQueue::insert(char c)
{
	if (tail == MAX_ELEMENTS)
		return -1;

	arr[tail++] = c;
}

int ArrayQueue::remove(char *c)
{
	int i;

	if (tail == 0)
		return 0;

	*c = arr[0];

	for (i = 0; i < tail - 1; i++)
		arr[i] = arr[i + 1];

	--tail;

	return 1;
}

int ArrayQueue::empty(void)
{
	return (tail == 0);
}

Queue * Queue::create(void)
{
	return new ArrayQueue();
}
