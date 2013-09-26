#include <stdio.h>
#include "queue.h"

int main()
{
	Queue q, *q1;

	printf("testing add/remove...");
	q.add(1);
	q.add(2);
	q.add(3);
	if (q.remove() != 1 || q.remove() != 2 || q.remove() != 3 || q.remove() != -1)
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	q.add(1);
	if (q.empty())
		goto fail;
	q.remove();
	if (!q.empty())
		goto fail;
	printf("[ok]\n");

	printf("testing duplicate...");
	q.add(1);
	q.add(2);
	q.add(3);
	q1 = q.duplicate();
	if (q.remove() != 1 || q.remove() != 2 || q.remove() != 3 || 
	    q.remove() != -1) {
		printf("[failed]\n");
		goto next;
	}
	if (!q1 || q1->remove() != 1 || q1->remove() != 2 || 
	    q1->remove() != 3 || q1->remove() != -1) {
		printf("[failed]\n");
		goto next;
	}
	printf("[ok]\n");

next:
	printf("testing remove_lowest...");
	q.add(3);
	q.add(1);
	q.add(2);
	if (q.remove_lowest() != 1 || q.remove_lowest() != 2 || 
	    q.remove_lowest() != 3 || q.remove_lowest() != -1)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
