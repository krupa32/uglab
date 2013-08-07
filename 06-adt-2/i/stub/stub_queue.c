#include <stdio.h>

void *queue_create(void);
void queue_free(void *queue);
int queue_insert(void *queue, char c);
int queue_remove(void *queue, char *c);
int queue_empty(void *queue);

int main()
{
	void *lq; 
	int x = 0;
	char c;
	printf("\ntesting queue_create...");
	lq = queue_create();
	if(lq)
		printf("[ok]\n");
	else
		goto fail;
//	printf("test..\n");
	printf("testing queue_insert/remove...");
	if (!queue_insert(lq, 'a'))
		goto fail;
	if (!queue_insert(lq, 'b'))
		goto fail;
	if (!queue_insert(lq, 'c'))
		goto fail;
	if (!queue_remove(lq, &c) || c != 'a')
		goto fail;
	if (!queue_remove(lq, &c) || c != 'b')
		goto fail;
	if (!queue_remove(lq, &c) || c != 'c')
		goto fail;
	printf("[ok]\n");
	
	printf("testing queue_empty...");
	if (!queue_empty(lq))
		goto fail;
	if (!queue_insert(lq, 'a'))
		goto fail;
	if (queue_empty(lq))
		goto fail;
	printf("[ok]\n");

	printf("testing queue_free...");
	queue_free(lq);
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}	
