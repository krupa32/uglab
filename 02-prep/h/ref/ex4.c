#include <string.h>

void num_to_words(int n, char *words)
{
	int digit, last_digit = 1, len;
	char tmp[100];
	char *digit_words[] = {
		"Zero ", "One ", "Two ", "Three ", "Four ",
		"Five ", "Six ", "Seven ", "Eight ", "Nine "
	};

	*words = 0;

	while (n) {

		digit = n % 10;

		/* backup the words */
		strcpy(tmp, words);

		/* copy word for digit as 1st word */
		strcpy(words, digit_words[digit]);

		/* digit_words array has an extra space for each word.
		 * but last digit should not have any extra space.
		 */
		if (last_digit) {
			/* remove extra space */
			len = strlen(words);
			words[len - 1] = 0;
			last_digit = 0;
		}

		/* append backed up word */
		strcat(words, tmp);

		n = n / 10;
	}

}


