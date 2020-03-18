/*
Given an unsorted array. Your task is to find the maximum difference between the successive elements in its sorted form.

Input:
The first line of input contains an integer T,  number of test cases. Following T lines contains an integer N denoting the size of array and next line followed contains the array elements.

Output:
Print the maximum gap between the successive elements.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ 106

Example:
Input:
1
3
1 10 5

Output:
5

Explanation:
Testcase 1: The maximum difference between successive elements of array is 5(abs(5-10)).
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    int max=0;
	    for(int i=0;i<n;i++)
	    {
	        int m;
	       m=a[i+1]-a[i];
	        if(m>max&&i+1<n)
	        {
	            max=m;
	        }
	    }
	    cout<<max<<endl;
	}
	return 0;
}
