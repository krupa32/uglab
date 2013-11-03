#include <stdio.h>
#include "list.h"

int check_tail(struct Node *head, int val)
{
	struct Node *p = head;

	while (p && p->next)
		p = p->next;

	return (p && (p->val == val));
}

int main()
{
	List l;
	struct Node *h;
	int arr[10] = { 23, 95, 48, 61, 39, 49, 55, 68, 42, 40 };
	int nops, i;

	printf("testing add_tail...");
	for (i = 0; i < 10; i++) {
		l.add_tail(arr[i]);
		if (!check_tail(l.get_head(), arr[i])) {
			printf("[failed]\n");
			goto test_search;
		}
	}
	printf("[ok]\n");

test_search:
	printf("testing search...");
	for (i = 9; i >= 0; i--) {
		if (!l.search(arr[i], &nops) || nops != (i+1)) {
			printf("[failed]\n");
			goto test_remove;
		}
	}
	printf("[ok]\n");

test_remove:
	printf("testing remove...");
	for (i = 9; i >= 0; i--) {
		l.remove(arr[i]);
		if (l.search(arr[i], &nops))
			goto fail;
	}
	l.remove(0);
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
