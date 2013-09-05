#include <stdio.h>
#include "dbllist.h"

int main()
{
	DblList l;
	Node *n1, *n2, *n3;
	char c;

	printf("testing create node...");
	c = 'a';
	if ((n1 = Node::create(&c)) == NULL)
		goto fail;
	c = 'b';
	if ((n2 = Node::create(&c)) == NULL)
		goto fail;
	c = 'c';
	if ((n3 = Node::create(&c)) == NULL)
		goto fail;
	printf("[ok]\n");
	
	printf("testing add_head...");
	l.add_head(n1);
	if (l.get_node(0) != n1)
		goto fail;
	l.add_head(n2);
	if (l.get_node(0) != n2)
		goto fail;
	printf("[ok]\n");
	
	printf("testing add_tail...");
	l.add_tail(n3);
	if (l.get_node(2) != n3)
		goto fail;
	printf("[ok]\n");
	
	printf("testing remove at head...");
	l.remove(l.get_node(0));
	printf("[ok]\n");
	
	printf("testing remove at tail...");
	l.remove(l.get_node(1));
	printf("[ok]\n");

	
	printf("testing empty...");
	if (l.empty())
		goto fail;
	l.remove(l.get_node(0));
	if (!l.empty())
		goto fail;
	printf("[ok]\n");
	
	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
