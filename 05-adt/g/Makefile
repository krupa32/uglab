
CFLAGS += -Wall

ex1: stub_ex1.o ex1.o
	gcc $^ -o $@

arraystack: stub_stack.o arraystack.o
	gcc $^ -o $@

liststack: stub_stack.o liststack.o 
	gcc $^ -o $@

test_ex1: ex1
	./ex1

test_arraystack: arraystack
	./arraystack

test_liststack: liststack
	./liststack

clean:
	rm -f ex1.o ex1 arraystack.o arraystack liststack.o liststack
