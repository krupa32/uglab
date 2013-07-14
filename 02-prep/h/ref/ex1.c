
int max(int a, int b, int c)
{
	int max;

	max = (a > b) ? a : b;

	max = (max > c) ? max : c;

	return max;
}

