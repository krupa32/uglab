#include <stdio.h>
#include "advanced_stack.h"

#define STACK_SIZ	100

static int test_push_pop(advanced_stack *as)
{
	int ret = 0, i;
	advanced_stack *tmp;
	int data[20] = {
		14, 23, 35, 28, 76, 38, 24, 53, 74, 17,
		44, 78, 90,  9,  4, 67, 61, 70, 33, 60
	};

	/* test basic push and pop */
	printf("testing basic push/pop... ");
	as->push(23);
	as->push(55);
	if ((ret = as->pop()) != 55)
		goto failed;
	printf("[OK]\n");

	/* test size */
	printf("testing size... ");
	as->push(26);
	if (as->size() != 2)
		goto failed;
	printf("[OK]\n");

	/* test empty */
	printf("testing stack empty... ");
	as->pop();
	as->pop();
	if (as->pop() != -1)
		goto failed;
	printf("[OK]\n");

	/* test stack full */
	printf("testing stack full... ");
	for (i = 0; i < STACK_SIZ; i++)
		as->push(i);
	if (as->push(i) != -1)
		goto failed;
	printf("[OK]\n");

	/* empty the stack */
	while (as->pop() != -1)
		;

	/* check equals */
	printf("testing equals... ");
	tmp = new advanced_stack(STACK_SIZ);
	for (i = 0; i < 20; i++) {
		as->push(data[i]);
		tmp->push(data[i]);
	}
	if (!as->equals(tmp))
		goto failed;
	tmp->pop();
	if (as->equals(tmp))
		goto failed;
	delete tmp;
	printf("[OK]\n");

	/* empty the stack */
	while (as->pop() != -1)
		;

	return 0;

failed:
	printf("[FAILED]\n");
	return -1;

}


static int test_clone(advanced_stack *as)
{
	int ret = 0, i;
	advanced_stack *c;
	int data[20] = {
		14, 23, 35, 28, 76, 38, 24, 53, 74, 17,
		44, 78, 90,  9,  4, 67, 61, 70, 33, 60
	};

	for (i = 0; i < 20; i++)
		as->push(data[i]);

	c = as->clone();

	/* check clone's size */
	printf("testing clone size... ");
	if (c->size() != as->size())
		goto failed;
	printf("[OK]\n");

	/* check clone elements */
	printf("testing clone elements... ");
	if (!as->equals(c))
		goto failed;
	printf("[OK]\n");

	return 0;

failed:
	printf("[FAILED]\n");
	return -1;
}

static int test_palindrome(advanced_stack *as)
{
	int ret = 0, i;
	advanced_stack *p, *tmp;
	int data[20] = {
		14, 23, 35, 28, 76, 38, 24, 53, 74, 17,
		44, 78, 90,  9,  4, 67, 61, 70, 33, 60
	};

	p = as->create_palindrome();

	/* test palindrome */
	printf("testing palindrome... ");
	tmp = new advanced_stack(STACK_SIZ);
	for (i = 0; i < as->size(); i++)
		tmp->push(p->pop());
	if (!as->equals(tmp))
		goto failed;
	if (!as->equals(p))
		goto failed;
	delete tmp;
	printf("[OK]\n");

	return 0;

failed:
	printf("[FAILED]\n");
	return -1;
}

int main()
{
	int ret;
	advanced_stack *as = new advanced_stack(STACK_SIZ);

	if (test_push_pop(as) < 0) {
		ret = -1;
		goto out;
	}

	if (test_clone(as) < 0) {
		ret = -1;
		goto out;
	}

	if (test_palindrome(as) < 0) {
		ret = -1;
		goto out;
	}

	delete as;
out:
	return ret;
}
