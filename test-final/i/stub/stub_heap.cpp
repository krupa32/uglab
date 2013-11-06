#include <stdio.h>
#include <string.h>
#include "heap.h"

void tree_to_arr(struct Node *root, int *arr)
{
	struct Node *p = root;
	struct Node *queue[50];
	int head = 0, tail = 0, count = 0;

	if (root)
		queue[tail++] = root;

	while (head != tail) {
		p = queue[head++];
		arr[count++] = p->val;

		if (p->left)
			queue[tail++] = p->left;
		if (p->right)
			queue[tail++] = p->right;
	}
}

int check_heap(struct Node *root, int count)
{
	int arr[15], i;
	int expected[15][15] = {
		{ 14 },
		{ 2, 14 },
		{ 2, 14, 6 },
		{ 2, 4, 6, 14 },
		{ 2, 4, 6, 14, 12 },
		{ 2, 4, 5, 14, 12, 6 },
		{ 2, 4, 5, 14, 12, 6, 11 },
		{ 2, 4, 5, 8, 12, 6, 11, 14 },
		{ 2, 4, 5, 8, 12, 6, 11, 14, 9 },
		{ 2, 4, 5, 8, 10, 6, 11, 14, 9, 12 },
		{ 2, 4,5, 8, 10, 6, 11, 14, 9, 12, 13 },
		{ 2, 4, 3, 8, 10, 5, 11, 14, 9, 12, 13, 6 },
		{ 2, 4, 3, 8, 10, 5, 11, 14, 9, 12, 13, 6, 7 },
	    	{ 2, 4, 3, 8, 10, 5, 11, 14, 9, 12, 13, 6, 7, 15 },
		{ 1, 4, 2, 8, 10, 5, 3, 14, 9, 12, 13, 6, 7, 15, 11 }
	};

	memset(arr, 0, 15*sizeof(int));
	tree_to_arr(root, arr);

	for (i = 0; i < count; i++) {
		if (arr[i] != expected[count-1][i])
			return 0;
	}

	return 1;
}

int main()
{
	int i;
	Heap h;
	struct Node nodes[15] = {
		{ 14, NULL, NULL, NULL },
		{ 2, NULL, NULL, NULL },
		{ 6, NULL, NULL, NULL },
		{ 4, NULL, NULL, NULL },
		{ 12, NULL, NULL, NULL },
		{ 5, NULL, NULL, NULL },
		{ 11, NULL, NULL, NULL },
		{ 8, NULL, NULL, NULL },
		{ 9, NULL, NULL, NULL },
		{ 10, NULL, NULL, NULL },
		{ 13, NULL, NULL, NULL },
		{ 3, NULL, NULL, NULL },
		{ 7, NULL, NULL, NULL },
		{ 15, NULL, NULL, NULL },
		{ 1, NULL, NULL, NULL },
	};

	printf("testing insert...\n");
	for (i = 0; i < 15; i++) {
		h.insert(&nodes[i]);
		if (!check_heap(h.get_root(), i+1))
			goto fail;
	}

	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
