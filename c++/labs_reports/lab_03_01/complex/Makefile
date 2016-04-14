all: complex

complex: main.o complex.o
	g++ main.o complex.o -o complex

main.o: main.cpp
	g++ -c main.cpp

complex.o: complex.cpp
	g++ -c complex.cpp

clean:
	rm *.o complex
