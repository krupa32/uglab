struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

class BSTree
{
	struct BSTreeNode *root;

	void do_postorder(struct BSTreeNode *p, 
			int *arr, int *count);
	int do_get_height(struct BSTreeNode *p);
	void remove_node(struct BSTreeNode *p, struct BSTreeNode *parent);

public:
	BSTree();
	void add(int val);
	int search(int val);
	void remove(int val);
	void get_postorder(int *arr, int *count);
	int get_height(void); 
};


