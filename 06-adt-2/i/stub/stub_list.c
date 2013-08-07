#include<stdlib.h>
#include"list.h"

int main()
{
	struct list *l;
	struct node *n;
	struct node *n1;
	n = (struct node*)malloc(sizeof(*n1));
	n1 = (struct node*)malloc(sizeof(*n1));
	if(n)
	{
		n->c = 'e';
		n->next = NULL;
	}
	if(n1)
	{
		n1->c = 'i';
		n1->next = NULL;
	}
	printf("\ntesting list_create...");
	l = list_create();
	if(l)
		printf("[ok]\n");
	else
		goto fail;

	printf("testing list_add_head...");
	list_add_head(l,n);
	if(l->head == n)
	{
		list_add_head(l,n1);
		if(l->head == n1)
			printf("[ok]\n");
	}
	else
		goto fail;
		
	printf("testing list-add_tail...");
	n1 = (struct node*)malloc(sizeof(*n));
	n1->c = 'o';
	n1->next = NULL;
	
	list_add_tail(l,n1);
	if(l->head->next->next  == n1)
		printf("[ok]\n");
	else
		goto fail;
		
	printf("testing list_del...");
	list_del(l, n);
	if(l->head == n)
		goto fail;
	else
		printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
