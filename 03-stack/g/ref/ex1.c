
int frequency(int arr[], int size, int n)
{
	int i, freq = 0;

	for (i = 0; i < size; i++) {
		if (arr[i] == n)
			freq++;
	}

	return freq;
}
