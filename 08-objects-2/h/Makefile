
test_dbllist: dbllist
	./dbllist

dbllist: stub_dbllist.o dbllist.o node.o charnode.o
	g++ $^ -o $@

test_dblqueue: dblqueue
	./dblqueue

dblqueue: stub_queue.o dblqueue.o dbllist.o node.o charnode.o
	g++ $^ -o $@
	
clean:
	rm -f dbllist dbllist.o node.o charnode.o dblqueue dblqueue.o 
