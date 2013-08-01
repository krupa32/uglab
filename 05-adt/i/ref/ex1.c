#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};

struct node *find ( struct node *head, int num)
{
	struct node *temp;
	temp = head->next;
	while(temp != NULL)
	{
		if( temp->num == num )
			return temp;
		temp = temp->next;
	}
	return NULL;
}
