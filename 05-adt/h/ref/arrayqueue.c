#include "queue.h"
#include "arrayqueue.h"
#include<stdlib.h>
void * queue_create(void)
{
	struct arrayqueue *aq;

	aq = (struct arrayqueue *)malloc(sizeof(*aq));

	if (aq)
		aq->tail = 0;

	return aq;
}

void queue_free(void *queue)
{
	free(queue);
}

int queue_insert(void *queue, char c)
{
	struct arrayqueue *aq = (struct arrayqueue *)queue;

	if (aq->tail == QUEUE_MAX_SIZE)
		return 0;

	aq->arr[aq->tail] = c;
	aq->tail++;

	return 1;
}

int queue_remove(void *queue, char *c)
{
	struct arrayqueue *aq = (struct arrayqueue *)queue;
	int i=0;
	if (aq->tail == 0)
		return 0;

	*c = aq->arr[0];
	for(i = 0; i < aq->tail; i++)
		aq->arr[i] = aq->arr[i+1];
	aq->tail-=1;
	return 1;
}

int queue_empty(void *queue)
{
	struct arrayqueue *aq = (struct arrayqueue *)queue;

	return (aq->tail == 0);
}


