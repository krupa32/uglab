#ifndef STACK_H
#define STACK_H

class stack
{
protected:
	int max_siz;
	int top;
	int *data;

public:
	stack(int max);
	~stack();
	int push(int n);
	int pop(void);
};

#endif // STACK_H
