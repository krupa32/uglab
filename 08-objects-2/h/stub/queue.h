/*
 * Abstract Queue class
 */

#ifndef QUEUE_H 
#define QUEUE_H

class Queue
{
public:
	virtual int insert(char c) = 0;
	virtual int remove(char *c) = 0;
	virtual int empty(void) = 0;

	static Queue * create(void);
};

#endif // QUEUE_H
