#include<stdio.h>
 struct point {int x;int y;};
extern void move(struct point *p, int offx, int offy);
int main()
{
	struct point p;
	p.x = 25; p.y = 20;
	move(&p, 0, 0);
	printf("\n testing with zeroes...");
	if(!( p.x== 25 && p.y == 20))
		goto fail;
	else printf("[ok]");
        move(&p, -10, 0);
	printf("\n testing with negetive values...");
        if(!( p.x== 15 && p.y == 20))
                goto fail;
	//else printf("[ok]");
	
        move(&p, 5, -10);
        if(!( p.x== 20 && p.y == 10))
                goto fail;
	else printf("[ok]");
	return 0;
  fail:
	printf("[failed]\n");
	return -1;	
}
