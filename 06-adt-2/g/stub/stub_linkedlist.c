#include <stdio.h>

struct node
{
	char c;
	struct node *next;
};

struct linkedlist
{
	struct node *head;
};

struct node *node_create(char c);
struct linkedlist * linkedlist_create(void);
void linkedlist_free(struct linkedlist *l);
struct node * linkedlist_get_node(struct linkedlist *l, int pos);
void linkedlist_insert_before(struct linkedlist *l, 
		struct node *before, struct node *n);
void linkedlist_del(struct linkedlist *l, struct node *n);

int main()
{
	struct linkedlist *l;
	struct node *n, *before;

	printf("testing list create...");
	if ((l = linkedlist_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing node create...");
	if ((n = node_create('a')) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing insert of 1st node...");
	linkedlist_insert_before(l, NULL, n);
	if (l->head != n)
		goto fail;
	printf("[ok]\n");

	printf("testing insert at head...");
	n = node_create('c');
	linkedlist_insert_before(l, l->head, n);
	if (l->head != n)
		goto fail;
	printf("[ok]\n");

	printf("testing get node...");
	before = linkedlist_get_node(l, 1);
	if (before->c != 'a')
		goto fail;
	printf("[ok]\n");

	printf("testing insert in middle...");
	n = node_create('b');
	linkedlist_insert_before(l, before, n);
	n = linkedlist_get_node(l, 1);
	if (n->c != 'b')
		goto fail;
	printf("[ok]\n");

	printf("testing count...");
	if (linkedlist_count(l) != 3)
		goto fail;
	printf("[ok]\n");

	printf("testing del...");
	linkedlist_del(l, n);
	printf("[ok]\n");

	printf("testing free...");
	linkedlist_free(l);
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
