#include <stdio.h>
#include <string.h>

extern void get_longest_word(char *str, char *longest);
extern void get_shortest_word(char *str, char *shortest);

int main()
{
	char buf[100], tmp[100];

	printf("testing longest word 1...");
	strcpy(buf, "beyond the horizon");
	get_longest_word(buf, tmp);
	if (strcmp(tmp, "horizon") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing longest word 2...");
	strcpy(buf, "to a glimpse of how green it was on the other side");
	get_longest_word(buf, tmp);
	if (strcmp(tmp, "glimpse") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing shortest word 1...");
	strcpy(buf, "beyond the horizon");
	get_shortest_word(buf, tmp);
	if (strcmp(tmp, "the") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing shortest word 2...");
	strcpy(buf, "to a glimpse of how green it was on the other side");
	get_shortest_word(buf, tmp);
	if (strcmp(tmp, "a") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
