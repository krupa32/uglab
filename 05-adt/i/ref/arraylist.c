//#include"list.h"
#include"arraylist.h"
#include<stdio.h>
#include<stdlib.h>
void * list_create(void)
{
	struct arraylist *list = NULL;
	list =  malloc( sizeof(*list));
	if(list)
	{
 		list->count = 0;
	 	//list->arr[0] 
		return list;
	}
	else
		return NULL;
}

void list_free(void *list)
{
	free(list);
}

int list_insert(struct arraylist *list, int pos, char c)
{
	int n = list->count ;
	if(list->count == LIST_MAX_SIZE)
	{
		printf("List is full...cannot insert\n");
		return 0;
	}
	if(pos > n)
		return 0;
	while( n != pos)
	{
		list->arr[n+1] = list->arr[n];
		n--;
	}
	list->arr[pos] = c;
	list->count += 1;
	return 1;
}

void list_remove(struct arraylist *list, int pos)
{
	if(pos >= list->count)
		return;
	while( pos < list->count)
	{
		list->arr[pos] = list->arr[pos+1];
		pos++;
	}
	list->count--;
}
char list_get(struct arraylist *list, int pos)
{
	if(pos >= list->count )
		return 0;
	return (list->arr[pos]);	
}
void list_set(struct arraylist *list, int pos, char c)
{
	if(pos >= list->count)	
		return;
	list->arr[pos] = c;
}	
int list_count(struct arraylist *list)
{
	return list->count;
}
