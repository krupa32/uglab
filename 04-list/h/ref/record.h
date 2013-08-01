
#define MAX_NAME	25

struct record
{
	int roll_num;
	char name[MAX_NAME];
	int mark;

	struct record *next;
};


struct list
{
	struct record *head;
};
