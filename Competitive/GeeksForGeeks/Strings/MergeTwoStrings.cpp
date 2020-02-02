/*
Given two strings S1 and S2 as input, the task is to merge them alternatively i.e. 
the first character of S1 then the first character of S2 and so on till the strings end.

NOTE: Add the whole string if other string is empty.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains two strings S1 and S2.

Output:
For each test case, in a new line, print the merged string.

Constraints:
1 <= T <= 100
1 <= |S1|, |S2| <= 104

Example:
Input:
2
Hello Bye
abc def

Output:
HBeylelo
adbecf
*/

#include <iostream>
using namespace std;

int mini(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s1,s2,s;
	    cin>>s1>>s2;
	    int l1 = s1.length();
	    int l2 = s2.length();
	    int n = mini(l1,l2);
	    for(int i=0;i<n;i++){
	        s=s+s1[i]+s2[i];
	    }
	    if(l1>l2){
	        for(int i=l2;i<l1;i++){
	            s+=s1[i];
	        }
	    }
	    else{
	        for(int i=l1;i<l2;i++){
	            s+=s2[i];
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}
