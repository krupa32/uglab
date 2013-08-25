
#include "queue.h"
#include "dbllist.h"

class DoubleQueue : public Queue
{
	DblList list;

public:

	DoubleQueue();

	int insert(char c);
	int remove(char *c);
	int empty(void);
};
