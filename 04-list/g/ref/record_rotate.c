#include <stdio.h>
#include "record.h"

#define LEFT	1
#define RIGHT	2

extern void rec_add(struct list *l, struct record *rec);
extern void rec_remove(struct list *l, struct record *rec);

void rec_rotate(struct list *l, int direction)
{
	struct record *p = l->head, *tmp;

	if (p == NULL)
		return;

	if (direction == LEFT) {

		/* remove the head */
		rec_remove(l, p);

		/* add it to tail */
		rec_add(l, p);

	} else {
		/* goto the tail */
		while (p->next)
			p = p->next;

		/* remove the tail */
		rec_remove(l, p);

		/* add it to head */
		p->next = l->head;
		l->head = p;
	}

}


