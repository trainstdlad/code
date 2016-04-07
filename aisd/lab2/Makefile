all: stack

stack: main_stack.o
	g++ main_stack.o -o stack

main_stack.o: main_stack.cpp
	g++ -c main_stack.cpp

clean:
	rm *.o stack 
