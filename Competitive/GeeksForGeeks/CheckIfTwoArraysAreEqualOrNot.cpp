/*
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  Each test case contains 3 lines of input. The first line contains an integer N denoting the size of the array. The second line contains element of array A[]. The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[],B[] <= 1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15
Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1}; Since all the array elements are same. So,
Output : 1
Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15}; Since all the array elements are not same. So,
Output : 0
*/

#include <iostream>
#include<map>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int sum=0;
	    long long int sum1=0;
	    long long int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    long long int b[n];
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	        sum1+=b[i];
	    }
	    if(sum==sum1){
	        cout<<1<<endl;
	    }
	    else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}
