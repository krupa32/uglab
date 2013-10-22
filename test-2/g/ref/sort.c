
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void sort(int *arr, int size)
{
	int i, j, min, min_index;

	for (i = 0; i < size - 1; i++) {

		min = arr[i];
		min_index = i;

		for (j = i+1; j < size; j++) {

			if (arr[j] < min) {
				min = arr[j];
				min_index = j;
			}
		}

		swap(&arr[i], &arr[min_index]);
	}
}
