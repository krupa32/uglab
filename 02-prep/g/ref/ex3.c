#include <string.h>

void trim(char *str)
{
	int i, len;
	char tmp[200], *start, *end, *p;

	strcpy(tmp, str);

	len = strlen(str);

	/* find first non-space char (dont go beyond end of string) */
	start = tmp;
	while (*start && *start == ' ')
		start++;

	/* find last non-space char (dont go beyond beginning of string) */
	end = tmp + len - 1;
	while (end >= tmp && *end == ' ')
		end--;

	/* copy all chars from start to end */
	p = start;
	while (p <= end) {
		*str = *p;
		str++;
		p++;
	}

	*str = 0;
}
