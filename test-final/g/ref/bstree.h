struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
};

class BSTree
{
	struct Node *root;

	void do_inorder(struct Node *n, int *arr, int *count);
public:
	BSTree();
	void insert(int val);
	void inorder(int *arr, int *count);
	int search(int val, int *nops);
};


