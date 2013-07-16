
#define STACK_SIZE	50

char stack[STACK_SIZE];
int top = 0;

int push(char c)
{
	if (top == STACK_SIZE)
		return 0;

	stack[top] = c;
	top++;

	return 1;
}

int pop(char *c)
{
	if (top == 0)
		return 0;

	top--;
	*c = stack[top];

	return 1;
}
