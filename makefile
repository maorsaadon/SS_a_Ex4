edge.o : edge.c graph.h
	gcc -c -Wall edge.c

node.o : node.c graph.h
	gcc -c -Wall node.c

graph.o : graph.c graph.h
	gcc -c -Wall graph.c

libstacts.a : edge.o node.o graph.o graph.h
	ar rcu libstacts.a edge.o node.o graph.o

main.o : main.c graph.h
	gcc -c -Wall main.c

graph : main.o libstacts.a
	gcc -Wall main.o ./libstacts.a -o graph

.PHONY:clean

clean:
	rm *.o libstacts.a graph

all:graph