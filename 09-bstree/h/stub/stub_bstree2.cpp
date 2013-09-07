#include<stdio.h>
#include"bstree.h"
int main()
{
	BSTree b;
	printf("\nAdding elements...");
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	b.add(5);
	b.add(6);
	b.add(8);
	b.add(7);
	b.add(9);
	printf("[ok]\n");
	printf("Chenking count_leaf_nodes...");	
	if(b.count_leaf_nodes() != 2)
		goto fail;
	printf("[ok]\n");
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
