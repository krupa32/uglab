
point: stub_point.o point.o
	gcc $^ -o $@

record: stub_record.o record.o
	gcc $^ -o $@

sorted: stub_sorted.o record.o record_sorted.o
	gcc $^ -o $@

cache: stub_cache.o record.o record_cache.o
	gcc $^ -o $@

test_point: point
	./point

test_record: record
	./record

test_sorted: sorted
	./sorted

test_cache: cache
	./cache

clean:
	rm point record sorted cache
