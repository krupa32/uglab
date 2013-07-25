#include "point.h"

int same(struct point *p1, struct point *p2)
{
	return (p1->x == p2->x) && (p1->y == p2->y);
}
