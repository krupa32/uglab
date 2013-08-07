#include<stdio.h>
struct node
{
	char c;
	struct node *next;
};

struct list
{
	struct node *head;
};

struct list * list_create(void);
void list_free(struct list *l);
void list_add_head(struct list *l, struct node *n);
void list_add_tail(struct list *l, struct node *n);
void list_del(struct list *l, struct node *n);
