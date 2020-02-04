/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/

#include <iostream>
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }    
    return b;
}

int longestCommonSub(string str1, int l1, string str2, int l2){
    int a[l1+1][l2+1];
    
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 || j==0){
                a[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                a[i][j] = a[i-1][j-1]+1;
            }
            else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    return a[l1][l2];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int l1,l2;
	    cin>>l1>>l2;
	    
	    string str1;
	    string str2;
	    cin>>str1>>str2;
	    
	    cout<<longestCommonSub(str1,l1,str2,l2)<<endl;
	}
	return 0;
}
