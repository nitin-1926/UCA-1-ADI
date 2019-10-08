#include<stdlib.h> 
#include<stdio.h> 

void merge(int arr[], int l, int m, int r) 
{ 
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
  
    while (i < n1 && j < n2) 
    { 
        if (Left[i] <= Right[j]) 
        { 
            arr[k] = Left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 

        int m = left+(right-left)/2; 

        mergeSort(arr, left, m); 
        mergeSort(arr, m+1, right); 
  
        merge(arr, left, m, right); 
    } 
} 

void printArray(int A[], int size) 
{ 
    for (int i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7, 6, 98, 4, 5, 2, 27, 57, 58, 38, 97}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr,size); 
  
    mergeSort(arr, 0, size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr,size); 
    return 0; 
}