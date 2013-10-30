struct entry
{
	int key;
	int val;
};

class HashTable
{
	int size;
	struct entry *arr;

public:
	HashTable(int size);
	int insert(struct entry *e);
	int search(int key, int *val, int *nops);
};


