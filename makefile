MazeSolver: main.o Finder.o Solver.o
	g++ -std=c++11 -g -Wall main.o Finder.o Solver.o -o MazeSolver
main.o: main.cpp Finder.h
	g++ -std=c++11 -g -Wall -c main.cpp
Finder.o: Finder.h Finder.cpp
	g++ -std=c++11 -g -Wall -c Finder.cpp
Solver.o: Solver.h Solver.cpp
	g++ -std=c++11 -g -Wall -c Solver.cpp
clean:
	rm *.o MazeSolver
