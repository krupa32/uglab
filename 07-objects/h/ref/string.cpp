#include <string.h>

#define MAX_LEN    100

class String
{
	char data[MAX_LEN];

public:
	String();
	String(const char *s);

	void get_data(char *s);

	String reverse(void);
};

String::String()
{
	data[0] = 0;
}

String::String(const char *s)
{
	strcpy(data, s);
}

void String::get_data(char *s)
{
	strcpy(s, data);
}

String String::reverse(void)
{
	char rev[MAX_LEN];
	int i, j = 0;

	for (i = strlen(data) - 1; i >= 0; i--)
		rev[j++] = data[i];
	rev[j] = 0;

	String s(rev);

	return s;
}
