#include <stdio.h>
#include<stdlib.h>

void swapf(float* a,float* b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

void main(){
    int n;
    int size;
    printf("enter size : \n");
    scanf("%d",&n);
    printf("enter the size of sack : \n");
    scanf("%d",&size);
    float profits[n];
    float weights[n];
    float x[n];
    float pw_ratio[n];
    printf("enter profit and weight for each item \n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&profits[i],&weights[i]);
        x[i]=0;
        pw_ratio[i]=profits[i]/weights[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(pw_ratio[j]>pw_ratio[i]){
                swapf(&pw_ratio[i],&pw_ratio[j]);
                swapf(&weights[i],&weights[j]);
                swapf(&profits[i],&profits[i]);
            }
            if(pw_ratio[j]==pw_ratio[i]){
                if(profits[j]>profits[i]){
                    swapf(&pw_ratio[i],&pw_ratio[j]);
                    swapf(&weights[i],&weights[j]);
                    swapf(&profits[i],&profits[i]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(weights[i]<size){
            size-=weights[i];
            x[i]=1;
        }
        else{
            size=0;
            x[i]=size/(int)weights[i];
            break;
        }
    }
    float max_profit=0;
    float max_weight=0;
    for(int i=0;i<n;i++){
        max_weight+=weights[i]*x[i];
        max_profit+=profits[i]*x[i];
    }
    printf("max profit : %f \n",max_profit);
    printf("max weight %f \n",max_weight);
}