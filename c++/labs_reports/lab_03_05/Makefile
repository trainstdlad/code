all: complex stack

stack: main_stack.o
	g++ main_stack.o -o stack

main_stack.o: main_stack.cpp
	g++ -c main_stack.cpp

complex: main_complex.o
	g++ main_complex.o -o complex

main_complex.o: main_complex.cpp
	g++ -c main_complex.cpp

clean:
	rm *.o stack complex
