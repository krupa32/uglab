
test_qsort: qsort
	./qsort

qsort: qsort.c stub_qsort.o
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
	rm -f qsort heap heapsort
