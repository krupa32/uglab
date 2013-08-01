#include<stdio.h>
struct point {int x;int y;};
extern int rect_area(struct point *p1, struct point *p2);

int main()
{
	struct point p1, p2;

	printf("p1 is origin ");
	p1.x = 0; p1.y = 0; p2.x = 5; p2.y = 20;
	if(rect_area(&p1, &p2) != 100)
		goto fail;
	printf("[ok]\n");

	printf("p1 is in the x axis... ");
	p1.x = 25; p1.y = 0; p2.x = 26; p2.y = 2;
	if(rect_area(&p1, &p2) != 2)
		goto fail;
	printf("[ok]\n");

	printf("p1 is in the y axis... ");
	p1.x = 0; p1.y = 1; p2.x = 26; p2.y = 2;
	if(rect_area(&p1, &p2) != 26)
		goto fail;
	printf("[ok]\n");

	printf("p1 is not in any axis... ");
	p1.x = 10; p1.y = 15; p2.x = 15; p2.y = 20;
	if(rect_area(&p1, &p2) != 25)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;	
}
