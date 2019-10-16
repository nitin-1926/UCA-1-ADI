#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x){ 
    while (l <= r){ 
        int m = l + (r-l)/2; 
        if (arr[m] == x) 
            return m; 
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
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
