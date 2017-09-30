CC = g++
DEBUG = -g3 -ggdb
CFLAGS = -Wall -w --std=c++14 $(DEBUG) 
LFLAGS = -Wall -o 

all: e1 e2 stack odd_range

e1: e1.cpp
	$(CC) -o e1 e1.cpp

e2: e2.cpp
	$(CC) -o e2 e2.cpp

stack: stack.cpp stack.tpp
	$(CC) $(CFLAGS) -o stack stack.cpp

odd_range: odd_range.cpp 
	$(CC) $(CFLAGS) -o odd_range odd_range.cpp

clean:
	\rm *.o e1 e2 stack odd_range
