// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int a[], int n)
{ 
    int k=0;
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    { if(a[i]>k)
       {
           break;
       }
       int j=i+1;
       int l=n-1;
        while(j<l){
            if(a[i] + a[j] + a[l] == k){
                return true;
            }
            else if(a[i] + a[j] + a[l] > k){
                l--;
            }
            else{
                j++;
            }
        }
    }
    return false;
}
