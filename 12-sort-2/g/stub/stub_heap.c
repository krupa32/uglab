#include <stdio.h>

#define MAX	10

#define PARENT(x)		(((x)-1)/2)
#define LEFTCHILD(x)		((x)*2+1)
#define RIGHTCHILD(x)		((x)*2+2)

extern void insert(int *heap, int size, int val);
extern int remove_min(int *heap, int size);

int check_heap(int *heap, int size)
{
	int left, right, i;

	for (i = 0; i < size/2; i++) {
		left = LEFTCHILD(i);
		right = RIGHTCHILD(i);
		if (left < size && heap[i] > heap[left])
			return 0;
		if (right < size && heap[i] > heap[right])
			return 0;
	}

	return 1;
}

int main()
{
	int arr[MAX] = { 9, 6, 3, 8, 5, 1, 4, 2, 0, 7 };
	int i, heap[MAX];

	printf("testing insert...");
	for (i = 0; i < MAX; i++) {
		insert(heap, i, arr[i]);
		if (!check_heap(heap, i+1))
			goto fail;
	}
	printf("[ok]\n");

	printf("testing remove_min...");
	for (i = 0; i < MAX; i++) {
		if (remove_min(heap, MAX - i) != i)
			goto fail;
		if (!check_heap(heap, MAX - i - 1))
			goto fail;
	}
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
