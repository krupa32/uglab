#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"

HashTable::HashTable(int siz)
{
	size = siz;
	arr = (struct entry *) malloc (size * sizeof(*arr));
	memset(arr, 0, size * sizeof(*arr));
}


int HashTable::insert(struct entry *e)
{
	int i, slot, found = 0;

	for (i = 0; i < size; i++) {
		slot = ((e->key * e->key) + i) % size;
		if (arr[slot].key == 0) {
			memcpy(&arr[slot], e, sizeof(*e));
			found = 1;
			break;
		}
	}

	return found;
}

int HashTable::search(int key, int *val, int *nops)
{
	int i, slot, found = 0;

	*nops = 0;
	*val = 0;

	for (i = 0; i < size; i++) {

		(*nops)++;

		slot = ((key * key) + i) % size;

		if (arr[slot].key == key) {
			*val = arr[slot].val;
			found = 1;
			break;
		}
	}

	return found;
}
