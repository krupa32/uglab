#include <stdio.h>
#include "hashtable.h"

int main()
{
	HashTable ht(10);
	struct entry arr[] = {
		{ 1, 12 }, { 2, 14 }, { 3, 39 }, { 4, 47 }, { 5, 8 },
		{ 6, 23 }, { 7, 33 }, { 8, 19 }, { 9, 76 }, { 10, 20 }
	};
	int i, val, nops, expected_nops[] = { 1, 1, 1, 1, 1, 2, 2, 5, 2, 4 };

	printf("testing insert...");
	for (i = 0; i < 10; i++) {
		if (!ht.insert(&arr[i]))
			goto fail;
	}
	if (ht.insert(&arr[0]))
		goto fail;
	printf("[ok]\n");

	printf("testing search...");
	for (i = 0; i < 10; i++) {
		if (!ht.search(arr[i].key, &val, &nops))
			goto fail;
		if (val != arr[i].val || nops != expected_nops[i])
			goto fail;
	}
	if (ht.search(99, &val, &nops))
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
