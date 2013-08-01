
point: stub_point.o point.o
	gcc $^ -o $@

record: stub_record.o record.o
	gcc $^ -o $@

before: stub_record_before.o record.o record_before.o
	gcc $^ -o $@

cdrecord: stub_cdrecord.o cdrecord.o
	gcc $^ -o $@

test_point: point
	./point

test_record: record
	./record

test_before: before
	./before

test_cdrecord: cdrecord
	./cdrecord

clean:
	rm point record before cdrecord
