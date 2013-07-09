
void to_upper(char *str)
{
	while (*str) {

		if (*str >= 'a' && *str <= 'z')
			*str -= 'a' - 'A';

		str++;
	}
}

void to_lower(char *str)
{
	while (*str) {

		if (*str >= 'A' && *str <= 'Z')
			*str += 'a' - 'A';

		str++;
	}
}

