#include <stdio.h>
#include <string.h>

#define MAX_LEN 	100

class String
{
	char data[MAX_LEN];

public:
	String();
	String(const char *s);

	void get_data(char *s);

	String substr(int start, int count);
};

int main()
{
	String s1, s2("hello world"), s3;
	char buf[MAX_LEN];


	printf("testing constructor...");
	s1.get_data(buf);
	if (strcmp(buf, "") != 0)
		goto fail;
	s2.get_data(buf);
	if (strcmp(buf, "hello world") != 0)
		goto fail;
	printf("[ok]\n");

	printf("testing substr...");
	s3 = s2.substr(3, 4);
	s3.get_data(buf);
	if (strcmp(buf, "lo w") != 0)
		goto fail;
	s3 = s2.substr(0, 4);
	s3.get_data(buf);
	if (strcmp(buf, "hell") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
