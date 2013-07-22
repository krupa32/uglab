
extern int push(char c);
extern int pop(char *c);
extern int top;

int scan(const char *str)
{
	int i, num;
	char c;

	while (*str) {
		if (*str >= 'a' && *str <= 'z')
			push(*str);
		else if (*str >= '0' && *str <= '9') {
			num = *str - '0';
			for (i = 0; i < num; i++)
				pop(&c);
		}

		str++;
	}

	return top;
}
