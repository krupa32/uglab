#include"list.h"
#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
void * list_create(void)
{
	struct linkedlist *list = NULL;
	list = (struct linkedlist *)  malloc(sizeof(*list));
	if(list)
	{
 		list->head = NULL;
	 	//list->arr[0] 
		return list;
	}
	else
		return NULL;
}

void list_free(void *l)
{
	struct linkedlist *list = l;
	struct node *tmp = list->head, *tmp1 = tmp;
	while(tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	free(list);
}

int list_insert(void *l, int pos, char c)
{
	int n = 0;
	struct linkedlist *list = l;
	struct node *tmp, *new_node, *prev;

	tmp = list->head;
	prev = NULL;
        
        new_node = malloc(sizeof(*new_node));
	new_node->c = c;
	new_node->next = NULL;

	if(list->head == NULL || pos == 0)
	{
		new_node->next = list->head;
		list->head = new_node;
		return 1;
	}
	while( n != pos && tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		n++;
	}
	if( tmp == NULL && n != pos)
		return 0;

	new_node->next = tmp;
	prev->next = new_node;

	return 1;
}

void list_remove(void *l, int pos)
{
	int n = 0;
	struct linkedlist *list = l;
	struct node *tmp = list->head,*prev;
	prev = tmp;
	while( n < pos && tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		n++;
	}
	if(tmp == NULL) 
		return;
	prev->next = tmp->next;
}
char list_get(void *l, int pos)
{
	int n = 0;
	struct linkedlist *list = l;
        struct node *tmp;
	tmp = list->head;
        while( n != pos && tmp)
        {
                tmp = tmp->next;
                n++;
        }
	if(tmp == NULL)
		return 0;
	return (tmp->c);	
}
void list_set(void *l, int pos, char c)
{
	int n = 0;
	struct linkedlist *list = l;
        struct node *tmp;
        tmp = list->head;
        while( n != pos && tmp)
        {
                tmp = tmp->next;
                n++;
        }
	if(tmp == NULL)
		return;
	tmp->c = c;	
}	
int list_count(void *l)
{
       int cnt=0;
	struct linkedlist *list = l;
       struct node *p = list->head;
       while(p!=NULL)
       {
               cnt++;
               p=p->next;
       }
       return cnt;
}
