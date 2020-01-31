/*
Given an array of size n and an integer b, traverse the array and if the element in array is b, double b and continue traversal. In the end return value of b.

Input:

The first line of the input contains T denoting the number of testcases. Then follows the description of testcases. The first line of each testcase contains two space separated positive integers n and b denoting the size of array and initial value of b respectively.The second line contains n space separated positive integers denoting the elements of array.


Output:

For each testcase, print the final value of b.


Constraints:

1<=T<=100
1<=n<=50
1<=b<=1000
1<=A[i]<=1018 (1<=i<=N)


Example:

Input:
1
5 2
1 2 3 4 8

Output:
16

Explanation: The initial value of b is 2. Traversing from the first element, 2 is found in 2nd position, so doubling b we get b = 4 . 4 is found in 4th position so doubling b we get b = 8. 8 is found in 5th position, so doubling b we get b = 16.
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    long long int b;
	    cin>>n>>b;
	    long long int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        if(a[i] == b){
	            b = 2*b;
	        }
	    }
	    cout<<b<<endl;
	}
	return 0;
}
