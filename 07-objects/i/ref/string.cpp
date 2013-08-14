#include <string.h>

#define MAX_LEN    100

class String
{
	char data[MAX_LEN];

public:
	String();
	String(const char *s);

	void get_data(char *s);

	String duplicate(void);
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

String String::duplicate(void)
{
	String s(data);

	return s;
}
