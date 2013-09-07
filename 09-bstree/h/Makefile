test_bstree1: bstree1
	./bstree1

bstree1: stub_bstree1.o bstree.o 
	g++ $^ -o $@

test_bstree2: bstree2
	./bstree2

bstree2: stub_bstree2.o bstree.o 
	g++ $^ -o $@
	
test_bstree3: bstree3
	./bstree3

bstree3: stub_bstree3.o bstree.o 
	g++ $^ -o $@

clean:
	rm -f bstree1 bstree2 bstree3 bstree.o 