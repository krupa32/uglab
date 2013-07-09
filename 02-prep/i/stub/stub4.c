#include<stdio.h>
#include<string.h>
extern int get_num_occurences(char *str,char *word);
int main()
{
	char str[50],word[10];
        int n=0;
	strcpy(str,"hello world");
	strcpy(word,"hello");
	n=get_num_occurences(str,word);
	printf("single occurence...");
	if(n!=1)	
		goto end;
	printf("ok\n");

       strcpy(str,"world hello world world");
        strcpy(word,"world");
        n=get_num_occurences(str,word);
        printf("several occurence...");
        if(n!=3)        
                goto end;
        printf("ok\n");

       strcpy(str,"hello world");
        strcpy(word,"nill");
        n=get_num_occurences(str,word);
        printf("no occurence...");
        if(n!=0)        
                goto end;
        printf("ok\n");

       strcpy(str,"helloo world");
        strcpy(word,"hello");
        n=get_num_occurences(str,word);
        printf("as a substring occurence...");
        if(n!=0)        
                goto end;
        printf("ok\n");

	return 0;
end:
	printf(" failed\n");
	return -1;
}
	
	
