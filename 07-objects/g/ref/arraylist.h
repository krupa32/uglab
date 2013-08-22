#include "list.h"

#define MAX_ELEMENTS    100

class ArrayList : public List
{
	char arr[MAX_ELEMENTS];
	int count;

public:
	ArrayList();

	int insert(int pos, char c);
	int remove(int pos, char *c);
	int get_count(void);

};


