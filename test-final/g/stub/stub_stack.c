#include <stdio.h>

extern int push(int n);
extern int pop(int *n);

int main()
{
	int n;
	int i;

	printf("testing push...");
	for (i = 0; i < 50; i++) {
		if (!push(29 + i * i))
			goto test_pop;
	}
	if (push(29 + i * i))
		goto test_pop;
	printf("[ok]\n");

test_pop:
	printf("testing pop...");
	for (i = 49; i >= 0; i--) {
		if (!pop(&n) || n != (29+i*i))
			goto test_empty;
	}
	if (pop(&n))
		goto test_empty;
	printf("[ok]\n");

test_empty:
	printf("testing empty...");
	if (!empty())
		goto fail;
	push(1);
	if (empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
