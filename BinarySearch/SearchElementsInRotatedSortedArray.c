#include<stdio.h>
#include<math.h>
int search(int arr[],int s,int e,int k){
    int mid;
    while(s<=e){
        mid=(s+e)/2.0;
        if(arr[mid]==k)
            return 1;
        else if(arr[e]>k&&arr[mid]<k)
            s=mid+1;
        else
            e=mid-1;
    }
    return 0;
}
int main(){
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the number whose first occurence you want\n");
    int k;
    scanf("%d",&k);
    if(search(arr,0,n-1,k))
        printf("Element Found");
    else
        printf("Sadly Element Not Found");
}