#include <stdio.h>
#include "stack.h"

int main()
{
	Stack *s = Stack::create();
	char c;

	printf("testing push/pop...");
	if (!s->push('a'))
		goto fail;
	if (!s->push('b'))
		goto fail;
	if (!s->push('c'))
		goto fail;
	if (!s->pop(&c) || c != 'c')
		goto fail;
	if (!s->pop(&c) || c != 'b')
		goto fail;
	if (!s->pop(&c) || c != 'a')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (!s->empty())
		goto fail;
	s->push('a');
	if (s->empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;

}
