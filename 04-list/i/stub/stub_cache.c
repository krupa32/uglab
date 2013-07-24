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

extern void rec_cache_init(struct list *cache, int num_records);
extern struct record *rec_alloc_from_cache(struct list *cache, 
		int roll_num, const char *name, int mark);
extern void rec_free_to_cache(struct list *cache, struct record *p);

int count(struct list *l)
{
  	int cnt=0;
	struct record *p = l->head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}
int main()
{
	struct record *rec,*rec1,*rec2,*rec3;
	struct list cache;

	printf("\n testing rec_cache_init...");
	rec_cache_init(&cache, 3);
	if( cache.head == NULL )
	{
		printf("[cache not created]...");
		goto fail;
	}
	if(count(&cache)!=3)
	{	printf("[not enough records are created]...");
		goto fail;
	}
		printf("[ok]");
	
	// head = rec_cache_init(10);
	
	printf("\n testing rec_alloc_from_cache...\n\t(1)cache has records...");
	rec = rec_alloc_from_cache(&cache,11,"Anil",70);
	if(rec == NULL)
	{
		printf("[the record is not properly allocated]...");
		goto fail;
	}
	if(count(&cache) != 2)
	{
		printf("[the record is not removed from the cache]...");
		goto fail;
	}
	printf("[ok]");
	rec2 = rec_alloc_from_cache(&cache,12,"Deva",80);
	rec3 = rec_alloc_from_cache(&cache,13,"Priya",90);
	printf("\n\t(2)cache has no more records...");
	rec = rec_alloc_from_cache(&cache,14,"nn",50);
	if(rec != NULL)
		goto fail;
	else	printf("[ok]");
	
	
	printf("\n testing rec_free_to_cache...");
	rec_free_to_cache(&cache, rec3);
	if(cache.head == NULL)
		goto fail;
	else	printf("[ok]");
	 
	return 0;

fail: 
	printf("[failed]\n");
	return -1;
}
