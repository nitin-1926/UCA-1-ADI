/*
Your are given N students with some goodies to be distrubuted among them such that student at ith index gets exactly i amount of goodies (considering no wastage). The goodies has already been distributed by some other. Your task is to check if it can be redistributed such that student at ith index gets i amount of goodies.

Input:
First line of input denotes the number of test cases T. The first line of each test case contains one integer N, denoting the number of students. The second line of each test case contains N integers each Ai, denoting the number of goodies distributed to ith member.

Output:
Print "YES" if we can redistribute in the requried way, otherwise "NO" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018

Examples:
Input:
2
5
7 4 1 1 2
5
1 1 1 1 1
Output:
YES
NO

Explanation:
Testcase 1: Since, all the goods can be redistributed as 1 2 3 4 5 (ith students get i number of goodies). So, output is YES.
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
	    for(int i=1;i<=n;i++){
	        cin>>a[i];
	    }
	   int sum=0;
	   int index=0;
	    for(int i=1;i<=n;i++){
	        sum = sum + a[i];
	        index = index + i;
	    }
	    
	    if(sum==index){cout<<"YES"<<endl;}
	    else{cout<<"NO"<<endl;}
	}
	return 0;
}
