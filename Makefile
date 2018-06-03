all: run

run: main.o DFS.o BFS.o
	gcc main.o BFS.o DFS.o
main.o: main.c
	gcc -c main.c
DFS.o: DFS.c
	gcc -c DFS.c
BFS.o: BFS.c
	gcc -c BFS.c
clean:
	rm *o run