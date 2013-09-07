#include<stdio.h>
#include"bstree.h"
int main()
{
	BSTree b;
	printf("\nAdding elements...");
	b.add(10);
	b.add(7);
	b.add(5);
	b.add(14);
	b.add(6);
	b.add(11);
	b.add(15);
	printf("[ok]\n");
	printf("Checking count_non_leaf_nodes...");	
	if(b.count_non_leaf_nodes() != 4)
		goto fail;
	printf("[ok]\n");
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
