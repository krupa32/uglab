#include <string.h>
#include <stdio.h>

void compress(char *str)
{
	char tmp[100];
	char *dst = tmp, *src = str;
	int compressing = 0;

	while (*src) {

		if (*src != ' ') {
			*dst = *src;
			dst++;
			compressing = 0;
		} else { /* *src is a space */

			if (!compressing) {
				*dst = *src;
				dst++;
				compressing = 1;
			} else {
				/* compressing going on.
				 * do not copy the ' '.
				 */
			}
		}

		src++;
	}

	*dst = 0;

	strcpy(str, tmp);
}
