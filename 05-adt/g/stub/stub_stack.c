#include <stdio.h>

void * stack_create(void);
void stack_free(void *stack);
int stack_push(void *stack, char c);
int stack_pop(void *stack, char *c);
int stack_empty(void *stack);

int main()
{
	void *stack;
	char c;

	printf("testing create stack...");
	if ((stack = stack_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing push/pop...");
	if (stack_push(stack, 'a') == 0)
		goto fail;
	if (stack_push(stack, 'b') == 0)
		goto fail;
	if (stack_push(stack, 'c') == 0)
		goto fail;
	if (stack_pop(stack, &c) == 0)
		goto fail;
	if (c != 'c')
		goto fail;
	if (stack_pop(stack, &c) == 0)
		goto fail;
	if (c != 'b')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (stack_empty(stack))
		goto fail;
	stack_pop(stack, &c);
	if (!stack_empty(stack))
		goto fail;
	printf("[ok]\n");

	printf("testing free stack...");
	stack_free(stack);
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
