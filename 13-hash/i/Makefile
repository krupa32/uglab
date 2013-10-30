
test_hashtable: hashtable
	./hashtable

hashtable: hashtable.cpp stub_hashtable.o
	g++ $^ -o $@

test_openhash: openhash
	./openhash

openhash: openhash.cpp stub_openhash.o
	g++ $^ -o $@

clean:
	rm -f hashtable openhash
