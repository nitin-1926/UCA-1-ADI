/*
Given a string which may contains lowercase and uppercase chracters. The task is to remove all  duplicate characters from the string and print the resultant string.  The order of remaining characters in the output should be same as in the original string.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains a string.

Output:
Print the resultant string after removing duplicate characters from string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
geeksforgeeks
HappyNewYear

Output:
geksfor
HapyNewYr

Explanation:
Testcase 1: After removing duplicate characters such as e, k, g, s, we have string as geksfor.
*/

#include <iostream>
using namespace std;

void ans(string s){
    int n = s.length();
    int hash[150]={0};
    
    for(int i=0;i<n;i++){
        if(hash[s[i]]==1){
            continue;
        }
        else{
            cout<<s[i];
            hash[s[i]]=1;
        }
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    ans(s);
	    cout<<endl;
	}
	return 0;
}
