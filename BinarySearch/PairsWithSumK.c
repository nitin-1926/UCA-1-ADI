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

int countpair(int ar[],int s,int e,int sum){
    int c=0;
    while(s<e){
        int total=ar[s]+ar[e];
        if(total==sum){
           if(ar[s]==ar[s+1]){
               int temp=0;
               while(temp<e){
                   if(ar[temp]+ar[e]==sum)
                    c++;
                   temp++;
               }
               e--;
           }
           else{
            c++;
             s++;
           }
        }
        else if(total<sum)
            s++;
        else
            e--;
    }
    return c;
}
int main(){
    printf("Enter the number of elements");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sum;
    printf("Enter the sum you want to check");
    scanf("%d",&sum);
    mergeSort(arr,0,n-1);
    printf("\nNumber of pairs with the given sum are: %d\n",countpair(arr,0,n-1,sum));
}