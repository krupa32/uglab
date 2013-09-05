/*
 * Abstract Stack class
 */

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
	virtual int insert(int pos, char c) = 0;
	virtual int remove(int pos, char *c) = 0;
	virtual int empty(void) = 0;

	static Vector * create(void);
};

#endif // VECTOR_H
