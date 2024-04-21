#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int n1,int n2){
    if(n1>n2){
        return n1;
    }
    return n2;
}
int LCS(char* a,char*b,int m,int n,char* result){
    int l[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                l[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                l[i][j]=l[i-1][j-1]+1;
            }
            else{
                l[i][j]=max(l[i][j-1],l[i-1][j]);
            }
        }
    }
    int index=l[m][n];
    result[index]='\0';
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            result[index-1]=a[i-1];
            i--;
            j--;
            index--;
        }
        else if(l[i-1][j]>l[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return l[m][n];
}
int main(){
    char a[100];
    char b[100];
    printf("enter the strings : \n");
    scanf("%s",&a);
    scanf("%s",&b);
    int m = strlen(a);
    int n = strlen(b);
    char result[m+n];
    int length = LCS(a,b,m,n,result);
    printf("length of LCS : %d\n",length);
    printf("LCS : %s\n",result);
    return 0;
}