
test_linkedlist: linkedlist
	./linkedlist

linkedlist: linkedlist.o stub_linkedlist.o
	gcc $^ -o $@

clean:
	rm -f linkedlist linkedlist.o
