
test_dbllist: dbllist
	./dbllist

dbllist: stub_dbllist.o dbllist.o node.o charnode.o
	g++ $^ -o $@

test_dblvector: dblvector
	./dblvector

dblvector: stub_vector.o dblvector.o dbllist.o node.o charnode.o
	g++ $^ -o $@
	
clean:
	rm -f dbllist dbllist.o node.o charnode.o dblvector dblvector.o
