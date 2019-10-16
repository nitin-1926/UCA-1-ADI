#include<stdio.h>

int missing(int arr[], int N){
    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] != mid + 1 &&arr[mid - 1] == mid)
            return mid + 1;
        if (arr[mid] != mid + 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main(){
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Misisng Element is: %d",missing(arr,n));
}
