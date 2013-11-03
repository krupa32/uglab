#include <stdlib.h>

#define PARENT(x)		(((x)-1)/2)
#define LEFTCHILD(x)		((x)*2+1)
#define RIGHTCHILD(x)		((x)*2+2)

#define SWAP(x,y,t)		{ t=x; x=y; y=t; }

void bubble_down(int *heap, int size, int index)
{
	int left, right, tmp, smallest;

	smallest = index;
	left = LEFTCHILD(index);
	right = RIGHTCHILD(index);

	if (left < size && heap[left] < heap[smallest])
		smallest = left;

	if (right < size && heap[right] < heap[smallest])
		smallest = right;

	if (smallest != index) {
		SWAP(heap[smallest], heap[index], tmp);
		bubble_down(heap, size, smallest);
	}
}

void bubble_up(int *heap, int size, int i)
{
	int parent = PARENT(i), tmp;

	while (i > 0) {
		parent = PARENT(i);

		if (heap[i] < heap[parent])
			SWAP(heap[i], heap[parent], tmp);

		i = parent;
	}
}

void insert(int *heap, int size, int val)
{
	heap[size] = val;
	bubble_up(heap, size+1, size);
}

int remove_min(int *heap, int size)
{
	int ret = heap[0], tmp, done = 0, left, right, i;

	SWAP(heap[0], heap[size-1], tmp);

	bubble_down(heap, size-1, 0);

	return ret;
}
    

void heapsort(int *arr, int size)
{
	int *heap, i;

	heap = (int *) malloc(size * sizeof(int));

	for (i = 0; i < size; i++)
		insert(heap, i, arr[i]);

	for (i = 0; i < size; i++)
		arr[i] = remove_min(heap, size - i);
}
