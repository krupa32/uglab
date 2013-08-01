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

extern struct record *rec_alloc(int roll_num, const char *name, int mark);
extern void rec_free(struct record *p);
extern void rec_add(struct list *l, struct record *p);
extern struct record *rec_find(struct list *l, int roll_num);
extern void rec_remove(struct list *l, struct record *p);
extern void rec_insert_before(struct list *l, struct record *reference, struct record *rec);

int main()
{
	struct list l = { NULL };
	struct record *rec, *ref;

	l.head = NULL;
	
	printf("\n testing rec_alloc...");
	rec = rec_alloc(101,"Abi",70);
	if(rec == NULL)
		goto fail;
	else 
		printf("[ok]");
	
	printf("\n testing rec_add [while adding first record]...");
	rec_add(&l, rec);
	if(l.head != rec)
		goto fail;
	else
		printf("[ok]");
	
	printf("\n adding several records...");
	rec = rec_alloc(102,"Anu",80);
	rec_add(&l, rec);
	
	ref = rec_alloc(103,"Balu",85);
	rec_add(&l, ref);
	
	rec = rec_alloc(104,"Chandran",90);
	rec_add(&l, rec);
	
	printf("[ok]");
	
	printf("\n testing rec_insert_before with next pointer...");
	rec = rec_alloc(105,"kiti",95);
	rec_insert_before(&l, ref, rec);

	if( rec->next != ref )
		goto fail;
	printf("[ok]");

	printf("\n testing rec_insert_before with rec_find...");
	rec = rec_find(&l, 105);
	if( rec->next != ref )
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return 0;
}
