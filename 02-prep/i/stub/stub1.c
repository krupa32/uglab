#include <stdio.h>

extern int square(int n);

int main()
{
	printf("testing normal number... ");
	if (square(5) != 25)
		goto fail;
	printf("[ok]\n");

	printf("testing large number... ");
	if (square(138) != 138*138)
		goto fail;
	printf("[ok]\n");

	printf("testing corner case 1... ");
	if (square(0) != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing corner case 2... ");
	if (square(-1) != 1)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
