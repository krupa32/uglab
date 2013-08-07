void * queue_create(void);
void queue_free(void *queue);
int queue_insert(void *queue, char c);
int queue_remove(void *queue, char *c);
int queue_empty(void *queue);
