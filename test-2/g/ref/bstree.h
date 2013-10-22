struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

class BSTree
{
	struct BSTreeNode *root;

	int do_get_height(struct BSTreeNode *p);

public:
	BSTree();
	void add(int val);
	int search(int val);
	int get_balancing_factor(void);
};


