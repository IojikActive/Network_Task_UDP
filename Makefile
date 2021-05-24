all:
	gcc client-server.h Client.c -o Client
	gcc client-server.h Server.c -o Server

server:
	gcc client-server.h Server.c -o Server

client: 
	gcc client-server.h Client.c -o Client


