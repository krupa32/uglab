#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t;
	int arr[10], count, ref[10] = { 1, 3, 2, 5, 6, 4 };
	int i;

	printf("testing insert...");
	t.add(4);
	t.add(2);
	t.add(6);
	t.add(1);
	t.add(3);
	t.add(5);
	printf("[ok]\n");

	printf("testing search...");
	if (!t.search(1) || !t.search(2) || !t.search(3) ||
	    !t.search(4) || !t.search(5) || !t.search(6) )
		goto fail;
	if (t.search(8) || t.search(9))
		goto fail;
	printf("[ok]\n");

	printf("testing get_postorder...");
	t.get_postorder(arr, &count);
	if (count != 6)
		goto fail;
	for (i = 0; i < 6; i++) {
		if (arr[i] != ref[i])
			goto fail;
	}
	printf("[ok]\n");

	printf("testing count_leaf_nodes...");
	if (t.count_leaf_nodes() != 3)
		goto fail;
	printf("[ok]\n");


	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
