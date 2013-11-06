#include <stdio.h>
#include "bstree.h"

int main()
{
	int arr[15] = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	int expected[15] = { 1, 3, 2, 5, 7, 6, 4, 9, 11, 10, 13, 15, 14, 12, 8 };
	int post[15], count, nops, i;
	BSTree t;

	printf("testing insert...\n");
	for (i = 0; i < 15; i++)
		t.insert(arr[i]);
	printf("[ok]\n");

	printf("testing postorder...\n");
	t.postorder(post, &count);
	if (count != 15) {
		printf("[failed]\n");
		goto test_search;
	}
	for (i = 0; i < 15; i++) {
		if (post[i] != expected[i]) {
			printf("[failed]\n");
			goto test_search;
		}
	}
	printf("[ok]\n");

test_search:
	printf("testing search...\n");
	if (!t.search(8, &nops) || nops != 1)
		goto fail;
	if (!t.search(2, &nops) || nops != 3)
		goto fail;
	if (!t.search(5, &nops) || nops != 4)
		goto fail;
	if (!t.search(12, &nops) || nops != 2)
		goto fail;
	if (!t.search(10, &nops) || nops != 3)
		goto fail;
	if (!t.search(13, &nops) || nops != 4)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
