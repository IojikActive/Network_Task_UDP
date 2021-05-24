//https://www.opennet.ru/docs/RUS/socket/socket.html

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>

//#include "client-server.h"



int main (int argc,char** argv){

	char* net = argv[1];
	char* port = argv[2];

	char message[] = "Client lookup!";

	struct sockaddr_in caddr;

	
	int s = socket(AF_INET,SOCK_DGRAM,0);//создаём сокет
	if(s<0){
		perror("wrong socket");
		printf("bad socket,exit");
		exit(1);
	}


	caddr.sin_family=AF_INET;
	caddr.sin_addr.s_addr = htons("127.0.0.1"); // INADDR_ANY для подключения к любому ип адресу. Использовать на сервере.
	caddr.sin_port = htonl(argv[2]);

	sendto(s,message,sizeof(message),0,(struct sockaddr *) &caddr, sizeof(ca));

	connect (s,(struct sockaddr *) &caddr,sizeof(caddr));

	close(s);

	



return 0;
}


