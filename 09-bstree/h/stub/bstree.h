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
    int count_leaf_nodes(void);
    void get_preorder(int *arr, int *count);
};
