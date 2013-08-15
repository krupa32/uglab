#include<stdlib.h>
#include"linkedlist.h"

struct node * node_create(char c)
{
	struct node *n = malloc(sizeof(*n));

	if (n) {
		n->next = NULL;
		n->c = c;
	}

	return n;
}

struct linkedlist * linkedlist_create(void)
{
	struct linkedlist *l =(struct linkedlist *) malloc(sizeof(*l));

	if (l) {
		l->head = NULL;
		return l;
	}

	return l; 
}

void linkedlist_free(struct linkedlist *l)
{
	struct node *temp = l->head;

	while(l->head)
	{
		temp = l->head->next;
		l->head = l->head->next;
		free(temp);
	}

	free(l);
}

struct node * linkedlist_get_node(struct linkedlist *l, int pos)
{
	struct node *p = l->head;
	int i = 0;

	while (p && i != pos)
	{
		i++;
		p = p->next;
	}

	return p;
}

void linkedlist_insert_before(struct linkedlist *l, 
		struct node *before, struct node *n)
{
	struct node *p = l->head, *prev = NULL;

	while (p && p != before) {
		prev = p;
		p = p->next;
	}

	if (prev == NULL) { // inserting at head
		n->next = l->head;
		l->head = n;
		return;
	}

	n->next = p;
	prev->next = n;
}

void linkedlist_del(struct linkedlist *l, struct node *n)
{
	struct node *prev = NULL, *p = l->head;

	while (p && p != n)
	{
		prev = p;
		p = p->next;
	}

	if (prev == NULL) { // removing head
		l->head = l->head->next;
		free(n);
		return;
	}

	prev->next = p->next;
	free(p);
}

int linkedlist_count(struct linkedlist *l)
{
	struct node *p = l->head;
	int i;

	while (p) {
		i++;
		p = p->next;
	}

	return i;

}
