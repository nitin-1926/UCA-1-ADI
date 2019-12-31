/*
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains T, denoting the number of testcases. Then follows description of testcases. Each case begins with a single positive integer N denoting the size of array. The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whether it is Pythagorean Triplet or not (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[i] <= 1000

Example:
Input:
1
5
3 2 4 6 5

Output:
Yes

Explanation:
Testcase 1: a=3, b=4, and c=5 forms a pythagorean triplet, so we print "Yes"
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool triplet(int arr[],int n){
    int l,r;
    for(int i=0;i<n;i++)
        arr[i]=(arr[i]*arr[i]);
     for (int i = n-1; i >= 2; i--) 
    { 
        int l = 0;
        int r = i-1;
        while (l < r) 
        { 
            if (arr[l] + arr[r] == arr[i]) 
                return true; 
            (arr[l] + arr[r] < arr[i])?  l++: r--; 
        } 
    } 
    return false; 
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	        if(triplet(a,n))
	        cout<<"Yes";
	        else cout<<"No";
	    cout<<'\n';
	}
}
