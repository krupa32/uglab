#include <stdio.h>
#include "list.h"

#define MAX_ELEMENTS    100


int main()
{
	List *l = List::create();
	char c;

	printf("testing insert/remove...");
	if (!l->insert(-1, 'a'))
		goto fail;
	if (!l->insert(-1, 'b'))
		goto fail;
	if (!l->insert(1, 'c'))
		goto fail;
	if (!l->remove(0, &c) || c != 'a')
		goto fail;
	if (!l->remove(1, &c) || c != 'b')
		goto fail;
	if (!l->remove(0, &c) || c != 'c')
		goto fail;
	printf("[ok]\n");

	printf("testing count...");
	if (l->get_count() != 0)
		goto fail;
	l->insert(-1, 'a');
	if (l->get_count() != 1)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
