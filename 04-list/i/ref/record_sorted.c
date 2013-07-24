#include <stdio.h>
#include "record.h"

void rec_add_sorted(struct list *l, struct record *rec)
{
	struct record *p = l->head, *tmp;

	if (l->head == NULL) {
		l->head = rec;
		return;
	}

	while (p->next && rec->roll_num > p->next->roll_num)
		p = p->next;

	/* now rec should be inserted between p and p->next */
	tmp = p->next;
	p->next = rec;
	rec->next = tmp;
}

void rec_reverse(struct list *l)
{
	struct record *p = l->head, *tmp, *prev;

	prev = NULL;

	while (p) {
		/* backup the next ptr */
		tmp = p->next;

		/* reverse this node */
		p->next = prev;

		/* p will become previous node for next iteration */
		prev = p;

		/* move to next node from the backed up ptr */
		p = tmp;
	}

	l->head = prev;
}
