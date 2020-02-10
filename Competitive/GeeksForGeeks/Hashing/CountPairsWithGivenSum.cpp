/*
Given an array of integers, and an integer  ‘K’ , find the count of pairs of elements in the array whose sum is equal to 'K'.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains 2 space separated integers N and K denoting the size of array and the sum respectively. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
Print the count of pairs of elements in the array whose sum is equal to the K.

Constraints:
1<=T<=50
1<=N<=50
1<=K<=50
1<=A[i]<=100

Example:
Input
2
4 6
1  5  7 1
4 2
1 1 1 1
Output
2
6
*/

#include <iostream>
using namespace std;
#include<map>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    map<int,int>m;
	    int count=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	       m[a[i]] += 1;
	    }
	    for(int i=0;i<n;i++){
	        int j=k-a[i];
	        count+=m[j];
	        if(j==a[i]){
	            count--;
	        }
	    }
	    cout<<count/2<<endl;
	}
	return 0;
}
