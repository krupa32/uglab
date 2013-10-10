int bsearch(int *arr, int size, int val)
{
	int lowerIndex, middleIndex, upperIndex, found;
	lowerIndex = 0;
	upperIndex = size - 1;
	found = 0;
	while ( lowerIndex <= upperIndex )
	{
		middleIndex = ( lowerIndex + upperIndex ) / 2;
		if ( val == arr[middleIndex] )
		{
			found = 1;
			break;
		}
		else if ( val < arr[middleIndex] )
			upperIndex = middleIndex - 1;
		else
			lowerIndex = middleIndex + 1;
	}
	return found;
}
