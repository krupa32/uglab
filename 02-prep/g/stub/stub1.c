#include <stdio.h>

extern int absdiff(int a, int b);

int main()
{

	printf("testing +ve numbers...");
	if (absdiff(10, 6) != 4)
		goto fail;
	printf("[ok]\n");

	printf("testing +ve numbers...");
	if (absdiff(10, 16) != 6)
		goto fail;
	printf("[ok]\n");

	printf("testing -ve numbers...");
	if (absdiff(10, -6) != 16)
		goto fail;
	printf("[ok]\n");

	printf("testing -ve numbers...");
	if (absdiff(-5, 3) != 8)
		goto fail;
	printf("[ok]\n");

	printf("testing -ve numbers...");
	if (absdiff(-5, -8) != 3)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
