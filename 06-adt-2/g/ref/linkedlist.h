struct node
{
	char c;
	struct node *next;
};

struct linkedlist
{
	struct node *head;
};

struct node *node_create(char c);
struct linkedlist * linkedlist_create(void);
void linkedlist_free(struct linkedlist *l);
struct node * linkedlist_get_node(struct linkedlist *l, int pos);
void linkedlist_insert_before(struct linkedlist *l, 
		struct node *before, struct node *n);
void linkedlist_del(struct linkedlist *l, struct node *n);
