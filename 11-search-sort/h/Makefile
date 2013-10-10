search: search.c stub_search.o
	gcc search.c stub_search.o -o search

sort: sort.c stub_sort.o
	gcc sort.c stub_sort.o -o sort

qsort: qsort.c stub_qsort.o
	gcc qsort.c stub_qsort.o -o qsort


test_search: search
	./search

test_sort: sort
	./sort

test_qsort: qsort
	./qsort


clean:
	rm -f search sort qsort