#include<stdio.h>

#define LEFT	1
#define RIGHT	2

#define MAX_NAME 25

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


extern struct record *rec_alloc(int roll_num,const char *name,int mark);
extern void rec_rotate(struct list *l, int direction);
extern void rec_add(struct list *l, struct record *rec);

int main()
{
	int i;
	struct record *rec;
	struct list l = { NULL };

	printf("adding records...");
	rec = rec_alloc(11, "Abi", 50);
	rec_add(&l, rec);
	rec = rec_alloc(15, "Balu", 70);
	rec_add(&l, rec);
	rec = rec_alloc(13, "Geetha", 60);
	rec_add(&l,rec);
	printf("[ok]\n");

	printf("testing left rotate...");
	rec_rotate(&l, LEFT);
	if (l.head->roll_num != 15)
		goto fail;
	printf("[ok]\n");

	printf("testing right rotate...\n");
	rec_rotate(&l, RIGHT);
	if (l.head->roll_num != 11)
		goto fail;
	printf("[ok]\n");

	printf("testing left rotate multiple times...");
	for (i = 0; i < 8; i++)
		rec_rotate(&l, LEFT);
	if (l.head->roll_num != 13)
		goto fail;
	printf("[ok]\n");

	printf("testing right rotate multiple times...");
	for (i = 0; i < 8; i++)
		rec_rotate(&l, RIGHT);
	if (l.head->roll_num != 11)
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
