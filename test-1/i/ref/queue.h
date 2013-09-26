#include "list.h"

class Queue
{
	List list;

public:
	Queue();
	void add(int val);
	int remove(void);
	int empty(void);
	Queue *duplicate(void);
	int remove_lowest(void);
};


