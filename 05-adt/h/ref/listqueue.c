#include"queue.h"
#include"listqueue.h"

void * queue_create(void)
{
	struct listqueue *queue = NULL;
	queue = (struct listqueue*) malloc(sizeof(*queue));
	if ( queue )
	{
		queue->head = NULL;
		return queue;
	}
	return NULL;
}

void queue_free(void *queue)
{
	struct listqueue *lq = queue;
	struct node *tmp = lq->head, *tmp1 = tmp;
	while(tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	free(lq); 
}

int queue_insert(void *queue, char c)
{
	struct listqueue *lq = queue;
	struct node *new_node, *prev,*cur = lq->head;
	new_node = (struct node*) malloc(sizeof(*new_node));
	new_node->c = c;
	new_node->next = NULL;
	if(lq->head == NULL)
	{
		lq->head = new_node;
		return 1;
	}
	while(cur)
	{	
		prev = cur;
		cur = cur->next;
	}
	prev->next = new_node;
	return 1;
}

int queue_remove(void *queue, char *c)
{
	struct listqueue *lq = queue;
	if(lq->head == NULL)
		return 0;
	*c = lq->head->c;
	lq->head = lq->head->next;
	return 1;
}

int queue_empty(void *queue)
{
	struct listqueue *lq = queue;
	if(lq->head == NULL)
		return 1;
	else
		return 0;
}
