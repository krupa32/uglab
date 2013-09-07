#include<stdio.h>
#include"bstree.h"
int main()
{
	BSTree b;
	int arr[7], count;
	int arr1[7]={5,6,7,10,11,14,15};
	b.add(10);
	b.add(7);
	b.add(5);
	b.add(14);
	b.add(6);
	b.add(11);
	b.add(15);
	
	printf("testing get_inorder...\n");
	b.get_inorder(arr, &count);
	
	printf("\tarr check : ");
	for(int i=0; i<7; i++)
	{
		if(arr[i] != arr1[i])
			goto fail;
	}
	printf("[ok]\n");
	
	printf("\tcount check : ");
	if(count != 7)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
