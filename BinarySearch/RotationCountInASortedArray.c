#include<stdio.h>

int rotation(int arr[],int n){
    int min1=arr[0],index=0;
    for(int i=1;i<n;i++){
        if(min1>arr[i]){
            min1=arr[i];
            index=i;
        }
    }
    return index;
}
int main(){
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the number of rotations\n");
    int k;
    scanf("%d",&k);
    printf("%d ",rotation(arr,k));
}