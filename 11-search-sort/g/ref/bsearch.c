int bsearch(int *arr, int size, int val)
{
	int lower, middle, upper, found;

	lower = 0;
	upper = size - 1;
	found = 0;
	while ( lower <= upper )
	{
		middle = ( lower + upper ) / 2;
		if ( val == arr[middle] )
		{
			found = 1;
			break;
		}
		else if ( val < arr[middle] )
			upper = middle - 1;
		else
			lower = middle + 1;
	}

	return found;
}
