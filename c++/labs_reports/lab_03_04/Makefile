all: lab_03_04

lab_03_04: main.o cone.o ctwo.o cthree.o cfour.o
	g++ main.o cone.o ctwo.o cthree.o cfour.o -o lab_03_04

main.o: main.cpp
	g++ -c main.cpp

cone.o: cone.cpp
	g++ -c cone.cpp

ctwo.o: ctwo.cpp
	g++ -c ctwo.cpp

cthree.o: cthree.cpp
	g++ -c cthree.cpp

cfour.o: cfour.cpp
	g++ -c cfour.cpp

clean:
	rm *.o lab_03_04

