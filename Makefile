all: test

test: test.cc kontroler.cc kontroler.h sejf.cc sejf.h
	g++ -Wall -W -O2 -std=c++0x test.cc kontroler.cc kontroler.h sejf.cc sejf.h -o test

clean:
	rm -f *.o *.gch test
