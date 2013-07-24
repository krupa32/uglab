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

int main()
{
	struct list l = { NULL };
	struct record *rec;

	l.head = NULL;
	
	printf("\n testing rec_alloc...");
	rec = rec_alloc(101,"Abi",70);
	if(rec == NULL)
		goto fail;
	else 
		printf("[ok]");
	
	rec_add(&l, rec);
	printf("\n testing rec_add [while adding first record]...");
	if(l.head != rec)
		goto fail;
	else
		printf("[ok]");
	
	printf("\n adding several records...");
	rec = rec_alloc(102,"Anu",80);
	rec_add(&l, rec);
	
	rec = rec_alloc(103,"Balu",85);
	rec_add(&l, rec);
	
	rec = rec_alloc(104,"Chandran",90);
	rec_add(&l, rec);
	
	printf("[ok]");
	
	printf("\n testing rec_find\n\t(1) record is in the middle of the list...");
	
	rec = rec_find(&l, 102);
	if(rec == NULL) 
	{
		printf("\n error: record is not identified\n");
		goto fail;
	}
	else if(rec->roll_num != 102)
	{
		printf("\n error: identified a wrong record\n");
		goto fail;
	}
	else 
		printf("[ok]");
	
	printf("\n\t(2) record is at the end of the list...");
	rec =  rec_find(&l, 104);
        if(rec == NULL) 
        {       
                printf("\n error: record is not identified\n");
                goto fail;
        }       
        else if(rec->roll_num != 104)
        {       
                printf("\n error: identified a wrong record\n");
                goto fail;
	}
        else 
                printf("[ok]");

        rec = NULL;
        printf("\n\t(3) record is not in the list...");
        rec =  rec_find(&l, 1);
	if(rec != NULL)
		goto fail;
	else
		printf("[ok]");
	
	printf("\n testing rec_remove for first record...");
	rec = rec_find(&l, 101);
	rec_remove(&l, rec);
	if( rec_find(&l, 101) != NULL)
		goto fail;
	else
		printf("[ok]");
	printf("\n testing for removal of last record...");
	rec = rec_find(&l, 104);
	rec_remove(&l, rec);
	if( rec_find(&l, 104) != NULL)	
		goto fail;
	else printf("[ok]");
	
	return 0;

fail:
	printf("[failed]\n");
	return 0;
}
