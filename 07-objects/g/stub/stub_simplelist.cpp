#include <stdio.h>

#define MAX_ELEMENTS    100

class SimpleList
{
	char arr[MAX_ELEMENTS];
	int count;

public:
	SimpleList();

	int insert(int pos, char c);
	int remove(int pos, char *c);
	int get_count(void);
};


int main()
{
	SimpleList l;
	char c;

	printf("testing insert/remove...");
	if (!l.insert(-1, 'a'))
		goto fail;
	if (!l.insert(-1, 'b'))
		goto fail;
	if (!l.insert(1, 'c'))
		goto fail;
	if (!l.remove(0, &c) || c != 'a')
		goto fail;
	if (!l.remove(1, &c) || c != 'b')
		goto fail;
	if (!l.remove(0, &c) || c != 'c')
		goto fail;
	printf("[ok]\n");

	printf("testing count...");
	if (l.get_count() != 0)
		goto fail;
	l.insert(-1, 'a');
	if (l.get_count() != 1)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
