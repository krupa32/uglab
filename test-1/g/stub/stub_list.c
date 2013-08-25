#include<stdlib.h>
#include <stdio.h>

struct node
{
	char c;
	struct node *next;
};

struct list
{
	struct node *head;
};


void list_add_tail(struct list *l, struct node *n);

struct node * list_get(struct list *l, int pos);

void list_del(struct list *l, struct node *n);


int main()
{
	struct list l;
	struct node n1 = { 'a', NULL} , n2 = { 'b', NULL }, n3 = { 'c', NULL };

	l.head = NULL;

	printf("testing list-add_tail...");
	list_add_tail(&l, &n1);
	if (list_get(&l, 0) != &n1)
		goto fail;
	list_add_tail(&l, &n2);
	if (list_get(&l, 1) != &n2)
		goto fail;
	list_add_tail(&l, &n3);
	if (list_get(&l, 2) != &n3)
		goto fail;
	printf("[ok]\n");
		
	printf("testing list_del...");
	list_del(&l, &n1);
	if(list_get(&l, 0) != &n2)
		goto fail;
	list_del(&l, &n3);
	if(list_get(&l, 0) != &n2)
		goto fail;
	list_del(&l, &n2);
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
