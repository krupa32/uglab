#include <string.h>

#define LEFT	1
#define RIGHT	2

void rotate(char *str, int direction, int count)
{
	char tmp[100];
	int i, len, index;

	len = strlen(str);

	if (direction == LEFT)
		index = count;
	else
		index = len - count;

	index = index % len;

	for (i = 0; i < len; i++) {
		tmp[i] = str[index];
		index = (index + 1) % len;
	}

	tmp[i] = 0;
	strcpy(str, tmp);
}

