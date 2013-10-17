#include<stdio.h>
#include<stdlib.h>


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	int *L, *R;

	//printf("merge: lower=%d, middle=%d, upper=%d, n1=%d, n2=%d\n", l, m, r, n1, n2);

       	L = (int *)malloc(sizeof(int)*n1);
	R = (int *)malloc(sizeof(int)*n2);

	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = 0;

	for (i = l; i <= r; i++) {
		if ((j < n1 && L[j] <= R[k]) || k >= n2) {
			/* If either current left array element is smaller
			 * OR the right array is exhausted,
			 * move the current left array element into arr.
			 */
			arr[i] = L[j];
			j++;
		} else {
			arr[i] = R[k];
			k++;
		}
	}

	free(L);
	free(R);
}

void mergesort1(int *arr, int lower, int upper)
{
	int middle;

	if(lower < upper)
	{
		middle = (lower+upper)/2;
		mergesort1(arr, lower, middle);
		mergesort1(arr, middle+1, upper);
		merge(arr, lower, middle, upper);
	}
	return;
}


void mergesort(int *arr, int size)
{
	mergesort1(arr, 0, size-1);
}

