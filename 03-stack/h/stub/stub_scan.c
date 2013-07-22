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
	if (scan("abcdefgh3ab") != 7)
		goto fail;
	printf("[ok]\n");

	printf("test case 2...");
	if (scan("a8") != 0)
		goto fail;
	printf("[ok]\n");

	printf("test case 3...");
	if (scan("abcdefgh5defgh28ab") != 2)
		goto fail;
	printf("[ok]\n");

	printf("test case 4...");
	if (scan("cdefgh9abcd21") != 1)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
