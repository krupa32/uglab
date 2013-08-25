#include <stdio.h>
#include "queue.h"

int main()
{
	Queue *s = Queue::create();
	char c;

	printf("testing insert/remove...");
	if (!s->insert('a'))
		goto fail;
	if (!s->insert('b'))
		goto fail;
	if (!s->insert('c'))
		goto fail;
	if (!s->remove(&c) || c != 'a')
		goto fail;
	if (!s->remove(&c) || c != 'b')
		goto fail;
	if (!s->remove(&c) || c != 'c')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (!s->empty())
		goto fail;
	s->insert('a');
	if (s->empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;

}
