#include<stdio.h>
#include"bstree.h"
int main()
{
	BSTree b;
	printf("testing add...");
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	if(b.search(4) == 0)
		goto fail;
	b.add(5);
	b.add(6);
	b.add(8);
	b.add(7);
	b.add(9);
	if(b.search(8) == 0)
		goto fail;
	if(b.search(7) == 0)
		goto fail;
	if(b.search(9) == 0)
		goto fail;
	printf("[ok]\n");
	
	printf("testing remove...");
	b.remove(4);
	if(b.search(4) == 1)
		goto fail;
	printf("[ok]\n");
	
	printf("testing search...");
	if(b.search(0) == 1)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
