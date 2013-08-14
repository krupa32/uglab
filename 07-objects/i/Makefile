
test_string: string
	./string

string: string.o stub_string.o
	g++ $^ -o $@

test_simplestack: simplestack
	./simplestack

simplestack: simplestack.o stub_simplestack.o
	g++ $^ -o $@

test_arraystack: arraystack
	./arraystack

arraystack: arraystack.o stub_arraystack.o
	g++ $^ -o $@

clean:
	rm -f string string.o simplestack simplestack.o arraystack arraystack.o
