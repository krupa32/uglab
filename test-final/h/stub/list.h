struct Node
{
	int val;
	struct Node *next;
};

class List
{
	struct Node *head;

public:
	List();
	struct Node * get_head(void);
	void add_tail(int val);
	void remove(int val);
	int search(int val, int *nops);
};


