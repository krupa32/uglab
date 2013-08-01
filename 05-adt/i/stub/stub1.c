#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};

extern struct node *find(struct node *head, int num);

int main()
{
	struct node  head,node1,node2,node3,*temp;
	head.next = &node1;
	head.num = 0;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	node1.num = 15;
	node2.num = 25;
	node3.num = 35;
	
	temp = find(&head, 15);
	if( temp == NULL )  
		goto fail;
	else printf("[ok]\n");
	temp = find(&head, 5);
	if(temp != NULL)
		goto fail;
	else
		printf("[ok]\n");
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
