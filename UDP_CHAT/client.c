#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 90
#define PORT 8008
#define SA struct sockaddr
#define SAI struct sockaddr_in

void chat(int sockfd,SAI server){
        char buff[MAX];

        int len=sizeof(server);
        while(1){            //    bzero(buff,sizeof(buff));
              //  read(connfd,buff,sizeof(buff));
                //printf("client %s\n",buff);
                printf("client :");
                bzero(buff,sizeof(buff));
                int n=0;
                while((buff[n++]=getchar())!='\n');
                sendto(sockfd,buff,sizeof(buff),0,(SA*)&server,len);

                 bzero(buff,sizeof(buff));
                recvfrom(sockfd,buff,sizeof(buff),0,(SA*)&server,(socklen_t*)&len);
                printf("server %s\n",buff);
        }
}
void main(){
        int sockfd,connfd;
        int len;
        SAI client,server;

        sockfd=socket(AF_INET,SOCK_DGRAM,0);
        printf("socket cretae \n");

        server.sin_family=AF_INET;
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        server.sin_port=htons(PORT);

        if(connect(sockfd,(SA*)&server,sizeof(server))==0)
        printf("client connected \n");



        chat(sockfd,server);
        close(sockfd);
}


