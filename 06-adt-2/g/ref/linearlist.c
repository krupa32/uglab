#include <stdio.h>
#include "linkedlist.h"
#include "linearlist.h"


void * linearlist_create(void)
{
	return linkedlist_create();
}

void linearlist_free(void *linearlist)
{
	linkedlist_free(linearlist);
}

int linearlist_insert(void *linearlist, int pos, char c)
{
	struct node *before = linkedlist_get_node(linearlist, pos);
	struct node *n = node_create(c);

	if (n)
		linkedlist_insert_before(linearlist, before, n);

	return (n != NULL);
}

int linearlist_remove(void *linearlist, int pos)
{
	struct node *n = linkedlist_get_node(linearlist, pos);

	linkedlist_del(linearlist, n);
}

char linearlist_get(void *linearlist, int pos)
{
	struct node *n = linkedlist_get_node(linearlist, pos);

	return n->c;
}

void linearlist_set(void *linearlist, int pos, char c)
{
	struct node *n = linkedlist_get_node(linearlist, pos);

	n->c = c;
}

int linearlist_count(void *linearlist)
{
	return linkedlist_count(linearlist);
}


