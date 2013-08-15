
void * linearlist_create(void);

void linearlist_free(void *linearlist);

int linearlist_insert(void *linearlist, int pos, char c);

int linearlist_remove(void *linearlist, int pos);

char linearlist_get(void *linearlist, int pos);

void linearlist_set(void *linearlist, int pos, char c);

int linearlist_count(void *linearlist);


