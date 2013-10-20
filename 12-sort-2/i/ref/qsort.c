void quicksort( int *arr, int lowerIndex, int upperIndex );
int partition( int *arr, int lowerIndex, int upperIndex );

void qsort(int *arr, int size)
{
	quicksort ( arr, 0, size-1 );
}

void quicksort( int *arr, int lowerIndex, int upperIndex )
{
	int pivot;
	if ( upperIndex > lowerIndex )
	{
		pivot = partition ( arr, lowerIndex, upperIndex );
		quicksort ( arr, lowerIndex, pivot - 1 );
		quicksort ( arr, pivot + 1, upperIndex );
	}
}

int partition( int *arr, int lowerIndex, int upperIndex )
{
	int left, right;
	int pivot_item;
	pivot_item = arr[lowerIndex]; 
	left = lowerIndex; 
	right = upperIndex;
	while ( left < right ) 
	{
		while( arr[left] <= pivot_item ) 
			left++;
		while( arr[right] > pivot_item ) 
			right--;
		if ( left < right ) 
		{
			int temp;
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp; 
		}
	}
	arr[lowerIndex] = arr[right];
	arr[right] = pivot_item;
	return right;
}