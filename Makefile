all: test

test: test.cc kontroler.cc kontroler.h sejf.cc sejf.h
	g++ -std=c++11 test.cc kontroler.cc kontroler.h sejf.cc sejf.h -o test

clean:
		rm -f *.o *.gch test
