
#include <stdio.h>

extern int sum(int arr[], int i1, int i2);

int main()
{
	int arr[] = { 1, 2, 3, 4, 9, 8, 7, 6 };

	printf("test 1...");
	if (sum(arr, 0, 1) != 3)
		goto fail;
	printf("[ok]\n");

	printf("test 2...");
	if (sum(arr, 0, 7) != 7)
		goto fail;
	printf("[ok]\n");

	printf("test 3...");
	if (sum(arr, 5, 6) != 15)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
