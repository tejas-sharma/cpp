CC = g++
DEBUG = -g3 -ggdb
CFLAGS = -Wall -w --std=c++14 $(DEBUG) 
LFLAGS = -Wall -o 

all: e1 e2 stack odd_range array_size trapezoid make_unique

e1: e1.cpp
	$(CC) -o e1 e1.cpp

e2: e2.cpp
	$(CC) -o e2 e2.cpp

stack: stack.cpp stack.tpp stack_bool.tpp
	$(CC) $(CFLAGS) -o stack stack.cpp

array_size: array_size.cpp 
	$(CC) $(CFLAGS) -o array_size array_size.cpp

odd_range: odd_range.cpp 
	$(CC) $(CFLAGS) -o odd_range odd_range.cpp

trapezoid: trapezoid.cpp 
	$(CC) $(CFLAGS) -o trapezoid trapezoid.cpp

make_unique: make_unique.cpp 
	$(CC) $(CFLAGS) -o make_unique make_unique.cpp

clean:
	\rm *.o e1 e2 stack odd_range array_size trapezoid make_unique
