#include <stdio.h>
#include <stdlib.h>

void  main(){
        int k,i,v,w,r,src,j;
        int flag[90],dist[90],last[90],cost[90][90];
        printf("enter how manu routers :");
        scanf("%d",&r);
        printf("enter cost matrix");
        for(i=0;i<r;i++){
                for(j=0;j<r;j++){
                        scanf("%d",&cost[i][j]);
                }
        }

        int count =0;
        do{
                count=0;
                for(i=0;i<r;i++){
                        for(j=0;j<r;j++){
                                for(k=0;k<r;k++){
                                        if(cost[i][j]>cost[i][k]+cost[k][j]){
                                                cost[i][j]=cost[i][k]+cost[k][j];
                                        count++;
                        }
        }
        }
        }
}while(count!=0);

for(i=0;i<r;i++){
                printf("distance from %d to \n",i+1);
        for(j=0;j<r;j++){
                printf("%d is %d\n",j+1,cost[i][j]);
        }
}
}

