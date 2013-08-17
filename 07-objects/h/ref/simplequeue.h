#define MAX_ELEMENTS    100

class SimpleQueue
{
	char arr[MAX_ELEMENTS];
	int tail;

public:
	SimpleQueue();

	int insert(char c);
	int remove(char *c);
	int empty(void);
};
