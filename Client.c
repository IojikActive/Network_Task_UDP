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
	//caddr.sin_addr.s_addr= (uint32_t)3158602561; //INADDR_ANY
	caddr.sin_addr.s_addr= inet_addr(argv[2]); //INADDR_ANY
	caddr.sin_port = atoi(argv[1]);
	printf("IP test int: %zu  \n", (uint32_t)caddr.sin_addr.s_addr);
	//inet_aton(htonl("127.0.0.2"),&caddr.sin_addr.s_addr);
	//printf("%s \n", inet_ntoa(caddr.sin_addr));
	printf("IP Client: %i.%i.%i.%i \n",
	((uint32_t)caddr.sin_addr.s_addr/16777216)%256,
	((uint32_t)caddr.sin_addr.s_addr/65536)%256,
	((uint32_t)caddr.sin_addr.s_addr/256)%256,
	((uint32_t)caddr.sin_addr.s_addr%256));
	printf("port %i \n",caddr.sin_port);

	sendto(s,message,sizeof(message),0,(struct sockaddr *) &caddr, sizeof(caddr)); 

	//clock_t clock = clock();

	//while (){


	//}

	close(s);





return 0;
}
