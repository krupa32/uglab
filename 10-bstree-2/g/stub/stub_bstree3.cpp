#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t;
	int arr[10], count, ref[10] = { 1, 3, 2, 5, 7, 6, 4 };
	int i;

	printf("testing add/search...");
	t.add(4);
	t.add(2);
	t.add(6);
	t.add(1);
	t.add(3);
	t.add(5);
	t.add(7);
	if (!t.search(1) || !t.search(2) || !t.search(3) ||
	    !t.search(4) || !t.search(5) || !t.search(6) || !t.search(7))
		goto fail;
	if (t.search(8) || t.search(9))
		goto fail;
	printf("[ok]\n");

	printf("testing remove...");
	t.remove(3);
	if (t.search(3) || !t.search(1))
		goto fail;
	t.remove(5);
	if (t.search(5) || !t.search(1))
		goto fail;
	t.remove(2);
	if (t.search(2) || !t.search(1))
		goto fail;
	t.remove(6);
	if (t.search(6) || !t.search(1))
		goto fail;
	t.remove(4);
	if (t.search(4) || !t.search(1))
		goto fail;
	t.remove(1);
	if (t.search(1))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
