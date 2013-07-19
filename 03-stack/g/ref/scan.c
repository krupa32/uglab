
extern int push(char c);
extern int pop(char *c);
extern int top;

int scan(const char *str)
{
	char ch;

	while (*str) {
		if (*str == '1')
			push(*str);
		else if (*str == '0')
			pop(&ch);

		str++;
	}

	return top;
}
