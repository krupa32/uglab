struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

class BSTree
{
	struct BSTreeNode *root;

	void do_inorder(struct BSTreeNode *p, 
			int *arr, int *count);
	int do_get_height(struct BSTreeNode *p);

public:
	BSTree();
	void add(int val);
	int search(int val);
	void get_inorder(int *arr, int *count);
	int get_height(void); 
	void remove(int val);
};


