#include <stdio.h>
#include "list.h"

int main()
{
	List l;
	struct Node n1 = { 1, NULL }, n2 = { 2, NULL }, n3 = { 3, NULL }, *p;

	printf("testing constructor...");
	if (l.get_tail() != NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing add_tail...");
	l.add_tail(&n1);
	if (l.get_tail() != &n1)
		goto fail;
	l.add_tail(&n2);
	if (l.get_tail() != &n2)
		goto fail;
	l.add_tail(&n3);
	if (l.get_tail() != &n3)
		goto fail;
	printf("[ok]\n");

	printf("testing remove_head...");
	if ((p = l.remove_head()) != &n1)
		goto fail;
	if ((p = l.remove_head()) != &n2)
		goto fail;
	if ((p = l.remove_head()) != &n3)
		goto fail;
	printf("[ok]\n");

	printf("testing find...");
	l.add_tail(&n1);
	l.add_tail(&n2);
	l.add_tail(&n3);
	if (l.find(1) != &n1 || l.find(2) != &n2 || l.find(3) != &n3 || l.find(4) != NULL)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;

}
