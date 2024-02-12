.PHONY = all clean 

all: my_graph my_Knapsack

my_graph: my_graph.o my_mat.o 
	gcc -Wall -g my_graph.o my_mat.o -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -g -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -g -c my_mat.c

my_Knapsack: my_Knapsack.o
	gcc -Wall -g my_Knapsack.c -o my_Knapsack

my_Knapsack.o: my_Knapsack.c  
	gcc -Wall -g -c my_Knapsack.c


clean:
	rm -f *.o *.a my_graph my_Knapsack