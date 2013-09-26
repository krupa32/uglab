struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

class BSTree
{
	struct BSTreeNode *root;

public:
	BSTree();
	void add(int val);
	int search(int val);
	void get_preorder(int *arr, int *count);
	int count_non_leaf_nodes(void); 
	void remove(int val);
};


