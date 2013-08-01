#define MAX_NAME	25

struct cdrecord
{
	int roll_num;
        char name[MAX_NAME];
        int mark;

        struct cdrecord *prev;
        struct cdrecord *next;
};
