a.out: source.cpp cache.o
	g++ -Wall -O3 source.cpp cache.o

cache.o: cache.h cache.cpp
	g++ -Wall -c -O3 cache.cpp

clean:
	rm -f a.out
	rm -f cache.o