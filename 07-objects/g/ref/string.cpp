#include <string.h>

#define MAX_LEN    100

class String
{
	char data[MAX_LEN];

public:
	String();
	String(const char *s);

	void get_data(char *s);

	String substr(int start, int count);
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

String String::substr(int start, int count)
{
	char buf[MAX_LEN];
	int i;


	for (i = 0; i < count; i++)
		buf[i] = data[start + i];
	buf[i] = 0;

	String s(buf);


	return s;
}
