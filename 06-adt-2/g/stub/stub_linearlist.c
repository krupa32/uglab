#include <stdio.h>

void * linearlist_create(void);
void linearlist_free(void *linearlist);
int linearlist_insert(void *linearlist, int pos, char c);
int linearlist_remove(void *linearlist, int pos);
char linearlist_get(void *linearlist, int pos);
void linearlist_set(void *linearlist, int pos, char c);
int linearlist_count(void *linearlist);


int main()
{
	void *l;

	printf("testing list create...");
	if ((l = linearlist_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing insert of 1st char...");
	if (!linearlist_insert(l, 0, 'a'))
		goto fail;
	printf("[ok]\n");

	printf("testing insert...");
	if (!linearlist_insert(l, 0, 'c'))
		goto fail;
	printf("[ok]\n");

	printf("testing insert in middle...");
	if (!linearlist_insert(l, 1, 'b'))
		goto fail;
	printf("[ok]\n");

	printf("testing get...");
	if (linearlist_get(l, 0) != 'c')
		goto fail;
	if (linearlist_get(l, 1) != 'b')
		goto fail;
	if (linearlist_get(l, 2) != 'a')
		goto fail;
	printf("[ok]\n");

	printf("testing get...");
	linearlist_set(l, 0, 'x');
	if (linearlist_get(l, 0) != 'x')
		goto fail;
	printf("[ok]\n");

	printf("testing remove...");
	linearlist_remove(l, 0);
	if (linearlist_get(l, 0) != 'b')
		goto fail;
	printf("[ok]\n");

	printf("testing free...");
	linearlist_free(l);
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
