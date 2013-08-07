#include <stdio.h>

struct node
{
	int num;
	struct node *next;
};

struct node *get_prev(struct node *head, struct node *n);

int main()
{
	struct node n5 = { 5, NULL };
	struct node n4 = { 4, &n5 };
	struct node n3 = { 3, &n4 };	
	struct node n2 = { 2, &n3 };
	struct node n1 = { 1, &n2 };

	printf("n is in the middle of the list : ");
	if (get_prev(&n1, &n3) != &n2)
		goto fail;
	printf("[ok]\n");

	printf("n is in the end of the list : ");
	if (get_prev(&n1, &n5) != &n4)
		goto fail;
	printf("[ok]\n");


	printf("only one node in list...");
	if (get_prev(&n5, &n5) != NULL)
		goto fail;
	printf("[ok]\n");

	printf("n is not in the list : ");
	if (get_prev(&n2, &n1) != NULL)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
