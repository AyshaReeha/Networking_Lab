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
void writefile(int connfd){
        FILE *fp;
        int i;
        char filename[]="result.txt";
        fp=fopen(filename,"w");
        char data[max],newdata[max];
        while(1){
        int n=recv(connfd,data,max,0);
        if(n<=0){
                break;
        }
        int len=strlen(data);
        for(i=0;data[i]!='\0';i++){
                int temp=data[len-i-1];
                newdata[i]=temp;}
        newdata[i]='\0';
        fprintf(fp,"%s",newdata);
        printf("%s",newdata);
        bzero(data,max);
        }
        fclose(fp);
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

        writefile(connfd);
        close(sockfd);
}

