#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t;

	printf("testing add...");
	t.add(4);
	t.add(2);
	t.add(6);
	t.add(1);
	t.add(3);
	t.add(5);
	t.add(7);
	printf("[ok]\n");

	printf("testing get_height...");
	if (t.get_height() != 2)
		goto fail;
	t.remove(1);
	if (t.get_height() != 2)
		goto fail;
	t.remove(3);
	if (t.get_height() != 2)
		goto fail;
	t.remove(5);
	if (t.get_height() != 2)
		goto fail;
	t.remove(7);
	if (t.get_height() != 1)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
