#include<stdio.h>
#include<string.h>
extern void num_to_words(int n, char *words);
int main()
{
	int n;
	char words[100];
	n = 5;
	num_to_words( n, words );
	printf("One digit : ");
	if( strcmp ( words, "Five" ) )
		goto end;
	printf("ok\n");

	n = 78;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("Two digit : ");
	if( strcmp ( words, "Seven Eight" ) )
		goto end;
	printf("ok\n");

	n = 342;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("3 digit : ");
	if( strcmp ( words, "Three Four Two" ) )
		goto end;
	printf("ok\n");

	n = 9264;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("4 digit : ");
	if( strcmp ( words, "Nine Two Six Four" ) )
		goto end;
	printf("ok\n");

	n = 85471;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("5 digit : ");
	if( strcmp ( words, "Eight Five Four Seven One" ) )
		goto end;
	printf("ok\n");

	n = 100;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("Only Hundreds digit : ");
	if( strcmp ( words, "One Zero Zero" ) )
		goto end;
	printf("ok\n");

	n = 22045;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("No Hundreds digit : ");
	if( strcmp ( words, "Two Two Zero Four Five" ) )
		goto end;
	printf("ok\n");

	n = 22305;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("No Tens digit : ");
	if( strcmp ( words, "Two Two Three Zero Five" ) )
		goto end;
	printf("ok\n");

	n = 72930;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("No Ones digit : ");
	if( strcmp ( words, "Seven Two Nine Three Zero" ) )
		goto end;
	printf("ok\n");

	n = 60738;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("No Thousands digit : ");
	if( strcmp ( words, "Six Zero Seven Three Eight" ) )
		goto end;
	printf("ok\n");

	n = 60038;
	bzero( words, strlen( words ) );
	num_to_words( n, words );
	printf("No Thousands and Hundreds digit : ");
	if( strcmp ( words, "Six Zero Zero Three Eight" ) )
		goto end;
	printf("ok\n");

	return 0;

end:
        printf("\n This case failed\n");
        return -1;
}
