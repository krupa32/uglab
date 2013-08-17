#include <stdio.h>
#include "queue.h"


int main()
{
	Queue *q = Queue::create();
	char c;

	printf("testing insert/remove...");
	if (!q->insert('a'))
		goto fail;
	if (!q->insert('b'))
		goto fail;
	if (!q->insert('c'))
		goto fail;
	if (!q->remove(&c) || c != 'a')
		goto fail;
	if (!q->remove(&c) || c != 'b')
		goto fail;
	if (!q->remove(&c) || c != 'c')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (!q->empty())
		goto fail;
	q->insert('a');
	if (q->empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
