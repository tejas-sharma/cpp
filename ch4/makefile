CC = g++
DEBUG = -g3 -ggdb
CFLAGS = -Wall -w --std=c++14 $(DEBUG) 
LFLAGS = -Wall -o 

all: vector_sort map_find

vector_sort: vector_sort.cpp
	$(CC) $(CFLAGS) -o vector_sort vector_sort.cpp

map_find: map_find.cpp
	$(CC) $(CFLAGS) -o map_find map_find.cpp

clean:
	\rm *.o vector_sort map_find
