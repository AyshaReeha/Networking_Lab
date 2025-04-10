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
void chat(int connfd){
                char buff[MAX];
                while(1){
                        bzero(buff,sizeof(buff));
                        read(connfd,buff,sizeof(buff));
                        printf("\n client :%s \n server",buff);

                        bzero(buff,sizeof(buff));
                        int n=0;
                        while((buff[n++]=getchar())!='\n');
                        write(connfd,buff,sizeof(buff));
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

        if((bind(sockfd,(SA*)&server,sizeof(server)))==0){
                printf("\nbinded successfully");
        }

        if(listen(sockfd,5)==0){
                printf("listening");
        }

        len=sizeof(client);
        connfd=accept(sockfd,(SA*)&server,(socklen_t*)&len);
        printf("\naccepted client..");

        chat(connfd);
        close(sockfd);
}
