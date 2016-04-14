all: complex

complex: main.o string.o
	g++ main.o string.o -o string

main.o: main.cpp
	g++ -c main.cpp

string.o: string.cpp
	g++ -c string.cpp

clean:
	rm *.o string
