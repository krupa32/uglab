#include<stdio.h>
#include"arrayqueue.h"
#include"queue.h"
int main()
{
	int x = 0; char *a ;
	struct arrayqueue *queue;
	printf("\ntesting queue_create...");
	queue = queue_create();
	if(queue == NULL)
	{
		printf("\n queue not created...\n");
		goto fail;
	}
	else
		printf("[ok]\n");
	
	printf("testing queue_insert...");
	x = queue_insert(queue, 'a');
	if(x == 1)
	{
		x = queue_insert(queue, 'b');
		x = queue_insert(queue, 'c');
		x = queue_insert(queue, 'd');
		printf("[ok]\n");
	}
	else
		goto fail;

	printf("testing queue_remove...");
	x = queue_remove(queue, a);
	if( *a != 'a')
		goto fail;
	else
		printf("[ok]\n");

	x = queue_remove(queue, a);
	x = queue_remove(queue, a);
	x = queue_remove(queue, a);	

	printf("testing queue_empty...");
	x = queue_empty(queue);
	if( x == 1)
		printf("[ok]\n");
	else
		goto fail;

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
