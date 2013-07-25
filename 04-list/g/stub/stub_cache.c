#include<stdio.h>

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
extern void rec_add_and_cache(struct list *l, struct record *p);
extern struct record *rec_find_and_cache(struct list *l, int roll_num);
extern void rec_remove(struct list *l, struct record *p);

int main()
{
	struct list l = { NULL };
	struct record *rec;

	printf("testing rec_alloc...");
	rec = rec_alloc(101,"Abi",70);
	if(rec == NULL)
		goto fail;
	printf("[ok]\n");
	
	printf("testing rec_add_and_cache [while adding first record]...");
	rec_add(&l, rec);
	if(l.head != rec)
		goto fail;
	printf("[ok]\n");
	
	printf("adding several records...");
	rec = rec_alloc(102,"Anu",80);
	rec_add_and_cache(&l, rec);
	if(l.head != rec)
		goto fail;
	rec = rec_alloc(103,"Balu",85);
	rec_add_and_cache(&l, rec);
	if(l.head != rec)
		goto fail;
	rec = rec_alloc(104,"Chandran",90);
	rec_add_and_cache(&l, rec);
	if(l.head != rec)
		goto fail;
	printf("[ok]\n");
	
	printf("testing rec_find_and_cache\n");
	printf("\t(1) record is in the middle of the list...");
	rec = rec_find_and_cache(&l, 102);
	if(rec == NULL) {
		printf("error: record is not identified\n");
		goto fail;
	} else if(rec->roll_num != 102)	{
		printf("error: identified a wrong record\n");
		goto fail;
	} else if (l.head != rec) {
		printf("error: record found, but not cached\n");
		goto fail;
	} else 
		printf("[ok]\n");
	
	printf("\t(2) record is at the end of the list...");
	rec = rec_find_and_cache(&l, 104);
	if(rec == NULL) {
		printf("error: record is not identified\n");
		goto fail;
	} else if(rec->roll_num != 104)	{
		printf("error: identified a wrong record\n");
		goto fail;
	} else if (l.head != rec) {
		printf("error: record found, but not cached\n");
		goto fail;
	} else 
		printf("[ok]\n");
	
        printf("\t(3) record is not in the list...");
        rec = NULL;
        rec =  rec_find_and_cache(&l, 1);
	if(rec != NULL)
		goto fail;
	printf("[ok]\n");
	
	return 0;

fail:
	printf("[failed]\n");
	return 0;
}
