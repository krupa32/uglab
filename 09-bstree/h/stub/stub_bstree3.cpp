#include<stdio.h>
#include"bstree.h"
int main()
{
	BSTree b;
	int arr[9], count;
	int arr1[9]={1,2,3,4,5,6,8,7,9};
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	b.add(5);
	b.add(6);
	b.add(8);
	b.add(7);
	b.add(9);
	
	printf("testing get_preorder...\n");
	b.get_preorder(arr, &count);
	
	printf("\tarr check : ");
	for(int i=0; i<9; i++)
	{
		if(arr[i] != arr1[i])
			goto fail;
	}
	printf("[ok]\n");
	
	printf("\tcount check : ");
	if(count != 9)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
