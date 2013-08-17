
test_string: string
	./string

string: string.o stub_string.o
	g++ $^ -o $@

test_simplequeue: simplequeue
	./simplequeue

simplequeue: simplequeue.o stub_simplequeue.o
	g++ $^ -o $@

test_arrayqueue: arrayqueue
	./arrayqueue

arrayqueue: arrayqueue.o stub_arrayqueue.o
	g++ $^ -o $@

clean:
	rm -f string string.o simplequeue simplequeue.o arrayqueue arrayqueue.o
