/*
Suppose you have two pets and you love both of them very much. You go to a pet store to buy different articles for your pets. But you ask salesman that you will buy only those articles which are actually in pair. In this store, articles are referred as integers. So you have to tell total no. of articles you will buy for your pets.

Note: Time complexity O(n).

Input : 
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Second line contains the no. of articles "N" shown by the salesman.Third line contains N - separated integers describing the articles referred as an integer.

Output : 
Total No. of articles you will prefer to buy for your pets.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
1 ≤ A[N] ≤ 1000

Example : 
Input : 
1
7
10 10 10 20 20 10 20
Output :
6
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
	    int hash[1000] = {0};
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        hash[a[i]]+=1;
	    }
	    int count=0;
	    for(int i=0;i<1000;i++){
	        if(hash[i] >= 2){
	           count += (hash[i]/2);
	        }
	    }
	    cout<<count*2<<endl;
	}
	return 0;
}
