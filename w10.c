#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int main(){
    int n;
    printf("number of nodes\n");
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    bool selected[n];
    for(int i=0;i<n;i++){
        selected[i]=false;
    }
    int t=0;
    selected[0]=true;
    while(t<n-1){
        int min=INT_MAX;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(selected[i] && !selected[j] && matrix[i][j]){
                    if(matrix[i][j]<min){
                    min=matrix[i][j];
                    x=i;
                    y=j;
                    }
                }
            }
        }
        printf("%d - %d\n",x,y);
        selected[y]=true;
        t++;
    }
    return 0;
}