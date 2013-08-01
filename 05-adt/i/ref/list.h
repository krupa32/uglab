void * list_create(void);
void list_free(void *list);
int list_insert(void *list, int pos, char c);
void list_remove(void *list, int pos);
char list_get(void *list, int pos);
void list_set(void *list, int pos, char c);
int list_count(void *list);
