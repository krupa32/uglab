struct Node
{
	int val;
        struct Node *next;
};

class Heap
{
	int count;
	struct Node *head;

	struct Node *get_node_at_pos(int pos);

public:
	Heap();
	struct Node *get_head(void);
	void insert(struct Node *n);
};


