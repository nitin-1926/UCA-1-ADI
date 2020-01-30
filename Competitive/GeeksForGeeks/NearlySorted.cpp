/*
Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, denoting number of elements in array and at most k positions away from its target position respectively. Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56

*/
#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int low,int high){
    int pivot = a[high];
    int i=(low-1);
    
    for(int j=low;j<=high-1;j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}
void quickSort(int a[],int start,int end){
    if(start < end){
        int pi;
        pi = partition(a,start,end);
        
        quickSort(a,start,pi-1);
        quickSort(a,pi+1,end);
    }
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    quickSort(a,0,n-1);
        print(a,n);
	    cout<<endl;
	}
	return 0;
}
