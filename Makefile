all: clean server client

server:
	gcc client-server.h Server.c -o Server

client: 
	gcc client-server.h Client.c -o Client

clean: 
	rm -rf *.o
	rm -rf Server
	rm -rf Client

launch:
	./Server 10103 &
	./Client 10103 &


