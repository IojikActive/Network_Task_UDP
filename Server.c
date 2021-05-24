#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

#include <errno.h>

//#include "client-server.h"
//49002 port


int main (int argc,char* argv[]){


    char* net = argv[1];
    char* port = argv[2];

    struct sockaddr_in saddr;

    

    printf("Socket get ready!!");

    int s = socket(AF_INET,SOCK_DGRAM,0);
    if(s<0){
        perror("wrong socket");
        printf("Bad socket,exit");
        exit(1);
    }
    printf("Socket ok");
	
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(argv[2]); // htons

    printf("DEBUG: BEFORE bind");
    if(bind(s, (struct sockaddr *) &saddr, sizeof(saddr)) < 0){
        perror("Wrong bind");
        printf("Bad bind,exit");
        exit(2);
    }

    printf("Bind ok");

    int bytes_read;
    int buf[1024];
    int num=0;


    printf("DEBUG: BEFORE WHILE");

   while(num<100){
        bytes_read = recvfrom(s,buf,1024,0,NULL,NULL);
        buf [bytes_read] ='\0';
        printf(buf,'\n');
        printf("wait...");
        num++;
    }

    close(s);
    shutdown(s,2);
    printf("close");

return 0;


}

