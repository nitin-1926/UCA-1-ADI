/*
Sherlock is a famous detective. This time he's working to catch a team of gangsters. Sherlock knows that the head of gangsters will be caught if he catches his underlings. The gangsters work under a hierarchical system. Each member reports exactly to one other member of the town. It's clear that there are no cycles in their reporting system.There are N people in the town, for simplicity indexed from 1 to N, and Sherlock knows who each of them report to. Member i reports to member Ai, and head of Gangsters does not report to anybody. Sherlock wants to find the members to whom nobody reports as these members could help him bring down the organization.

Input:
First line consists of T test cases.
The first line every test case contains of one integer N.
Next line has N space-separated integers. The i-th integer denotes Ai, the person whom the i-th member reports to.

Output:
Single line output in ascending order, denoting the members of gangsters who nobody reports to.

Constraints:
1<=T<=100
1<= N<=10^5
1<=Ai<=N except for leader of gangsters, whose Ai equals to 0.

Example:
Input:
1
6
0 1 1 2 2 3
Output:
4 5 6

Explanation:
For testcase1: N=6 and A={0,1,1,2,2,3}
A[0]=0, A[1]=1, A[2]=1, A[3]=2, A[4]=2, A[5]=3.
A[0] is the head. 1 reports to 1. 2 reports to 1. 3 reports to 2. 4 reports to 2. 5 reports to 3.
So, the people not being being reported are 4, 5 and 6.

*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int hash[n+1] = {0};
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        hash[a[i]] = 1;
	    }
	    for(int i=0;i<n+1;i++){
	        if(hash[i] == 0){
	            cout<<i<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
