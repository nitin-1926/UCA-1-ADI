/*
Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9

Explanation:
Testcase 1: Array elements of A1[] are sorted according to A1[].
*/
#include <iostream>
using namespace std;
#include<map>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a1[n];
	    int a2[m];
	    map<int,int>hash;
	    for(int i=0;i<n;i++){
	        cin>>a1[i];
	        hash[a1[i]]+=1;
	    }
	    for(int i=0;i<m;i++){
	        cin>>a2[i];
	    }
	    int count;
	    for(int i=0;i<m;i++){
	        if(hash[a2[i]]){
	            count = hash[a2[i]];
	            while(count--){
	                cout<<a2[i]<<" ";
	                hash[a2[i]]-=1;
	            }
	        }
	    }
	    for(auto i : hash){
	        if(i.second > 0){
	            count = i.second;
	            while(count--){
	                cout<<i.first<<" ";
	            }
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
