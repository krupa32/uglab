/*
 * Abstract Stack class
 */

#ifndef STACK_H
#define STACK_H

class Stack
{
public:
	virtual int push(char c) = 0;
	virtual int pop(char *c) = 0;
	virtual int empty(void) = 0;

	static Stack * create(void);
};

#endif // STACK_H
