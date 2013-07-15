#include<stdio.h>
extern int max(int a, int b, int c);
int main()
{
	int a, b, c;
	a = 1001;
	b = 34;
	c = 72;
	printf("a is max ");
	if ( max ( a, b, c ) != a )
		goto end;
	printf("ok\n");

	a = 34;
	b = 72;
	c = 1001;
	printf("c is max ");
	if ( max ( a, b, c ) != c )
		goto end;
	printf("ok\n");

	a = 72;
	b = 1001;
	c = 34;
	printf("b is max ");
	if ( max ( a, b, c ) != b )
		goto end;
	printf("ok\n");

	a = -3;
	b = -34;
	c = -72;
	printf("all are negative ");
	if ( max ( a, b, c ) != a )
		goto end;
	printf("ok\n");

	a = -1001;
	b = 34;
	c = -72;
	printf("combo negative and positive numbers ");
	if ( max ( a, b, c ) != b )
		goto end;
	printf("ok\n");

	a = 34;
	b = 0;
	c = 72;
	printf("including 0 ");
	if ( max ( a, b, c ) != c )
		goto end;
	printf("ok\n");

	return 0;

end:
	printf("");
	printf("\n This case failed\n");
	return -1;
}
