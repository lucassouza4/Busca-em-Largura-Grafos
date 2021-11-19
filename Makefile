all: principal.o BFS.o
	g++ -o programa principal.o BFS.o

run:
	.\programa.exe

principal.o: principal.cpp
	g++ principal.cpp -c
 
BFS.o: BFS.cpp
	g++ BFS.cpp -c