#include <stdio.h>

#define MAX	10

extern void heapsort(int *arr, int size);

int main()
{
	int arr[MAX] = { 9, 6, 3, 8, 5, 1, 4, 2, 0, 7 };
	int i;

	printf("testing heapsort...");
	heapsort(arr, MAX);
	for (i = 0; i < MAX; i++) {
		if (arr[i] != i)
			goto fail;
	}
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
