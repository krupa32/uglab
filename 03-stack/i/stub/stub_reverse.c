#include <stdio.h>

extern int push(char c);
extern int pop(char *c);
extern void reverse(const char *str, char *reversei_str);

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

	printf("testing simple string reverse...");
	reverse("hello world", rev);
	if (strcmp(rev, "dlrow olleh") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing palindrome reverse...");
	reverse("101010101", rev);
	if (strcmp(rev, "101010101") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing single character string reverse...");
	reverse("h", rev);
	if (strcmp(rev, "h") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
