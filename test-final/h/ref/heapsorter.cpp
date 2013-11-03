#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "heapsorter.h"

#define PARENT(x)		(((x)-1)/2)
#define LEFT(x)			((x)*2+1)
#define RIGHT(x)		((x)*2+2)

#define SWAP(x,y,t)		{ t=x; x=y; y=t; }

void bubble_down(char **heap, int size, int i)
{
	int left, right, max;
	char *tmp;

	while (i < size) {
		max = i;
		left = LEFT(i);
		right = RIGHT(i);

		if (left < size && strcmp(heap[left], heap[max]) > 0)
			max = left;
		if (right < size && strcmp(heap[right], heap[max]) > 0)
			max = right;

		if (i != max) {
			SWAP(heap[i], heap[max], tmp);
			i = max;
		} else
			break;
	}
}


void build_heap(char **heap, int size)
{
	int i, left, right, max;
	char *tmp;

	for (i = size/2; i >= 0; i--) {
		bubble_down(heap, size, i);
	}
}

HeapSorter::HeapSorter()
{
}

void HeapSorter::sort(char **heap, int size)
{
	char *tmp;

	build_heap(heap, size);

	while (size > 1) {
		tmp = heap[0];
		heap[0] = heap[size - 1];
		heap[size - 1] = tmp;

		size--;

		bubble_down(heap, size, 0);
	}

}

Sorter *Sorter::create(void)
{
	return new HeapSorter();
}
