
int equal_interval(int arr[], int size)
{
	int diff, interval, i;

	if (size <= 2)
		return 1;

	diff = arr[1] - arr[0];

	for (i = 0; i < size - 1; i++) {
		diff = arr[i+1] - arr[i];
		if (i == 0)
			interval = diff;
		else if (interval != diff)
			return 0;
	}

	return 1;
}
