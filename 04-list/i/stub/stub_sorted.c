#include<stdio.h>
#include<malloc.h>
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
extern void rec_add_sorted(struct list *l, struct record *p);
extern void rec_reverse(struct list *l);

int main()
{
	struct record *rec;
	struct list l = { NULL };

	printf("\n adding first record...");
	rec = rec_alloc(11,"Abi",50);
	rec_add_sorted(&l, rec);
	printf("[ok]");
	
	printf("\n testing rec_add_sorted...");
	rec = rec_alloc(15,"Balu",70);
	rec_add_sorted(&l, rec);
	printf("\n\t(1) simple case...");
	if(l.head->next->roll_num !=15)
		goto fail;
	else printf("[ok]");
	
	printf("\n\t(2) inserting in the middle of the list...");
	rec = rec_alloc(13,"Geetha",60);
	rec_add_sorted(&l,rec);
	if(l.head->roll_num != 11 || l.head->next->roll_num != 13)
		goto fail;
	else
		printf("[ok]");
	
	printf("\n testing rec_reverse...");
	rec_reverse(&l);
	if( l.head->roll_num !=15 || l.head->next->roll_num != 13 || l.head->next->next->roll_num !=11)
		goto fail;
	else	printf("[ok]\n");


	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
