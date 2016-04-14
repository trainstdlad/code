all: cone.o ctwo.o main.o
	g++ main.o cone.o ctwo.o -o lab_02

cone.o: cone.cpp
	g++ -c cone.cpp

ctwo.o: ctwo.cpp
	g++ -c ctwo.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab_02

