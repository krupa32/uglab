#include "simplelist.h"

SimpleList::SimpleList()
{
	count = 0;
}

int SimpleList::insert(int pos, char c)
{
	int i;

	if (count == MAX_ELEMENTS)
		return 0;

	if (pos == -1) {
		pos = count;
	} else {
		for (i = count - 1; i >= pos; i--)
			arr[i + 1] = arr[i];
	}

	arr[pos] = c;

	count++;

	return 1;
}

int SimpleList::remove(int pos, char *c)
{
	int i;

	if (count == 0)
		return 0;

	*c = arr[pos];

	for (i = pos; i < count; i++)
		arr[i] = arr[i+1];

	count--;

	return 1;
}

int SimpleList::get_count(void)
{
	return count;
}

