#include<stdio.h>
#include<string.h>
#define MAX 10
extern void qsort(int *arr, int size);

int main()
{
	int i;
	int arr[MAX] = { 5, 9, 3, 5, 18, 2, 1, 4, 6, 17 };
	int sorted[MAX] = { 1, 2, 3, 4, 5, 5, 6, 9, 17, 18 };
	
	
	printf ( "testing assorted : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX*sizeof(int) ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	printf ( "testing sorted array : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX*sizeof(int) ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	for ( i = 0; i < MAX; i++ )
		arr[i] = sorted[MAX - i - 1];
	printf ( "testing array sorted in descending order : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX*sizeof(int) ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	return 0;

fail:
	printf ( "[failed]\n" );
	return -1;
}
