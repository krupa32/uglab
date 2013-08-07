#include<stdio.h>

struct node
{
	int num;
	struct node *next;
};

struct node *get_prev(struct node *head, struct node *n)
{
	struct node *p = head;

	while (p->next != NULL)
	{
		if ( p->next == n)
			return p;
		p = p->next;
	}
	return NULL;
}
