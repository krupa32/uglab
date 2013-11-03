
#define STACK_SIZE	50

int stack[STACK_SIZE];
int top = 0;

int push(int n)
{
	if (top == STACK_SIZE)
		return 0;

	stack[top] = n;
	top++;

	return 1;
}

int pop(int *n)
{
	if (top == 0)
		return 0;

	top--;
	*n = stack[top];

	return 1;
}

int empty(void)
{
	return (top == 0);
}
