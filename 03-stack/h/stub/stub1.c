
#include <stdio.h>

extern int equal_interval(int arr[], int size);

int main()
{
	int arr[] = { 
		1, 3, 5, 7, 9, 1, 11, 21, 31, 42, 
		1, 3, 5, 7, 5, -1, -3, -5, -7, -9 
	};

	printf("testing +ve nums...");
	if (equal_interval(arr, 5) != 1)
		goto fail;
	printf("[ok]\n");

	printf("testing +ve nums failure...");
	if (equal_interval(&arr[5], 5) != 0)
		goto fail;
	printf("[ok]\n");

	printf("test +ve nums unsorted...");
	if (equal_interval(&arr[10], 5) != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing -ve nums...");
	if (equal_interval(&arr[15], 5) != 1)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
