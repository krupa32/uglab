#ifndef ADV_STACK_H
#define ADV_STACK_H

#include "stack.h"

class advanced_stack : public stack
{
public:
	advanced_stack(int max) : stack(max) { }
	~advanced_stack() { }

	int size(void);
	int equals(advanced_stack *s2);

	advanced_stack *clone(void);
	advanced_stack *create_palindrome(void);
};

#endif // ADV_STACK_H
