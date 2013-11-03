#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List::List()
{
	head = NULL;
}

struct Node * List::get_head(void)
{
	return head;
}

void List::add_tail(int val)
{
	struct Node *n, *p = head, *prev = NULL;

	n = (struct Node *)malloc(sizeof(*n));
	n->val = val;
	n->next = NULL;

	while (p) {
		prev = p;
		p = p->next;
	}

	if (!prev)
		head = n;
	else
		prev->next = n;
	
}

void List::remove(int val)
{
	struct Node *p = head, *prev = NULL;

	while (p && p->val != val) {
		prev = p;
		p = p->next;
	}

	if (p) {
		if (p == head)
			head = head->next;
		else
			prev->next = p->next;

		free(p);
	}
}

int List::search(int val, int *nops)
{
	struct Node *p = head, *prev = NULL;

	*nops = 0;

	while (p) {
		(*nops)++;
		if (p->val == val)
			break;

		p = p->next;
	}

	return (p != NULL);
}

