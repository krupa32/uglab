struct entry
{
        int key;
        int val;
	struct entry *next;
};

class OpenHashTable
{

        int size;
        struct entry **arr;

public:
        OpenHashTable(int size);
        int insert(struct entry *e);
        int search(int key, int *val, int *nops);
};
