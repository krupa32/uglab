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
	struct Node *get_head(void);
	void add_head(struct Node *n);
	struct Node *remove_head(void);
	struct Node *find(int val);
};


