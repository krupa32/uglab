#include <stdio.h>

#define MAX_ELEMENTS    100

class SimpleStack
{
	char arr[MAX_ELEMENTS];
	int top;

	public:
	SimpleStack();

	int push(char c);
	int pop(char *c);
	int empty(void);
};


int main()
{
	SimpleStack s;
	char c;

	printf("testing push/pop...");
	if (!s.push('a'))
		goto fail;
	if (!s.push('b'))
		goto fail;
	if (!s.push('c'))
		goto fail;
	if (!s.pop(&c) || c != 'c')
		goto fail;
	if (!s.pop(&c) || c != 'b')
		goto fail;
	if (!s.pop(&c) || c != 'a')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (!s.empty())
		goto fail;
	s.push('a');
	if (s.empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
