#include <stdio.h>
#include "list.h"

List::List()
{
	head = NULL;
}

struct Node *List::get_tail(void)
{
	struct Node *p = head;

	if (p == NULL)
		return NULL;

	while (p->next)
		p = p->next;

	return p;
}

void List::add_tail(struct Node *n)
{
	struct Node *p = head;

	if (head == NULL) {
		head = n;
		head->next = NULL;
		return;
	}

	while (p->next)
		p = p->next;

	n->next = NULL;
	p->next = n;
}

struct Node *List::remove_head(void)
{
	struct Node *p = head;

	if (head)
		head = head->next;

	return p;
}

struct Node *List::find(int val)
{
	struct Node *p = head;

	while (p) {
		if (p->val == val)
			break;
		p = p->next;
	}

	return p;
}
