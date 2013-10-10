void sort(int *arr, int size)
{
	int i, cur = 0, pos;
	for(i = 1; i < size; i++)
	{
		cur = arr[i];
		pos = i-1;
		while(pos >= 0)
		{
			if(arr[pos] > cur)
			{
				arr[pos+1] = arr[pos];
				pos--;
			}
			else
			{
				arr[pos+1] = cur;
				break;
			}
		}
		if(pos < 0) 
			arr[pos+1] = cur;
	}
}
