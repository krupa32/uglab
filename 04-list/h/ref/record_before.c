#include "record.h"

void rec_insert_before(struct list *l, struct record *reference, struct record *rec)
{
	struct record *before = l->head;
	struct record *this;
	while (before->next) {
		this = before->next;
		if (this->roll_num == reference->roll_num)
			break;

		before = before->next;
	}

	before->next=rec;
	rec->next=this;
}
