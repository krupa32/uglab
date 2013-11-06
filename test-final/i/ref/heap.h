struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

class Heap
{
	struct Node *root;

public:
	Heap();
	struct Node *get_root(void);
	void insert(struct Node *n);
};


