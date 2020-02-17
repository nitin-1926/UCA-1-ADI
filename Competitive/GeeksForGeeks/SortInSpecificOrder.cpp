/*
Given an array A of positive integers. Your task is to sort them in such a way that the first part of the array contains odd numbers sorted in descending order, rest portion contains even numbers sorted in ascending order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated values of the array.

Output:
For each test case in a new line print the space separated values of the modified array.

Constraints:
1 <= T <= 103
1 <= N <= 107
0 <= Ai <= 1018

Example:
Input:
2
7
1 2 3 5 4 7 10
7
0 4 5 3 7 2 1

Output:
7 5 3 1 2 4 10
7 5 3 1 0 2 4

Explanation:
Testcase1: Array elements 7 5 3 1 are odd and sorted in descending order, whereas 2 4 10 are even numbers and sorted in ascending order.
*/

#include <iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
int f(int x,int y){
    return x>y;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    vector<int>even;
	    vector<int>odd;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i]%2==0){
	            even.push_back(a[i]);
	        }
	        else{
	            odd.push_back(a[i]);
	        }
	    }
	    sort(even.begin(),even.end());
	    sort(odd.begin(),odd.end(),f);
	    for(int i=0;i<even.size();i++){
	        odd.push_back(even[i]);
	    }
	    for(int i=0;i<odd.size();i++){
	        cout<<odd[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
