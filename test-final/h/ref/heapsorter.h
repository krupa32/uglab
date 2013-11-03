#include "sorter.h"

class HeapSorter : public Sorter
{
public:
	HeapSorter();
	void sort(char **arr, int size);
};
