#include<stdio.h>
#include<string.h>
extern void to_upper(char *str);
extern void to_lower(char *str);
int main()
{
	char str[50];
	strcpy(str,"hello world");
	to_upper(str);
	printf("all chars are lower case...");
	if( strcmp(str,"HELLO WORLD"))
		goto end;
	printf("ok\n");
	
	strcpy(str,"f");
	printf("single character...");
	to_upper(str);
	if(strcmp(str,"F"))
		goto end;
	printf("ok\n");

	strcpy(str, "MixED cAsE");
	printf("some chars are upper case...");
	to_upper(str);
	if(strcmp(str,"MIXED CASE"))
		goto end;
	printf("Ok\n");

	strcpy(str,"2SpeciAl CharacTERS@:");
	printf("string with spl chars...");
	to_upper(str);
	if(strcmp(str,"2SPECIAL CHARACTERS@:"))
		goto end;
	printf("ok\n");
	
	
        strcpy(str,"TOLOWER");
        printf("all chars are uppercase...");
        to_lower(str);
        if(strcmp(str,"tolower"))
                goto end;
        printf("ok\n");

        strcpy(str,"KinG fiSHEr");
        printf("chars with mixed case...");
        to_lower(str);
        if(strcmp(str,"king fisher"))
                goto end;
        printf("ok\n");

        strcpy(str,"$");
        printf("spl chars...");
        to_lower(str);
        if(strcmp(str,"$"))
                goto end;
        printf("ok\n");

        strcpy(str,"<lower>");
        printf("lower case with spl chars...");
        to_lower(str);
        if(strcmp(str,"<lower>"))
                goto end;
        printf("ok\n");

	printf("\n Both the functions are ok\n");
	return 0;
end:
	printf("\n This case failed\n");
	return -1;
}
	
	
