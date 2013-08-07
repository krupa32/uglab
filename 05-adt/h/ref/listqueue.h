#include<stdlib.h>

struct node
{
	char c;
	struct node *next;
};

struct listqueue
{
	struct node *head;
};

