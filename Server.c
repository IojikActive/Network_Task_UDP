#include "client-server.h"


int main (int argc,char* argv[]){


        int port = (int)*argv[1];
        struct sockaddr_in saddr;

        //printf("Socket get ready!!\n");

        int s = socket(AF_INET,SOCK_DGRAM,0);
        if(s<0){
            perror("wrong socket \n");
            printf("Bad socket,exit \n");
            exit(1);
        }
        //printf("Socket is ok\n");

        saddr.sin_family = AF_INET;
        saddr.sin_addr.s_addr = INADDR_ANY;
        saddr.sin_port = atoi(argv[1]); // htons 

    
        
        printf("IP Server: %i.%i.%i.%i \n",
	((int)saddr.sin_addr.s_addr/16777216)%256,
	((int)saddr.sin_addr.s_addr/65536)%256,
	((int)saddr.sin_addr.s_addr/256)%256,
	((int)saddr.sin_addr.s_addr%256));
    printf("Port: %i \n",saddr.sin_port);


      //  printf("DEBUG: BEFORE bind\n");
        if(bind(s, (struct sockaddr *) &saddr, sizeof(saddr)) < 0){
            perror("Wrong bind");
            printf("Bad bind,exit");
            exit(2);
        }

        printf("Bind ok\n");

        int bytes_read;
        int buf[1024];
        int num=0;


        printf("Waiting message\n");

        while(1){
            bytes_read = recvfrom(s,buf,1024,0,NULL,NULL);
            buf [bytes_read] ='\0';
            printf("%s \n",buf);
            
            //if(buf != NULL){
                

            //}
        }

        close(s);
        shutdown(s,2);
        printf("close\n");
        printf("%i",num);

    return 0;




}
