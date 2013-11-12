all: test

test: test.cc kontroler.cc kontroler.h sejf.cc sejf.h
	g++ -std=c++0x test.cc kontroler.cc kontroler.h sejf.cc sejf.h -o test


clean:
	rm -f *.o *.gch test
