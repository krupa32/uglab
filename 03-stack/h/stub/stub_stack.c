#include <stdio.h>

extern int push(char c);
extern int pop(char *c);

int main()
{
	char ch;
	int i;

	printf("testing basic push/pop...");
	if (!push('c'))
		goto fail;
	if (!push('h'))
		goto fail;
	if (!pop(&ch))
		goto fail;
	if (ch != 'h')
		goto fail;
	if (!pop(&ch))
		goto fail;
	if (ch != 'c')
		goto fail;
	printf("[ok]\n");

	printf("testing stack full...");
	for (i = 0; i < 50; i++)
		push('a');
	if (push('b'))
		goto fail;
	for (i = 0; i < 50; i++)
		pop(&ch);
	printf("[ok]\n");

	printf("testing stack empty...");
	if (pop(&ch))
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
