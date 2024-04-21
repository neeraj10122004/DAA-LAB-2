#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void optimal_parentheses(int s[][100],int i,int n){
    if(i==n){
        printf("A%d",i);
    }
    else{
        printf("(");
        optimal_parentheses(s,i,s[i][n]);
        optimal_parentheses(s,s[i][n]+1,n);
        printf(")");
    }
}

void matrix_chain(int* dimensions,int n){
    int s[100][100],kk[100][100];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j){
                s[i][j]=0;
            }
            else if(i<j){
            s[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int q=s[i][k]+s[k+1][j]+dimensions[i-1]*dimensions[k]*dimensions[j];
                if(q<s[i][j]){
                    s[i][j]=q;
                    kk[i][j]=k;
                }
            }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            printf("%d ",kk[i][j]);
        }
        printf("\n");
    }
    optimal_parentheses(kk,1,n);
    printf("\n");
}
int main(){
    int n;
    printf("enter the number of matrices : \n");
    scanf("%d",&n);
    int dimensions[n+1];
    printf("enter the dimensions: \n");
    for(int i=0;i<=n;i++){
        scanf("%d",&dimensions[i]);
    }
    matrix_chain(dimensions,n);
    return 0;
}