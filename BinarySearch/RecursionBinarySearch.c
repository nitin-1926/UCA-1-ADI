#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x) { 
    if (r >= l){ 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x) return mid; 
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
    } 
    return -1; 
} 
int main(){ 
    int arr[] = {2, 3, 4, 10, 40,50,38,74,63,28,834,82,84,1,8,19}; 
    int n = sizeof(arr)/ sizeof(arr[0]); 
    int x = 10; 
    int result = binarySearch(arr, 0, n-1, x); 
    if(result == -1){
        printf("Element Not Found");
    } 
    else{
        printf("Element Found At Index %d",result);
    }
    return 0; 
} 
