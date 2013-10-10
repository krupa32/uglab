void sort(int *arr, int size)
{
	int i, j, temp;
	for ( i = 1; i < size; i++ )
	{
		for ( j = 0; j < size - 1; j++ )
		if ( arr[j] > arr[j+1] )
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
}