#include"bstree.h"
#include<stdlib.h>
#include<stdio.h>
BSTree::BSTree()
{
	root = NULL; 
}
void BSTree::add(int val)
{
	BSTreeNode* t = new BSTreeNode;
	t->val = val;
	t->left = NULL;
	t->right = NULL;
	if(root == NULL)
		root = t;
	else
	{
		BSTreeNode* curr;
		BSTreeNode* parent;
		curr = root;
		parent = NULL;
		while(curr)
		{
			parent = curr;
			if(t->val < curr->val) 
				curr = curr->left;
			else 
				curr = curr->right;
		}
		if (t->val < parent->val)
			parent->left = t;
		else
			parent->right = t;
	}
}
void BSTree::remove(int val)
{
	if(root == NULL)
		return;
	BSTreeNode* curr;
	curr = root;
	while(curr != NULL)
	{
		if (curr->val == val)
		{
			BSTreeNode* t1;
			t1 = curr;
			while(t1->right)
			{
				BSTreeNode* t2;
				t2 = t1->right;
				while(t2->left)
				{
					t2 = t2->left;
				}
				int temp = t1->val;
				t1->val = t2->val;
				t2->val = temp;
				t1 = t2;
			}
			t1 = t1->left;
			break;
		}
		else if(val < curr->val) 
			curr = curr->left;
		else 
			curr = curr->right;
	}
}
int BSTree::search(int val)
{
	if(root == NULL)
		return 0;
	BSTreeNode* curr;
	curr = root;
	while(curr != NULL)
	{
		if (curr->val == val)
			return 1;
		else if(val < curr->val) 
			curr = curr->left;
		else 
			curr = curr->right;
	}
	return 0;
}

void inorder(BSTreeNode *, int *,int *,int *);
int BSTree::count_non_leaf_nodes(void)
{
	int nonLeafCnt=0;
	BSTreeNode* temp = root;
	//printf("callin preorder..\n");
	inorder(temp, NULL, NULL, &nonLeafCnt);
	//printf("returned from preorder..\n");
	return nonLeafCnt;
}
void inorder(BSTreeNode* root, int *arr, int *count, int *leafCnt)
{
//printf("root\n");
	if (root)
	{
//
		//if(leafCnt)
	//printf("hi...\n");
		inorder(root->left,arr,count,leafCnt);
		if(leafCnt)
		{	
						
			if( (root->right != NULL) || (root->left != NULL) )
			{
				//printf("left..\n");
				//printf("hiiii..\n");
				(*leafCnt) += 1;
			}
		}
		else
			arr[(*count)++] = root->val;
		//printf("%d - ",arr[*count]-1);		
		inorder(root->right, arr, count, leafCnt);
	}
}
void BSTree::get_inorder(int *arr, int *count)
{
	BSTreeNode* temp = root;
	inorder(temp, arr, count, NULL);
}

