#include <stdio.h>

#define Q_SIZE		50

int insert(int val);
int delete(int *val);
int empty(void);

int main()
{
	int i, val;

	printf("testing insert...\n");
	for (i = Q_SIZE - 1; i >= 0; i--) {
		if (!insert(i*i+3)) {
			printf("[failed for %d]\n", i);
			goto test_delete;
		}
	}
	if (insert(i*i+3)) {
		printf("[failed]\n");
		goto test_delete;
	}
	printf("[ok]\n");

test_delete:
	printf("testing delete...\n");
	for (i = Q_SIZE - 1; i >= 0; i--) {
		if (!delete(&val) || val != (i*i+3)) {
			printf("[failed]\n");
			goto test_empty;
		}
	}
	if (delete(&val)) {
		printf("[failed]\n");
		goto test_empty;
	}
	printf("[ok]\n");

test_empty:
	printf("testing empty...\n");
	while (delete(&val))
		;
	if (!empty())
		goto fail;
	insert(0);
	if (empty())
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
