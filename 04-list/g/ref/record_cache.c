#include <stdio.h>
#include "record.h"

extern void rec_remove(struct list *l, struct record *rec);

void rec_add_and_cache(struct list *l, struct record *rec)
{
	rec->next = l->head;
	l->head = rec;
}

struct record *rec_find_and_cache(struct list *l, int roll_num)
{
	struct record *p = l->head;

	while (p) {
		if (p->roll_num == roll_num)
			break;

		p = p->next;
	}

	if (!p)
		return NULL;

	rec_remove(l, p);

	rec_add_and_cache(l, p);

	return p;
}
