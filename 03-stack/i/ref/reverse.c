
extern int push(char c);
extern int pop(char *c);

void reverse(const char *str, char *reverse_str)
{
	char ch;

	while (*str) {
		push(*str);
		str++;
	}

	while (pop(&ch)) {
		*reverse_str = ch;
		reverse_str++;
	}

	*reverse_str = 0;
}
