#include <stdio.h>
#include <string.h>

#define LEFT	1
#define RIGHT	2

extern void shift(char *str, int direction, int count);

int main()
{
	char buf[100];

	printf("testing left shift 1...");
	strcpy(buf, "beyond the horizon");
	shift(buf, LEFT, 3);
	if (strcmp(buf, "ond the horizon   ") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing left shift 2...");
	strcpy(buf, "beyond the horizon");
	shift(buf, LEFT, 7);
	if (strcmp(buf, "the horizon       ") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing right shift 1...");
	strcpy(buf, "beyond the horizon");
	shift(buf, RIGHT, 3);
	if (strcmp(buf, "   beyond the hori") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing right shift 2...");
	strcpy(buf, "beyond the horizon");
	shift(buf, RIGHT, 8);
	if (strcmp(buf, "        beyond the") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing no shift...");
	strcpy(buf, "beyond the horizon");
	shift(buf, LEFT, 0);
	if (strcmp(buf, "beyond the horizon") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
