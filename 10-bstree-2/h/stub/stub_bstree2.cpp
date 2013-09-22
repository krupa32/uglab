#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t, t2;
	int arr[10], count, ref[10] = { 1, 2, 3, 4, 5, 6 };
	int i;

	printf("testing add/search...");
	t.add(4);
	if (!t.search(4))
		goto fail;
	t.add(2);
	if (!t.search(4))
		goto fail;
	t.add(6);
	if (!t.search(4))
		goto fail;
	t.add(1);
	if (!t.search(4))
		goto fail;
	t.add(3);
	if (!t.search(4))
		goto fail;
	t.add(5);
	if (!t.search(4))
		goto fail;
	printf("[ok]\n");

	printf("testing get_inorder...");
	t.get_inorder(arr, &count);
	if (count != 6)
		goto fail;
	for (i = 0; i < 6; i++) {
		if (arr[i] != ref[i])
			goto fail;
	}
	printf("[ok]\n");

	printf("testing get_height...");
	t2.add(4);
	t2.add(2);
	t2.add(3);
	t2.add(6);
	if (t2.get_height() != 2)
		goto fail;
	printf("[ok]\n");


	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
