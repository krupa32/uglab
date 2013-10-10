#include<stdio.h>
#include<stdlib.h>

void mergesort(int *arr, int size);
void mergesort1(int*,  int, int);
void merge(int*, int, int, int);

void mergesort(int *arr, int size)
{
	mergesort1(arr, 0, size-1);
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

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
	int *L = (int *)malloc(sizeof(int)*n1);
	int *R = (int *)malloc(sizeof(int)*n2);

	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j <= n2; j++)
		R[j] = arr[m + 1+ j];
	
	i = 0; j = 0; k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
