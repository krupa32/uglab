#include <stdio.h>
#include "list.h"

List::List()
{
	head = NULL;
}

struct Node *List::get_head(void)
{
	return head;
}

void List::add_head(struct Node *n)
{
	if (head == NULL) {
		head = n;
		return;
	}

	n->next = head;
	head = n;
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
