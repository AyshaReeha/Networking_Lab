                                                            udpserver.c                                                                         #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 90
#define PORT 8008
#define SA struct sockaddr
#define SAI struct sockaddr_in

void chat(int sockfd,SAI client){
        char buff[MAX];
        int len=sizeof(client);
        while(1){
                bzero(buff,sizeof(buff));
                recvfrom(sockfd,buff,sizeof(buff),0,(SA*)&client,(socklen_t*)&len);
                printf("client %s\n",buff);
                bzero(buff,sizeof(buff));
                int n=0;
                printf("server ");
                while((buff[n++]=getchar())!='\n');

                sendto(sockfd,buff,sizeof(buff),0,(SA*)&client,len);        }
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

        if(bind(sockfd,(SA*)&server,sizeof(server))==0)
        printf("socket binded \n");

        if(listen(sockfd,5)==0){
                printf("listening \n");
        }

        len=sizeof(client);
        connfd=accept(sockfd,(SA*)&server,(socklen_t*)&len);
        printf("accepted\n");
        chat(sockfd,client);
        close(sockfd);
        close(connfd);

}