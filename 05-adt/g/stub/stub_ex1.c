#include <stdio.h>

struct node
{
	int num;
	struct node *next;
};

struct node *get_last(struct node *head);

int main()
{
	struct node n3 = { 3, NULL };
	struct node n2 = { 2, &n3 };
	struct node n1 = { 1, &n2 };

	printf("test case 1...");
	if (get_last(&n1) != &n3)
		goto fail;
	printf("[ok]\n");

	printf("test case 2 (only one node in list)...");
	if (get_last(&n3) != &n3)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
