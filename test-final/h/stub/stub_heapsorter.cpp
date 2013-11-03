#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorter.h"

int main()
{
	Sorter *s;
	int i;
	const char *strings[10] = {
		"huawei", "darshan", "transcend", "lenovo", "mouse",
		"scale", "pencil", "unix", "singer", "checks"
	};
	char *arr[10];
	const char *sorted[10] = {
		"checks", "darshan", "huawei", "lenovo", "mouse",
		"pencil", "scale", "singer", "transcend", "unix"
	};

	/* initialize */
	for (i = 0; i < 10; i++) {
		arr[i] = (char *)malloc(20);
		strcpy(arr[i], strings[i]);
	}


	s = Sorter::create();

	printf("testing sort...");
	s->sort(arr, 10);
	for (i = 0; i < 10; i++) {
		if (strcmp(arr[i], sorted[i]) != 0)
			goto fail;
	}
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
