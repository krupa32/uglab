struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

class BSTree
{
	struct BSTreeNode *root;

	void do_preorder(struct BSTreeNode *p, 
			int *arr, int *count);
	int do_count_non_leaf_nodes(struct BSTreeNode *p);
	void remove_node(struct BSTreeNode *p, struct BSTreeNode *parent);

public:
	BSTree();
	void add(int val);
	int search(int val);
	void get_preorder(int *arr, int *count);
	int count_non_leaf_nodes(void); 
	void remove(int val);
};


