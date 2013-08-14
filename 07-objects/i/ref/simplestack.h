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
