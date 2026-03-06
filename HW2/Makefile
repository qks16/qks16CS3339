a.out: source.cpp utils.o
	g++ -Wall -O3 source.cpp utils.o

utils.o: utils.h utils.cpp
	g++ -Wall -c -O3 utils.cpp

clean:
	rm -f a.out
	rm -f utils.o