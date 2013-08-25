#include <stdio.h>
#include "list.h"

void list_add_tail(struct list *l, struct node *n)
{
	struct node *p = l->head, *prev = NULL;

	while (p) {
		prev = p;
		p = p->next;
	}

	if (prev == NULL) {
		l->head = n;
		return;
	} else {
		prev->next = n;
	}
	
}

struct node * list_get(struct list *l, int pos)
{
	int i = 0;
	struct node *p = l->head;

	while (p) {
		if (i == pos)
			break;
		i++;
		p = p->next;
	}

	return p;
}

void list_del(struct list *l, struct node *n)
{
	struct node *p = l->head, *prev = NULL;

	while (p && p != n) {
		prev = p;
		p = p->next;
	}

	if (prev == NULL) {
		l->head = n->next;
		return;
	} else {
		prev->next = n->next;
	}
	
}


