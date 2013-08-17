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

	String reverse(void);
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

	printf("testing reverse...");
	s3 = s1.reverse();
	s3.get_data(buf);
	if (strcmp(buf, "") != 0)
		goto fail;
	s3 = s2.reverse();
	s3.get_data(buf);
	if (strcmp(buf, "dlrow olleh") != 0)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
