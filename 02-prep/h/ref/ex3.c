
#include <string.h>

void get_word(char *str, int n, char *word)
{
	int i = 0;
	char *p, *start, tmp[100];

	strcpy(tmp, str);

	*word = 0;

	p = tmp;
	start = tmp;

	while (*p) {
		if (*p == ' ') { /* word boundary reached */
			i++;
			if (i == n) { /* nth word found */
				*p = 0;
				strcpy(word, start);
				break;
			} else {
				/* move 'start' to next word */
				start = p + 1;
			}
		}

		p++;
	}

	/* special case for last word terminated by 0 */
	i++;
	if (i == n) { /* nth word found */
		*p = 0;
		strcpy(word, start);
	}

}

