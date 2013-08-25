
#include "stack.h"
#include "dbllist.h"

class DoubleStack : public Stack
{
	DblList list;

public:

	DoubleStack();

	int push(char c);
	int pop(char *c);
	int empty(void);
};
