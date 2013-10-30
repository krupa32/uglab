#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "openhash.h"

OpenHashTable::OpenHashTable(int siz)
{
        size = siz;
	arr = (struct entry **) malloc (size * sizeof(*arr));
	memset(arr, 0, size * sizeof(*arr));
}


int OpenHashTable::insert(struct entry *e)
{
	int i, slot;
	struct entry *temp;

	slot = (e->key * e->key) % size;

	temp = (struct entry*) malloc(sizeof(struct entry));
	memcpy(temp, e, sizeof(*e));

	temp->next = arr[slot];
	arr[slot] = temp;

        return 1;
}

int OpenHashTable::search(int key, int *val, int *nops)
{
        int i, slot;
	struct entry *temp = NULL;

        *nops = 0;
        *val = 0;

         slot = (key * key) % size;
         temp = arr[slot];

         while (temp) {

		(*nops)++;

		if (temp->key == key)
			break;
		temp = temp->next;
	}

        if(temp != NULL)
	     *val = temp->val;
                       
        return (temp != NULL);
}
