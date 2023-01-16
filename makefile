CC = gcc -c
CFLAGS = -Wall -g
CLIBSA = ar rcs

all: graph libstacts.a

.PHONY:clean

clean:
	rm -rf *.o *.a graph

graph : main.o libstacts.a
	gcc -Wall main.o ./libstacts.a -o graph

libstacts.a : edge.o node.o graph.o header.h
	$(CLIBSA) libstacts.a edge.o node.o graph.o

main.o : main.c header.h
	$(CC) $(CFLAGS) main.c

edge.o : edge.c header.h
	$(CC) $(CFLAGS) edge.c

node.o : node.c header.h
	$(CC) $(CFLAGS) node.c

graph.o : graph.c header.h
	$(CC) $(CFLAGS) graph.c
