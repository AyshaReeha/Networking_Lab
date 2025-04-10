#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 90
#define PORT 8000
#define SA struct sockaddr
#define SAI struct sockaddr_in
void chat(int sockfd){
                char buff[MAX];
                while(1){
                        printf("\nclient");
                        bzero(buff,sizeof(buff));
                        int n=0;
                        while((buff[n++]=getchar())!='\n');
                        write(sockfd,buff,sizeof(buff));

                         bzero(buff,sizeof(buff));
                        read(sockfd,buff,sizeof(buff));
                        printf("\n server:%s ",buff);
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
        chat(sockfd);
        close(sockfd);
}



