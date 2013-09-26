#include "list.h"

class Stack
{
	List list;

public:
	Stack();
	void push(int val);
	int pop(void);
	int empty(void);
	Stack *duplicate(void);
	Stack *reverse(void);
};


