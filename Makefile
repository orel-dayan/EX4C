CC = gcc
CFLAGS = -Wall -g -fPIC

all: graph

graph:  graph.o main.o 
	$(CC) $(CFLAGS) $^ -o $@


%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm  *.o graph
