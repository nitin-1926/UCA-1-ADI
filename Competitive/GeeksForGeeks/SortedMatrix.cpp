/*
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the matrix. Then the next line contains the n x n elements in row wise order.

Output:
Print the elements of the matrix in sorted order.

Constraints:
1<=T<=100
1<=n<=100
1<=a[n][n]<=100

Example:
Input:
2
4
10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
3
1 3 4 2 6 7 5 8 9

Output:
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
1 2 3 4 5 6 7 8 9 
*/

#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n][n];
	    //set<int>s;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	            v.push_back(a[i][j]);
	        }
	    }
	    sort(v.begin(),v.end());
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<' ';
	    }
	    cout<<endl;
	}
	return 0;
}
