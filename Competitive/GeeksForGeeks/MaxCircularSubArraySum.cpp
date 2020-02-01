/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Input:
First line of input contains a single integer T which denotes the number of test cases. First line of each test case contains a single integer N which denotes the total number of elements. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
For each test case print the maximum sum obtained by adding the consecutive elements.

Constraints:
1 <= T <= 101
1 <= N <= 106
-106 <= Arr[i] <= 106

Example:
Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
22
23
52

Explanation:
Testcase 1: Starting from last element of the array, i.e, 12, and moving in circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
*/

// #include <iostream>
// using namespace std;

// int main() {
// 	//code
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n;
// 	    cin>>n;
// 	    int a[n];
// 	    int min = 0;
// 	    int sum = 0;
// 	    int sumneg = 0;
// 	    for(int i=0;i<n;i++){
// 	        cin>>a[i];
// 	        sum+=a[i];
// 	    }
// 	    for(int i=0;i<n;i++){
// 	        if(a[i] < 0){
// 	            int j=i;
// 	            sumneg = 0;
// 	            while(j<n && a[j]<0){
// 	                sumneg += a[j];
// 	                //cout<<a[j]<<" ";
// 	                ++j;
// 	            }
// 	            if(j == n && a[0]<0){
// 	                sumneg += a[0];
// 	               // while(a[j] < 0){
// 	               //     sumneg += a[j];
// 	               //     ++j;
// 	               // }
// 	            }
// 	            //cout<<sumneg<<endl;
// 	            i=j-1;
// 	            if(sumneg < min){
// 	                min = sumneg;
// 	            }
// 	        }
// 	    }
// 	    //cout<<sum<<endl;
// 	    cout<<(sum + (min*-1))<<endl;
// 	}
// 	return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int maxcircularsubarray(int arr[],int n)
{   int i;
    int maxintotal=arr[0];
    int maxcurr=arr[0];
    int minintotal=arr[0];
    int mincurr=arr[0];
    int sum=arr[0];
    for(i=1;i<n;i++)
    {
        if(maxcurr+arr[i]>arr[i])
        {
            maxcurr=maxcurr+arr[i];
        }
        else
        {
            maxcurr=arr[i];
        }
        maxintotal=max(maxintotal,maxcurr);
        if(mincurr+arr[i]<arr[i])
        {
            mincurr=mincurr+arr[i];
        }
        else
        {
            mincurr=arr[i];
        }
        minintotal=min(minintotal,mincurr);
        sum=sum+arr[i];
        
    }
    if(minintotal==sum)
    return maxintotal;
    else
    return max(sum-minintotal,maxintotal);
}
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,i;
         cin>>n;
         int arr[n];
         for(i=0;i<n;i++)
         {
             cin>>arr[i];
         }
         cout<<maxcircularsubarray(arr,n)<<endl;
     }
	return 0;
}
