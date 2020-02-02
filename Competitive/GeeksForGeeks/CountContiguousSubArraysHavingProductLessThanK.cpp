/*
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two integers N & K and the second line contains N space separated array elements.

Output:
For each test case, print the count of required subarrays in new line.

Constraints:
1<=T<=200
1<=N<=105
1<=K<=1015
1<=A[i]<=105

Example:
Input:
2
4 10
1 2 3 4
7 100
1 9 2 8 6 4 3

Output:
7
16
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    long long k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    int i=0;int j;int count=0;long long product=0;
	    while(a[i]>k and i<n)
	    {
	        i++;
	    }
	    if(i<n)
	    {
	       product=a[i];
	    }
	    j=i;
	    while(j<n)
	    {
	        if(product<k)
	        {   
	            // cout<<j<<" "<<i<<" ";
	            count+=j-i+1;
	            product=product*a[j+1];
	            j++;
	           // cout<<count<<" ";
	        }
	        else
	        {
	            //cout<<j<<" "<<i<<" ";
	            product=product/a[i];
	            i++;
	           // cout<<count<<" ";
	        }
	    }
	  
	    cout<<count<<endl;
	}
	return 0;
}
