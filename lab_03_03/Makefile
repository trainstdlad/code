all: lab_03_03

lab_03_03: main.o cone.o ctwo.o cthree.o
	g++ main.o cone.o ctwo.o cthree.o -o lab_03_03

main.o: main.cpp
	g++ -c main.cpp

cone.o: cone.cpp
	g++ -c cone.cpp

ctwo.o: ctwo.cpp
	g++ -c ctwo.cpp

cthree.o: cthree.cpp
	g++ -c cthree.cpp

clean:
	rm *.o lab_03_03

