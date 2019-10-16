#include<stdio.h>

void merge(int arr[], int l, int m, int r){ 
    int i=0;
    int j=0;
    int k=l; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int Left[n1], Right[n2]; 

    for (i = 0; i < n1; i++) 
        Left[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        Right[j] = arr[m + 1+ j]; 
    i=0;
    j=0;
  
    while (i < n1 && j < n2){ 
        if (Left[i] <= Right[j]){ 
            arr[k] = Left[i]; 
            i++; 
        } 
        else{ 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1){ 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int left, int right){ 
    if (left < right){ 

        int m = left+(right-left)/2; 

        mergeSort(arr, left, m); 
        mergeSort(arr, m+1, right); 
  
        merge(arr, left, m, right); 
    } 
}
int first(int arr[],int s,int e,int k){
    int pos=-1;
    while(s<=e){
        int m=(s+e)/2;
        if(arr[m]==k){
            pos=m;
            e=m-1;
        }
        else if(arr[m]<k){
            s=m+1;
        }
        else
            e=m-1;
    }
    return pos;
}
int main(){
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    printf("Enter the number whose first occurence you want\n");
    int k;
    scanf("%d",&k);
    printf("%d ",first(arr,0,n-1,k));
}