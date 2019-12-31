// Given an array of integers A. A subsequence of A is called Bitonic if it is first increasing then decreasing.

// Input:
// The first line contains an integer T denoting the no of test cases. Each test case consist of two lines. The first line contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A[].

// Output:
// For each test case in a new line print the max sum bitonic subsequence.

// Constraints:
// 1<=T<=100
// 1<=N<=50
// 1<=A[]<=100

// Example:
// Input:
// 2
// 6
// 80 60 30 40 20 10
// 9
// 1 15 51 45 33 100 12 18 9

// Output:
// 210
// 194

// Explanation:
// Testcase2:
// Input : A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9}
// Output : 194
//  Bi-tonic Sub-sequence are :
// {1, 51, 9}
// {1, 50, 100, 18, 9}
// {1, 15, 51, 100, 18, 9}
// {1, 15, 45, 100, 12, 9}
// {1, 15, 45, 100, 18, 9} .. so on           
// Maximum sum Bi-tonic sub-sequence is 1 + 15 + 51 + 100 + 18 + 9 = 194  

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int arr[n],arr1[n],arr2[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr1[i]=arr[i];
            arr2[i]=arr[i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && arr1[j]+arr[i]>arr1[i])
                {
                    arr1[i]=arr1[j]+arr[i];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(arr[i]>arr[j] && arr2[j]+arr[i] > arr2[i])
                {
                    arr2[i]=arr2[j]+arr[i];
                }
            }
        }
        
        int maxval=-1;
        for(int i=0;i<n;i++)
        {
            maxval=max(maxval,arr1[i]+arr2[i]-arr[i]);
            
        }
        cout<<maxval<<endl;
        }
    return 0;
}