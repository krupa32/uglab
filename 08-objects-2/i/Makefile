
test_dbllist: dbllist
	./dbllist

dbllist: stub_dbllist.o dbllist.o node.o charnode.o
	g++ $^ -o $@

test_dblstack: dblstack
	./dblstack

dblstack: stub_stack.o dblstack.o dbllist.o node.o charnode.o
	g++ $^ -o $@
	
clean:
	rm -f dbllist dbllist.o node.o charnode.o dblstack dblstack.o 
