#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

/* Caller should allocate a dummy node struct record head;
 * and store the return value of this function in head.next
 */
void rec_cache_init(struct list *cache, int num_records)
{
	int i;
	struct record *rec;

	if ((rec = malloc(num_records * sizeof(*rec))) == NULL)
		return NULL;

	for (i = 0; i < num_records; i++)
		rec[i].next = &rec[i+1];

	rec[num_records - 1].next = NULL;

	cache->head = &rec[0];
}

struct record *rec_alloc_from_cache(struct list *cache,
			int roll_num, const char *name, int mark)
{
	struct record *p;

	/* no nodes in cache? */
	if (cache->head == NULL)
		return NULL;

	p = cache->head;

	/* remove first node from cache */
	cache->head = cache->head->next;

	p->roll_num = roll_num;
	strcpy(p->name, name);
	p->mark = mark;
	p->next = NULL;

	return p;
}

void rec_free_to_cache(struct list *cache, struct record *rec)
{
	rec->next = cache->head;
	cache->head = rec;
}
