#include "queue.h"

char arr[MAX_ELEMENTS];
int tail = 0;

int queue_insert(char c)
{
	arr[tail] = c;
	tail++;
}

int queue_remove(char *c)
{
	int i;

	if (tail == MAX_ELEMENTS)
		return 0;

	*c = arr[0];

	for (i = 0; i < tail - 1; i++)
		arr[i] = arr[i+1];

	tail--;

	return 1;
}

int queue_empty(void)
{
	return (tail == 0);
}


