#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "queue.h"

#define MAX_ELEMENTS    100

class ArrayQueue : public Queue
{
	char arr[MAX_ELEMENTS];
	int tail;

public:
	ArrayQueue();

	int insert(char c);
	int remove(char *c);
	int empty(void);

};

#endif // ARRAYQUEUE_H
