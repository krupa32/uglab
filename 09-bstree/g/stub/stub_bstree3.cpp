#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree t;
	int arr[10], count, ref[10] = { 1, 3, 2, 5, 6, 4 };
	int i;

	printf("testing add...");
	t.add(4);
	t.add(2);
	t.add(6);
	t.add(1);
	t.add(3);
	t.add(5);
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

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
