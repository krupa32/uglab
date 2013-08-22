
#define MAX_ELEMENTS    100

class SimpleList
{
	char arr[MAX_ELEMENTS];
	int count;

public:
	SimpleList();

	int insert(int pos, char c);
	int remove(int pos, char *c);
	int get_count(void);
};


