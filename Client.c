//https://www.opennet.ru/docs/RUS/socket/socket.html
#include "client-server.h"




int main (int argc,char* argv[]){


	char message[] = "CLIENT: lookup";

	struct sockaddr_in caddr;


	int s = socket(AF_INET,SOCK_DGRAM,0);//создаём сокет
	if(s<0){
		perror("wrong socket");
		printf("bad socket,exit");
		exit(1);
	}

	caddr.sin_family=AF_INET;
	caddr.sin_addr.s_addr = INADDR_ANY;//INADDR_ANY
	caddr.sin_port = atoi(argv[1]);

	
	//printf("%s \n", inet_ntoa(caddr.sin_addr));
	printf("IP Client: %i.%i.%i.%i \n",
	((int)caddr.sin_addr.s_addr/16777216)%256,
	((int)caddr.sin_addr.s_addr/65536)%256,
	((int)caddr.sin_addr.s_addr/256)%256,
	((int)caddr.sin_addr.s_addr%256));
	printf("port%i \n",caddr.sin_port);

	sendto(s,message,sizeof(message),0,(struct sockaddr *) &caddr, sizeof(caddr)); 

	//clock_t clock = clock();

	//while (){


	//}

	close(s);





return 0;
}
