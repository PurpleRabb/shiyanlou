CC = g++
CLFAGS = -std=c++11

all: ClientMain.cpp ServerMain.cpp Server.o Client.o
	$(CC) $(CFLAGS) ServerMain.cpp Server.o -o chatserver
	$(CC) $(CFLAGS) ClientMain.cpp Client.o -o chatclient

Server.o : Server.cpp Server.h Common.h
	$(CC) $(CFLAGS) -c Server.cpp

Client.o : Client.cpp Client.h Common.h
	$(CC) $(CFLAGS) -c Client.cpp

.PHONY: clean
clean:
	rm -r *.o chatserver chatclient
