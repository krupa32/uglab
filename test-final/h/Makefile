
test_stack: stack
	./stack

stack: stack.c stub_stack.o
	gcc $^ -o $@

test_list: list
	./list

list: list.cpp stub_list.o
	g++ $^ -o $@

test_heapsorter: heapsorter
	./heapsorter

heapsorter: heapsorter.cpp stub_heapsorter.o
	g++ $^ -o $@

clean:
	rm -f stack list heapsorter heapsorter.o
