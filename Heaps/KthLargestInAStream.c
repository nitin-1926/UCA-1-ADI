#include<stdio.h>
#include<stdlib.h>

void MinHeapify(int a[],int i,int n)
{
    int left=0;
    int right=0;
    int max=0;
    while(i<=n/2-1)
    {
        left=2*i+1;
        right=2*i+2;
        max=i;
        if(left<n && a[left]<a[max])
            max=left;
        if(right<n && a[right]<a[max])
            max=right;
        if(max!=i)
        {
            a[max]=a[max]^a[i];
            a[i]=a[max]^a[i];
            a[max]=a[max]^a[i];
        }
        else
            break;
        i=max;
    }
}
 
void BuildMinHeap(int a[],int n)
{
    int i=0;
    for(i=n/2-1;i>=0;i--)
        MinHeapify(a,i,n);
}
 
void findKthLargest(int I[],int N,int k)
{
    int i=0;
    int a[k];
    for(i=0;i<N;i++)
    {
        if(i<k-1)
        {
            a[i]=I[i];
        }
        else if(i==k-1)
        {
            a[i]=I[i];
            BuildMinHeap(a,k);
        }
        else
        {
            if(I[i]>a[0])
            {
                a[0]=I[i];
                MinHeapify(a,0,k);
            }
        }
        printf("Kth Largest Element:%d\n",a[0]);
    }
}
int main(){
    int n;
    printf("Enter the size of the stream\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the k for Kth Largest\n");
    int k;
    scanf("%d",&k);
    printf("Enter the elements of the stream\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   findKthLargest(arr,n,k);
   return 0; 
}