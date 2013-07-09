
int get_num_occurences(char *str, char *word)
{
	int occurences = 0;
	char tmp[100], *p;

	p = tmp;
	*p = 0;

	while (*str) {

		if (*str == ' ') { /* word boundary reached */
			*p = 0;
			if (strcmp(tmp, word) == 0)
				occurences++;

			p = tmp;
			*p = 0;
			
		} else {
			/* continue forming the word */
			*p = *str;
			p++;
		}

		str++;
	}

	/* test last word in the string  */
	if (strcmp(tmp, word) == 0)
		occurences++;

	return occurences;
}

