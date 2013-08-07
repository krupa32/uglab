
CFLAGS += -Wall

ex1: stub1.o ex1.o
	gcc $^ -o $@

arrayqueue: stub_queue.o arrayqueue.o
	gcc $^ -o $@

listqueue: stub_queue.o listqueue.o 
	gcc $^ -o $@

test_ex1: ex1
	./ex1

test_arrayqueue: arrayqueue
	./arrayqueue

test_listqueue: listqueue
	./listqueue

clean:
	rm -f ex1.o ex1 arrayqueue.o arrayqueue listqueue.o listqueue
