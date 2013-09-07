struct BSTreeNode
{
    int val;
    BSTreeNode *left;
    BSTreeNode *right;
};

class BSTree
{
    BSTreeNode *root;

public:
    BSTree();
    void add(int val);
    void remove(int val);
    int search(int val);
    int count_non_leaf_nodes(void);
    void get_inorder(int *arr, int *count);
};
