
test_msort: msort
	./msort

msort: msort.c stub_msort.o
	gcc $^ -o $@

test_heap: heap
	./heap

heap: heap.c stub_heap.o
	gcc $^ -o $@

test_heapsort: heapsort
	./heapsort

heapsort: heap.c stub_heapsort.o
	gcc $^ -o $@

clean:
	rm -f msort heap heapsort
