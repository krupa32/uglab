
test_stack: stack
	./stack

stack: stack.c stub_stack.o
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
	rm -f stack bstree heap
