
class Node
{
protected:
	Node *prev;
	Node *next;

public:

	Node();

	Node *get_prev(void);

	Node *get_next(void);

        void insert_after(Node *p);

	void remove(void);

	virtual void get_data(void *) = 0;

	static Node *create(void *);

};


