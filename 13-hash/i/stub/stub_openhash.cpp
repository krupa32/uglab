#include <stdio.h>
#include "openhash.h"

int main()
{
	OpenHashTable ht(10);
	struct entry arr[] = {
		{ 1, 12 }, { 2, 14 }, { 11, 39 }, { 12, 47 }, { 5, 8 },
		{ 6, 23 }, { 7, 33 }, { 8, 19 }, { 9, 76 }, { 22, 20 }
	};
	int i, val, nops, expected_nops[] = { 3, 4, 2, 3, 1, 1, 1, 2, 1, 1 };

	printf("testing insert...");
	for (i = 0; i < 10; i++) {
		if (!ht.insert(&arr[i]))
			goto fail;
	}
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
