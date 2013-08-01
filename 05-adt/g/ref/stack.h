void * stack_create(void);
void stack_free(void *stack);
int stack_push(void *stack, char c);
int stack_pop(void *stack, char *c);
int stack_empty(void *stack);
