#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define max 90
#define PORT 8800
#define SA struct sockaddr
#define SAI struct sockaddr_in
void sendfile(int sockfd){
 FILE *fp;
        char filename[90];
        printf("enter filename ");
        scanf("%s",filename);
        fp=fopen(filename,"r");
        char data[max];
        while(fgets(data,max,fp)!=NULL){
                send(sockfd,data,sizeof(data),0);
                bzero(data,sizeof(data));
        }
}
void main(){
        int sockfd,connfd,len;
        SAI client,server;

        sockfd=socket(AF_INET,SOCK_STREAM,0);
        printf("socket created successfully ");

        server.sin_family=AF_INET;
        server.sin_addr.s_addr=htonl(INADDR_ANY);
        server.sin_port=htons(PORT);

        if((connect(sockfd,(SA*)&server,sizeof(server)))==0){
                printf("\nconnected successfully");
        }

        sendfile(sockfd);
        close(sockfd);
}











