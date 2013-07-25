#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

struct record *rec_alloc(int roll_num, const char *name, int mark)
{
	struct record *p;

	if ((p = malloc(sizeof(*p))) == NULL)
		return NULL;

	p->roll_num = roll_num;
	strcpy(p->name, name);
	p->mark = mark;
	p->next = NULL;

	return p;
}

void rec_free(struct record *p)
{
	free(p);
}

void rec_add(struct list *l, struct record *rec)
{
	struct record *p = l->head;

	if (l->head == NULL) {
		l->head = rec;
		return;
	}

	/* goto last node */
	while (p->next)
		p = p->next;

	p->next = rec;

	return;
}

struct record *rec_find(struct list *l, int roll_num)
{
	struct record *p = l->head;

	while (p) {
		if (p->roll_num == roll_num)
			break;

		p = p->next;
	}

	return p;
}

void rec_remove(struct list *l, struct record *rec)
{
	struct record *p = l->head;

	if (l->head == rec) {
		l->head = rec->next;
		goto out;
	}

	while (p && p->next != rec)
		p = p->next;

	if (!p)
		return;

	/* unlink rec from the list */
	p->next = rec->next;

out:
	rec->next = NULL;
}
