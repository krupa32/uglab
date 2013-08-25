#include <stdio.h>

int queue_insert(char c);
int queue_remove(char *c);
int queue_empty(void);

int main()
{
	int x = 0;
	char c;

	printf("testing queue_insert/remove...");
	if (!queue_insert('a'))
		goto fail;
	if (!queue_insert('b'))
		goto fail;
	if (!queue_insert('c'))
		goto fail;
	if (!queue_remove(&c) || c != 'a')
		goto fail;
	if (!queue_remove(&c) || c != 'b')
		goto fail;
	if (!queue_remove(&c) || c != 'c')
		goto fail;
	printf("[ok]\n");
	
	printf("testing queue_empty...");
	if (!queue_empty())
		goto fail;
	if (!queue_insert('a'))
		goto fail;
	if (queue_empty())
		goto fail;
	printf("[ok]\n");

	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}	
