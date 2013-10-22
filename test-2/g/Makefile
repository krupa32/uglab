
test_sort: sort
	./sort

sort: sort.c stub_sort.o
	gcc $^ -o $@

test_bstree: bstree
	./bstree

bstree: bstree.cpp stub_bstree.o
	g++ $^ -o $@

clean:
	rm -f sort bstree
