#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t;

	printf("testing add/search...");
	t.add(4);
	if (!t.search(4))
		goto fail;
	t.add(2);
	if (!t.search(2))
		goto fail;
	t.add(6);
	if (!t.search(6))
		goto fail;
	t.add(1);
	if (!t.search(1))
		goto fail;
	t.add(3);
	if (!t.search(3))
		goto fail;
	t.add(5);
	if (!t.search(5))
		goto fail;
	t.add(7);
	if (!t.search(7))
		goto fail;
	if (t.search(8) || t.search(9))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
