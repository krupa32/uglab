
test_list: list
	./list

list: list.o stub_list.o
	g++ $^ -o $@

test_queue: queue
	./queue

queue: queue.o stub_queue.o list.o
	g++ $^ -o $@

clean:
	rm -f queue list queue.o list.o
