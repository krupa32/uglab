
#define Q_SIZE		50

int queue[Q_SIZE];
int tail = 0;

int insert(int val)
{
	if (tail == Q_SIZE)
		return 0;

	queue[tail++] = val;

	return 1;
}

int delete(int *val)
{
	int i;

	if (tail == 0)
		return 0;

	*val = queue[0];

	tail--;

	for (i = 0; i < tail; i++)
		queue[i] = queue[i+1];

	return 1;
}

int empty(void)
{
	return (tail == 0);
}
