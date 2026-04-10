cache: cmd_line.cpp cache_class.o
	g++ -Wall -O3 cmd_line.cpp cache_class.o -o cache

cache_class.o: cache_class.cpp
	g++ -Wall -c -O3 cache_class.cpp

file_process: fileio.cpp
	g++ -Wall -O3 fileio.cpp -o file_process

clean:
	rm -f cache
	rm -f cache_class.o
	rm -f file_process