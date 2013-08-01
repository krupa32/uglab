#include<stdio.h>

void * list_create(void);
void list_free(void *list);
int list_insert(void *list, int pos, char c);
void list_remove(void *list, int pos);
char list_get(void *list, int pos);
void list_set(void *list, int pos, char c);
int list_count(void *list);

int main()
{
	int x = 0; char a;
	struct arraylist *list;

	printf("\nCreating arraylist...");
	list = list_create();
	if(list == NULL)
	{
		printf("\n list not created...\n");
		goto out;
	}
	else
		printf("[ok]\n");
	
	printf("testing list_insert...\n\t(1)valid position...");
	x = list_insert(list, 0, 'a');
	if(x == 1)
		printf("[ok]\n");
	else
		goto fail;
	if(! list_insert(list, 1, 'b'))
		goto fail;
	if(! list_insert(list, 2, 'c'))
		goto fail;
	printf("\t(2)invalid postion...");
	x = list_insert(list, 7,'d');
	if( x == 1)
		goto fail;
	else
		printf("[ok]\n");

	printf("testing list_get...");
	a = list_get(list, 1);
	if( a != 'b')
		goto fail;
	a = list_get(list, 7);
	if(a != 0)
		goto fail;
	else
		printf("[ok]\n");

	printf("testing list_remove...");
	list_remove(list, 1);
	a = list_get(list, 1);
	if( a != 'c')
		goto fail;
	else
		printf("[ok]\n");
	
	printf("teseting list_set...");
	list_set(list, 0, 'e');
	if(list_get(list, 0) == 'e')
		printf("[ok]\n");
	else
		goto fail;
	x =list_count(list);
	if(x == 2)
		printf("[ok]\n");
	else
		goto fail;
	return 0;
fail:
	printf("[failed]\n");
out:
	return -1;
}


