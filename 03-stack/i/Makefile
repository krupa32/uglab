
ex1: stub1.o ex1.o
	gcc stub1.o ex1.o -o ex1

stack: stub_stack.o stack.o
	gcc stub_stack.o stack.o -o stack

reverse: stub_reverse.o stack.o reverse.o
	gcc stub_reverse.o stack.o reverse.o -o reverse

test_ex1: ex1
	./ex1

test_stack: stack
	./stack

test_reverse: reverse
	./reverse

clean:
	rm -f ex1.o ex1 stack.o stack reverse.o reverse
