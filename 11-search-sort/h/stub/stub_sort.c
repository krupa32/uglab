#include<stdio.h>
#include<string.h>
#define MAX 10
extern void sort(int *arr, int size);

int main()
{
	int i;
	int arr[MAX] = { 5, 9, 3, 5, 8, 2, 1, 4, 6, 7 };
	int sorted[MAX] = { 1, 2, 3, 4, 5, 5, 6, 7, 8, 9 };
	
	
	printf ( "testing assorted : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	printf ( "testing sorted array : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	for ( i = 0; i < MAX; i++ )
	{
		arr[i] = MAX - i - 1;
		sorted[i] = i;
	}
	printf ( "testing array sorted in descending order : " );
	sort ( arr, MAX );
	if ( memcmp ( arr, sorted, MAX ) != 0 )
		goto fail;
	printf ( "[ok]\n" );
	
	
	return 0;

fail:
	printf ( "[failed]\n" );
	return -1;
}