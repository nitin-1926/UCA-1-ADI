/*
Given an array of integers A[] and a number k.You can pair two number of array if difference between them is strictly less than k. The task is to find maximum possible sum of such disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.

Examples:

Input  : A[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Then disjoint pairs with difference less than K are,
(3, 5), (10, 12), (15, 17)	
max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is,
(3, 5), (9, 12), (15, 17), but this pairing produces less sum.

Input  : A[] = {5, 15, 10, 300}, k = 12
Output : 25
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 3 lines . The first line of each test case is an integer N denoting the size of the array A. In the next line are N space separated values of the array A. In the next line is an integer x.


Output:
For each test case output in a new line the maximum possible sum of disjoint pairs

Constraints:
1<=T<100
1<=N<=100
1<=A[] <=1000

Example:
Input:
2
7
3 5 10 15 17 12 9
4
4
5 15 10 300
12

Output:
62
25
*/

#include <iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        int num;
	        cin>>num;
	        v.push_back(num);
	    }
	    int k;
	    cin>>k;
	    sort(v.begin(),v.end());
	    int sum=0;
	    for(int i=n-1;i>0;i--){
            if((v[i]-v[i-1])<k){
                sum+=(v[i]+v[i-1]);
                i--;
            }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
