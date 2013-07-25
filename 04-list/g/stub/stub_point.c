#include<stdio.h>
struct point {int x;int y;};
extern int same(struct point *p1, struct point *p2);

int main()
{
	struct point p1, p2;

	printf("testing same points... ");
	p1.x = 25; p1.y = 20; p2.x = 25; p2.y = 20;
	if(!same(&p1, &p2))
		goto fail;
	printf("[ok]\n");

	printf("testing different points... ");
	p1.x = 25; p1.y = 20; p2.x = 25; p2.y = 2;
	if(same(&p1, &p2))
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;	
}
