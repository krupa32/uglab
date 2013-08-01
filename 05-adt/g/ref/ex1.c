
struct node
{
	int num;
	struct node *next;
};

struct node *get_last(struct node *head)
{
	struct node *p = head;

	while (p && p->next)
		p = p->next;

	return p;
}
