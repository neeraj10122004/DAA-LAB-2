#include<stdio.h>
#include<stdlib.h>
int matrix[100][100];
int visited[100];

void DFS(int i,int n){
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(matrix[i][j] && !visited[j]){
            DFS(j,n);
        }
    }
}
int isconnected(int n){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    DFS(0,n);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("enter the number of nodes \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    if(isconnected(n)){
        printf("graph is connected");
    }
    else{
        printf("graph is not connected\n");
    }
    return 0;
}