#include "point.h"

int rect_area(struct point *p1, struct point *p2)
{	
	return (p2->x - p1->x) * (p2->y - p1->y);
}
