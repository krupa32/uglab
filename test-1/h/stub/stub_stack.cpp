#include <stdio.h>
#include "stack.h"

int main()
{
	Stack s, *s1;

	printf("testing push/pop...");
	s.push(1);
	s.push(2);
	s.push(3);
	if (s.pop() != 3 || s.pop() != 2 || s.pop() != 1 || s.pop() != -1)
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	s.push(1);
	if (s.empty())
		goto fail;
	s.pop();
	if (!s.empty())
		goto fail;
	printf("[ok]\n");

	printf("testing duplicate...");
	s.push(1);
	s.push(2);
	s.push(3);
	s1 = s.duplicate();
	if (s.pop() != 3 || s.pop() != 2 || s.pop() != 1 || s.pop() != -1)
		goto fail;
	if (s1->pop() != 3 || s1->pop() != 2 || s1->pop() != 1 || s1->pop() != -1)
		goto fail;
	printf("[ok]\n");

	printf("testing reverse...");
	s.push(1);
	s.push(2);
	s.push(3);
	s1 = s.reverse();
	if (s.pop() != 3 || s.pop() != 2 || s.pop() != 1 || s.pop() != -1)
		goto fail;
	if (s1->pop() != 1 || s1->pop() != 2 || s1->pop() != 3 || s1->pop() != -1)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
