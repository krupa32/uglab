#include "point.h"

void move(struct point *p, int offx, int offy)
{
	p->x += offx;
	p->y += offy;
}
