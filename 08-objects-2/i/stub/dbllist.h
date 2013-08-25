#include "node.h"

class DblList
{
	Node *head;

public:

	DblList();

	void add_head(Node *n);

	void add_tail(Node *n);
	
	Node *get_node(int pos);

	void remove(Node *n);

	int empty(void);
};
