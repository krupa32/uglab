#include<stdio.h>
#include<string.h>
extern void rotate(char *str, int direction, int count);
int main()
{
        char str[50];
	int direction, count;
        strcpy(str,"12345678");
	direction = 1;
	count = 3;
        rotate(str,direction,count);
        printf("rotate 3(value less than len of string) characters to left...");
        if( strcmp(str,"45678123"))
                goto end;
        printf("ok\n");

	strcpy(str,"12345678");
        direction = 1;
        count = 0;
        rotate(str,direction,count);
        printf("rotate no characters to left...");
        if( strcmp(str,"12345678"))
                goto end;
        printf("ok\n");

        strcpy(str,"12345678");
        direction = 1;
        count = 8;
        rotate(str,direction,count);
        printf("rotate all characters to left...");
        if( strcmp(str,"12345678"))
                goto end;
        printf("ok\n");

        strcpy(str,"1");
        direction = 1;
        count = 0;
        rotate(str,direction,count);
        printf("length of string = 1. rotate no character to left...");
        if( strcmp(str,"1"))
                goto end;
        printf("ok\n");

        strcpy(str,"1");
        direction = 1;
        count = 1;
        rotate(str,direction,count);
        printf("length of string = 1. rotate 1 character to left...");
        if( strcmp(str,"1"))
                goto end;
        printf("ok\n");
        

	strcpy(str,"12345678");
        direction = 2;
        count = 3;
        rotate(str,direction,count);
        printf("rotate 3(value less than len of string) characters to right...");
        if( strcmp(str,"67812345"))
                goto end;
        printf("ok\n");

        strcpy(str,"12345678");
        direction = 2;
        count = 0;
        rotate(str,direction,count);
        printf("rotate no characters to right...");
        if( strcmp(str,"12345678"))
                goto end;
        printf("ok\n");

        strcpy(str,"12345678");
        direction = 2;
        count = 8;
	printf("rotate all characters to right...");
        if( strcmp(str,"12345678"))
                goto end;
        printf("ok\n");

        strcpy(str,"1");
        direction = 2;
        count = 0;
        rotate(str,direction,count);
        printf("length of string = 1. rotate no character to right...");
        if( strcmp(str,"1"))
                goto end;
        printf("ok\n");

        strcpy(str,"1");
        direction = 2;
        count = 1;
        rotate(str,direction,count);
        printf("length of string = 1. rotate 1 character to right...");
        if( strcmp(str,"1"))
                goto end;
        printf("ok\n");
	return 0;

end:
        printf("\n This case failed\n");
        return -1;
}
