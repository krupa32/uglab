
test_string: string
	./string

string: string.o stub_string.o
	g++ $^ -o $@

test_simplelist: simplelist
	./simplelist

simplelist: simplelist.o stub_simplelist.o
	g++ $^ -o $@

test_arraylist: arraylist
	./arraylist

arraylist: arraylist.o stub_arraylist.o
	g++ $^ -o $@

clean:
	rm -f string string.o simplelist simplelist.o arraylist arraylist.o
