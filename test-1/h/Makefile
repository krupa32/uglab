
test_list: list
	./list

list: list.o stub_list.o
	g++ $^ -o $@

test_stack: stack
	./stack

stack: stack.o stub_stack.o list.o
	g++ $^ -o $@

clean:
	rm -f stack list stack.o list.o
