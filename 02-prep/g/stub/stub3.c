#include <stdio.h>
#include <string.h>

extern void trim(char *str);

int main()
{
	char buf[100];

	printf("testing left space...");
	strcpy(buf, "    beyond the horizon");
	trim(buf);
	if (strcmp(buf, "beyond the horizon") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing right space...");
	strcpy(buf, "beyond the horizon      ");
	trim(buf);
	if (strcmp(buf, "beyond the horizon") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing both space...");
	strcpy(buf, "      beyond the horizon     ");
	trim(buf);
	if (strcmp(buf, "beyond the horizon") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing no space...");
	strcpy(buf, "beyond the horizon");
	trim(buf);
	if (strcmp(buf, "beyond the horizon") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
