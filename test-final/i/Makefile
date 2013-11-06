
test_queue: queue
	./queue

queue: queue.c stub_queue.o
	gcc $^ -o $@

test_bstree: bstree
	./bstree

bstree: bstree.cpp stub_bstree.o
	g++ $^ -o $@

test_heap: heap
	./heap

heap: heap.cpp stub_heap.o
	g++ $^ -o $@

clean:
	rm -f queue bstree heap
