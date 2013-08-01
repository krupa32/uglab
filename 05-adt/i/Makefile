
CFLAGS += -Wall

ex1: stub1.o ex1.o
	gcc $^ -o $@

arraylist: stub_list.o arraylist.o
	gcc $^ -o $@

linkedlist: stub_list.o linkedlist.o 
	gcc $^ -o $@

test_ex1: ex1
	./ex1

test_arraylist: arraylist
	./arraylist

test_linkedlist: linkedlist
	./linkedlist

clean:
	rm -f ex1.o ex1 arraylist.o arraylist linkedlist.o linkedlist
