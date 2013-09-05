
#include "vector.h"
#include "dbllist.h"

class DoubleVector : public Vector
{
	DblList list;

public:

	DoubleVector();

        int insert(int pos, char c);
        int remove(int pos, char *c);
        int empty(void);
};
