#include "arraylist.h"

ArrayList::ArrayList()
{
	count = 0;
}

int ArrayList::insert(int pos, char c)
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

int ArrayList::remove(int pos, char *c)
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

int ArrayList::get_count(void)
{
	return count;
}

List * List::create(void)
{
	return new ArrayList();
}
