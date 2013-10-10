bsearch: bsearch.c stub_search.o
	gcc bsearch.c stub_search.o -o bsearch

sort: sort.c stub_sort.o
	gcc sort.c stub_sort.o -o sort

qsort: qsort.c stub_qsort.o
	gcc qsort.c stub_qsort.o -o qsort


test_bsearch: bsearch
	./bsearch

test_sort: sort
	./sort

test_qsort: qsort
	./qsort


clean:
	rm -f bsearch sort qsort
