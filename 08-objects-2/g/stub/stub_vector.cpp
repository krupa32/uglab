#include <stdio.h>
#include "vector.h"

int main()
{
	Vector *v = Vector::create();
	char c;

	printf("testing insert/remove...");
	if (!v->insert(-1, 'a'))
		goto fail;
	if (!v->insert(0, 'b'))
		goto fail;
	if (!v->insert(-1, 'c'))
		goto fail;

	/* vector now has b, a, c */

	if (!v->remove(0, &c) || c != 'b')
		goto fail;
	if (!v->remove(1, &c) || c != 'c')
		goto fail;
	if (!v->remove(0, &c) || c != 'a')
		goto fail;
	printf("[ok]\n");

	printf("testing empty...");
	if (!v->empty())
		goto fail;
	v->insert(-1, 'a');
	if (v->empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;

}
