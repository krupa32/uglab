#include <stdio.h>

extern int push(char c);
extern int pop(char *c);
extern int scan(const char *str);

int main()
{
	char ch, rev[50];

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

	printf("test case 1...");
	if (scan("11110000") != 0)
		goto fail;
	printf("[ok]\n");

	printf("test case 2...");
	if (scan("1111000") != 1)
		goto fail;
	printf("[ok]\n");

	printf("test case 3...");
	if (scan("111100000") != 0)
		goto fail;
	printf("[ok]\n");

	printf("test case 4...");
	if (scan("1111001100111110") != 6)
		goto fail;
	printf("[ok]\n");

	printf("test case 5...");
	if (scan("111100110011111000000000") != 4)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
