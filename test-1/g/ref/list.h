struct node
{
	char c;
	struct node *next;
};

struct list
{
	struct node *head;
};


void list_add_tail(struct list *l, struct node *n);

struct node * list_get(struct list *l, int pos);

void list_del(struct list *l, struct node *n);


