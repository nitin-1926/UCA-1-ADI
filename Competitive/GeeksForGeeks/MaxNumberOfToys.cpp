/*
Given an array consisting cost of toys. Given an integer K depicting the amount with you. Maximise the number of toys you can have with K amount.

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the number of toys and an integer K depicting the value of K.
Next line is followed by the cost of toys.


Output:

Print the maximum toys in separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ K ≤ 10000
1 ≤ A[i] ≤ 10000


Example:

Input
1
7 50
1 12 5 111 200 1000 10
Output
4
*/


#include <iostream>
using namespace std;
#include <queue>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    int k;
	    cin>>n>>k;
	    int a[n];
	    priority_queue <int, vector<int>, greater<int> > q;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        q.push(a[i]);
	    }
	    int sum=0;
	    int count = 0;
	    while(sum<=k){
	        sum+=q.top();
	        q.pop();
	        count++;
	    }
	    cout<<count-1<<endl;
	}
	return 0;
}
