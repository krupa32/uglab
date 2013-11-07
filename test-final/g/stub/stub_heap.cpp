#include <stdio.h>
#include <string.h>
#include "heap.h"

int check_list(struct Node *head, int count)
{
	struct Node *p = head;
	int i;
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

	for (i = 0; i < count; i++) {
		if (p->val != expected[count-1][i])
			return 0;
		p = p->next;
	}

	return 1;
}

int main()
{
	int i;
	Heap h;
	struct Node nodes[15] = {
		{ 14, NULL },
		{ 2, NULL },
		{ 6, NULL },
		{ 4, NULL },
		{ 12, NULL },
		{ 5, NULL },
		{ 11, NULL },
		{ 8, NULL },
		{ 9, NULL },
		{ 10, NULL },
		{ 13, NULL },
		{ 3, NULL },
		{ 7, NULL },
		{ 15, NULL },
		{ 1, NULL },
	};

	printf("testing insert...\n");
	for (i = 0; i < 15; i++) {
		h.insert(&nodes[i]);
		if (!check_list(h.get_head(), i+1))
			goto fail;
	}

	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
