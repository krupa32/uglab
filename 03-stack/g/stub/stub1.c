
#include <stdio.h>

extern int frequency(int arr[], int size, int n);

int main()
{
	int arr[] = { 
		1, 2, 3, 4, 9, 9, 7, 6, 4, 5, 
		3, 6, 7, 4, 5, 7, 3, 4, 9, 7 
	};

	printf("test 1...");
	if (frequency(arr, 1, 1) != 1)
		goto fail;
	printf("[ok]\n");

	printf("test 2...");
	if (frequency(arr, 10, 4) != 2)
		goto fail;
	printf("[ok]\n");

	printf("test 3...");
	if (frequency(arr, 20, 4) != 4)
		goto fail;
	printf("[ok]\n");

	printf("test 4...");
	if (frequency(arr, 20, 8) != 0)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
