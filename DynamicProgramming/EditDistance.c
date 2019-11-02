#include<stdio.h>
#include<string.h>

int minimum(int a,int b,int c){
    if(a<b){
        if(a<c){
            return a;
        }
        else
        return c;
    }
    else{
        if(b<c){
            return b;
        }
        else
        return c;
    }
}

int editDistance(char str1[], char str2[]){
    int arr[strlen(str1)+1][strlen(str2)+1];
    for(int i=0;i<=strlen(str1);i++){
        for(int j=0;j<=strlen(str2);j++){
            if(i==0){
                arr[i][j] = j;
            }
            else if(j==0){
                arr[i][j] = i;
            }
            else if(str1[i-1]==str2[j-1]){
                arr[i][j] = arr[i-1][j-1];
            }
            else{
                arr[i][j] = 1+minimum(arr[i-1][j-1],arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[strlen(str1)][strlen(str2)];
}
int main(){
    char str1[20];
    char str2[20];

    scanf("%s",str1);
    scanf("%s",str2);

    printf("%d\n",editDistance(str1,str2));
    return 0;
}