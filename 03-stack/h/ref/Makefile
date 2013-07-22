
ex1: stub1.o ex1.o
	gcc stub1.o ex1.o -o ex1

stack: stub_stack.o stack.o
	gcc stub_stack.o stack.o -o stack

scan: stub_scan.o stack.o scan.o
	gcc stub_scan.o stack.o scan.o -o scan 

test_ex1: ex1
	./ex1

test_stack: stack
	./stack

test_scan: scan
	./scan

clean:
	rm -f ex1.o ex1 stack.o stack scan.o scan
