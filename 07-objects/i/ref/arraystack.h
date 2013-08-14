#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stack.h"

#define MAX_ELEMENTS    100

class ArrayStack : public Stack
{
	char arr[MAX_ELEMENTS];
	int top;

public:
	ArrayStack();

	int push(char c);
	int pop(char *c);
	int empty(void);

};

#endif // ARRAYSTACK_H
