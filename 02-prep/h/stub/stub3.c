#include<stdio.h>
#include<string.h>
extern void get_word(char *str, int n, char *word);
int main()
{
	int n;
	char word[50], str[50];
	n = 2;
	strcpy( str, "Hello World is a sample program" );
	bzero( word, strlen( word ) );
	get_word( str, n, word );
	printf("Word from the middle of a string : ");
	if( strcmp ( word, "World" ) )
		goto end;
	printf("ok\n");

	n = 1;
	strcpy( str, "Hello World is a sample program" );
	bzero( word, strlen( word ) );
	get_word( str, n, word );
	printf("1st Word from the string : ");
	if( strcmp ( word, "Hello" ) )
		goto end;
	printf("ok\n");

	n = 6;
	strcpy( str, "Hello World is a sample program" );
	bzero( word, strlen( word ) );
	get_word( str, n, word );
	printf("Last word from the string : ");
	if( strcmp ( word, "program" ) )
		goto end;
	printf("ok\n");

	n = 7;
	strcpy( str, "Hello World is a sample program" );
	bzero( word, strlen( word ) );
	get_word( str, n, word );
	printf("n > num of words in the string : ");
	if( strcmp ( word, "" ) )
		goto end;
	printf("ok\n");

	n = 2;
	strcpy( str, "" );
	bzero( word, strlen( word ) );
	get_word( str, n, word );
	printf("No Words in the string : ");
	if( strcmp ( word, "" ) )
		goto end;
	printf("ok\n");

	return 0;

end:
        printf("\n This case failed\n");
        return -1;
}
