a.out: source.cpp utils.o
	g++ source.cpp utils.o

utils.o: utils.h utils.cpp
	g++ -c utils.cpp

clean:
	rm -f a.out
	rm -f utils.o