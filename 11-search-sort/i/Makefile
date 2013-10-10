bsearch: bsearch.c stub_search.o
	gcc bsearch.c stub_search.o -o bsearch

isort: isort.c stub_isort.o
	gcc isort.c stub_isort.o -o isort

msort: msort.c stub_msort.o
	gcc msort.c stub_msort.o -o msort


test_bsearch: bsearch
	./bsearch

test_isort: isort
	./isort

test_msort: msort
	./msort


clean:
	rm -f bsearch isort msort
