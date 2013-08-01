#include<stdio.h>
#include<malloc.h>
#define MAX_NAME 25
struct cdrecord
{
        int roll_num;
        char name[MAX_NAME];
        int mark;

        struct cdrecord *next;
	struct cdrecord *prev;
};

extern void cdlist_init(struct cdrecord *l);
extern struct cdrecord *cdrec_alloc(int roll_num, const char *name, int mark);
extern void cdrec_add_head(struct cdrecord *l, struct cdrecord *rec);
extern void cdrec_add_tail(struct cdrecord *l, struct cdrecord *rec);
extern struct cdrecord *cdrec_find(struct cdrecord *l, int roll_num);
extern void cdrec_remove(struct cdrecord *l, struct cdrecord *rec);

int main()
{
	struct cdrecord l, *rec;
	
//	&l = NULL;
//	rec = NULL;	

	printf("\n testing cdlist_init...");
	cdlist_init(&l);
	if( &l == l.next && &l == l.prev )
//	if(&l==l.prev)
		printf("[ok]");
	else
		goto fail;

	printf("\n testing cdrec_alloc...");
	rec = cdrec_alloc(101,"Abi",70);
	if(rec == NULL)
		goto fail;
	else 
		printf("[ok]");
	
	printf("\n testing cdrec_add_head [whi&le adding first record]...");
	cdrec_add_head(&l, rec);	
	if(l.next != rec || l.prev != rec || rec->next != &l || rec->prev != &l)
		goto fail;
	else
		printf("[ok]");

	printf("\n testing cdrec_remove for existing 1 record...");
	cdrec_remove(&l, rec);
	if( &l == l.next && &l == l.prev )
		printf("[ok]");
	else
		goto fail;

	printf("\n testing cdrec_add_tail [whi&le adding first record]...");
	cdrec_add_tail(&l, rec);	
	if(l.next != rec || l.prev != rec || rec->next != &l || rec->prev != &l)
		goto fail;
	else
		printf("[ok]");

	printf("\n adding severa&l records to head...");
	rec = cdrec_alloc(102,"Anu",80);
	cdrec_add_head(&l, rec);
	
	rec = cdrec_alloc(103,"Ba&lu",85);
	cdrec_add_head(&l, rec);

	if(l.next != rec || rec->prev != &l)
		goto fail;
	printf("[ok]");

	printf("\n adding severa&l records to tail...");
	rec = cdrec_alloc(104,"Chandran",90);
	cdrec_add_tail(&l, rec);

	rec = cdrec_alloc(105,"kiti",95);
	cdrec_add_tail(&l, rec);
	
	if(l.prev != rec || rec->next != &l)
		goto fail;
	printf("[ok]");
	
	printf("\n testing rec_find\n\t(1) record is in the midd&le of the &list...");
	
	rec = cdrec_find(&l, 102);
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
	
	printf("\n\t(2) record is at the end of the &list...");
	rec =  cdrec_find(&l, 105);
        if(rec == NULL) 
        {       
                printf("\n error: record is not identified\n");
                goto fail;
        }       
        else if(rec->roll_num != 105)
        {       
                printf("\n error: identified a wrong record\n");
                goto fail;
	}
        else 
                printf("[ok]");

        rec = NULL;
        printf("\n\t(3) record is not in the &list...");
        rec =  cdrec_find(&l, 1);
	if(rec != NULL)
		goto fail;
	else
		printf("[ok]");
	
	printf("\n testing rec_remove for first record...");
	rec = cdrec_find(&l, 103);
	cdrec_remove(&l, rec);
	if( cdrec_find(&l, 103) != NULL)
		goto fail;
	else
		printf("[ok]");
	printf("\n testing for remova&l of &last record...");
	rec = cdrec_find(&l, 105);
	cdrec_remove(&l, rec);
	if( cdrec_find(&l, 105) != NULL)	
		goto fail;
	else printf("[ok]\n");
	
	return 0;

fail:
	printf("[failed]\n");
	return 0;
}
