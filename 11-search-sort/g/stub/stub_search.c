#include<stdio.h>
#include<string.h>
#define MAX 10
extern int bsearch(int *arr, int size, int val);

int main()
{
	int i;
	int arr[MAX];

	for ( i = 0; i < MAX; i++ )
		arr[i] = i;
		
	printf ( "testing binary search... : " );
	if ( bsearch ( arr, MAX, 0 ) != 1 )
		goto fail;
	//printf ( "[ok]\n" );
	
	//printf ( "Last element : " );
	if ( bsearch ( arr, MAX, 9 ) != 1 )
		goto fail;
	//printf ( "[ok]\n" );
	
	//printf ( "Middle element : " );
	if ( bsearch ( arr, MAX, 8 ) != 1 )
		goto fail;
	//printf ( "[ok]\n" );
	
	//printf ( "Element not in array : " );
	if ( bsearch ( arr, MAX, 10 ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
			
	return 0;

fail:
	printf ( "[failed]\n" );
	return -1;
}
