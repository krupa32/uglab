#include<stdio.h>
#include<string.h>
extern void compress(char *str);
int main()
{
	char str[50];
	strcpy(str,"hello world");
	compress(str);
	printf("single space...");
	if( strcmp(str,"hello world"))
		goto end;
	printf("ok\n");
	
	strcpy(str,"more    space");
	printf("more space between words...");
	compress(str);
	if(strcmp(str,"more space"))
		goto end;
	printf("ok\n");

	strcpy(str, "   hello");
	printf("more space in the begining...");
	compress(str);
	if(strcmp(str," hello"))
		goto end;
	printf("Ok\n");

	strcpy(str,"nospace");
	printf("single word...");
	compress(str);
	if(strcmp(str,"nospace"))
		goto end;
	printf("ok\n");
	
	
        strcpy(str,"TOLOWER    ");
        printf("more space at the end...");
        compress(str);
        if(strcmp(str,"TOLOWER "))
                goto end;
        printf("ok\n");

	return 0;
end:
	printf("\n This case failed\n");
	return -1;
}
	
	
