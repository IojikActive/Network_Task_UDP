//https://www.opennet.ru/docs/RUS/socket/socket.html
#include "client-server.h"



int main (int argc,char* argv[]){

	//char* port = argv[1];

	char message[] = "Its me bro!";

	struct sockaddr_in caddr;

	
	int s = socket(AF_INET,SOCK_DGRAM,0);//создаём сокет
	if(s<0){
		perror("wrong socket");
		printf("bad socket,exit");
		exit(1);
	}

	caddr.sin_family=AF_INET;
	caddr.sin_addr.s_addr = INADDR_ANY; //htons("127.0.0.1"); // INADDR_ANY для подключения к любому ип адресу. Использовать на сервере.
	caddr.sin_port = atoi(argv[1]);

	printf("%i \n",caddr.sin_port);

	sendto(s,message,sizeof(message),0,(struct sockaddr *) &caddr, sizeof(caddr)); 

	//connect (s,(struct sockaddr *) &caddr,sizeof(caddr));

	close(s);

	



return 0;
}


