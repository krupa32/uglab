#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdrecord.h"

struct cdrecord *cdrec_alloc(int roll_num, const char *name, int mark)
{
	struct cdrecord *p;

	if ((p = malloc(sizeof(*p))) == NULL)
		return NULL;

	p->roll_num = roll_num;
	strcpy(p->name, name);
	p->mark = mark;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void cdlist_init(struct cdrecord *l)
{
	l->next = l;
	l->prev = l;
}

void cdrec_add_head(struct cdrecord *l, struct cdrecord *rec)
{
	rec->next = l->next;
	rec->prev = l;

	rec->next->prev = rec;
	rec->prev->next = rec;
}

void cdrec_add_tail(struct cdrecord *l, struct cdrecord *rec)
{
	rec->next = l;
	rec->prev = l->prev;

	rec->next->prev = rec;
	rec->prev->next = rec;
}

struct cdrecord *cdrec_find(struct cdrecord *l, int roll_num)
{
	struct cdrecord *p = l->next;

	while (p != l) {
		if (p->roll_num == roll_num)
			break;

		p = p->next;
	}
	if(p == l)
		return NULL;
	return p;
}

void cdrec_remove(struct cdrecord *l, struct cdrecord *rec)
{
	rec->prev->next = rec->next;
	rec->next->prev = rec->prev;
}
