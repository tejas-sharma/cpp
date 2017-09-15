OBJS = ignite_dataloader.o
CC = g++
DEBUG = -g3
CFLAGS = -Wall -w --std=c++14 -c $(DEBUG)
LFLAGS = -Wall -o ignite_dataloader -L/home/user/tsharma/bin/ignite-cpp/lib -lignite

ignite_dataloader: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS)
	
ignite_dataloader.o: ignite_dataloader.cpp 
	$(CC) $(CFLAGS) ignite_dataloader.cpp

clean:
	\rm *.o ignite_dataloader
