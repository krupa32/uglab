#include"list.h"
#include"queue.h"
void * queue_create(void)
{
	struct list* l = list_create();
	return l;	
}

void queue_free(void *queue)
{
	struct list *l = (struct list*) queue;
	list_free(l);
}

int queue_insert(void *queue, char c)
{
	struct list *l = (struct list*)queue;
	struct node *new_node = (struct node*)malloc(sizeof(*new_node));	
	if(new_node)
	{
		new_node->c = c;
		new_node->next = NULL;
		list_add_tail(l,new_node);
		return 1;
	}
	return 0;
}

int queue_remove(void *queue, char *c)
{
	struct list *l = (struct list*)queue;
	//printf("queue-remove..\n");
	*c = l->head->c;
	list_del(l,l->head);	
}
	
int queue_empty(void *queue)
{
	struct list *l = (struct list *)queue;
	if(l->head)
		return 0;
	else
		return 1;

}
