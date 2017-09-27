CC = g++
DEBUG = -g3 -ggdb
CFLAGS = -Wall -w --std=c++14 $(DEBUG) 
LFLAGS = -Wall -o 

all: e1 e2 stack e4

e1: e1.cpp
	$(CC) -o e1 e1.cpp

e2: e2.cpp
	$(CC) -o e2 e2.cpp

stack: stack.cpp
	$(CC) $(CFLAGS) -o stack4 stack.cpp

e4: e4.cpp
	$(CC) -o e4 e4.cpp

clean:
	\rm *.o e1 e2 stack e4
