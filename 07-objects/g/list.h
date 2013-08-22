class List
{

public:

	virtual int insert(int pos, char c) = 0;

	virtual int remove(int pos, char *c) = 0;

	virtual int get_count(void) = 0;

	static List * create(void);
};


