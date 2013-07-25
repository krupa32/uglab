
point: stub_point.o point.o
	gcc $^ -o $@

record: stub_record.o record.o
	gcc $^ -o $@

rotate: stub_rotate.o record.o record_rotate.o
	gcc $^ -o $@

cache: stub_cache.o record.o record_cache.o
	gcc $^ -o $@

test_point: point
	./point

test_record: record
	./record

test_rotate: rotate
	./rotate

test_cache: cache
	./cache

clean:
	rm point record rotate cache
