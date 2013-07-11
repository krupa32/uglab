#include <string.h>
#include <stdio.h>

void get_longest_word(char *str, char *longest)
{
	int longest_len = 0, done = 0;
	char tmp[100], *p, *word;

	strcpy(tmp, str);
	p = tmp;
	word = tmp;

	while (!done) {

		word = p;

		/* move p till next ' ' */
		while (*p && *p != ' ')
			p++;

		if (*p == 0)
			done = 1;

		/* replace ' ' by 0 and move p */
		*p = 0;
		p++;

		/* 'word' now has the last word extracted */
		if (strlen(word) > longest_len) {
			strcpy(longest, word);
			longest_len = strlen(word);
		}
	}

}

void get_shortest_word(char *str, char *shortest)
{
	int shortest_len = 1000, done = 0;
	char tmp[100], *p, *word;

	strcpy(tmp, str);
	p = tmp;
	word = tmp;

	while (!done) {

		word = p;

		/* move p till next ' ' */
		while (*p && *p != ' ')
			p++;

		if (*p == 0)
			done = 1;

		/* replace ' ' by 0 and move p */
		*p = 0;
		p++;

		/* 'word' now has the last word extracted */
		if (strlen(word) < shortest_len) {
			strcpy(shortest, word);
			shortest_len = strlen(word);
		}
	}


}

