#include <string.h>

#define LEFT	1
#define RIGHT	2

void shift(char *str, int direction, int count)
{
	int i, len;

	len = strlen(str);

	if (direction == LEFT) {
		/* move (len - count) chars to left */
		for (i = 0; i < len - count; i++)
			str[i] = str[i + count];

		/* fill last count chars with ' ' */
		for ( ; i < len; i++)
			str[i] = ' ';
	} else {
		/* move (len - count) chars to right */
		for (i = len - 1; i >= count; i--)
			str[i] = str[i - count];

		/* fill first count chars with ' ' */
		for ( ; i >= 0; i--)
			str[i] = ' ';
	}
}
