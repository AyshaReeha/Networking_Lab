#include <stdio.h>
#include <stdlib.h>

void leaky(int n,int packet[],int max,int out){
        int i;
        int bucket=0;
        for(i=0;i<n;i++){
                printf("incoming packet %d\n",packet[i]);
                if(bucket+packet[i]<=max){
                        bucket+=packet[i];
                        printf("added packet %d ,now bucket size %d\n",packet[i],bucket);
                }
                else{
                        printf("packet dropped ,overflow...\n");
                }
                if(bucket>out){
                        bucket-=out;
                        printf("transmitted %d remaiing %d \n",out,bucket);
                }
                else{
                        bucket=0;
                        printf("transmitted %d and bucket empty \n",out);
                }}
                while(bucket!=0){
                        if(bucket>out){
                        bucket-=out;
                        printf("transmitted %d remaiing %d \n",out,bucket);
                }
                else{
                        bucket=0;
                        printf("transmitted %d and bucket empty \n",out);

        }


}
}
void main(){
        int packet[10],m,max,out;
        printf("enter number of packets ");
        scanf("%d",&m);
        printf("enter the packets");
        int i;
        for(i=0;i<m;i++){
                scanf("%d",&packet[i]);
        }
        printf("enter the max size of bucket ");
        scanf("%d",&max);
        printf("enter out floe ");
        scanf("%d",&out);

        leaky(m,packet,max,out);
}




