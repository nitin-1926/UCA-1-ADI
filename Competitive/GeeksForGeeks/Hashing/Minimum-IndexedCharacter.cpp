/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Output the character in patt that is present at the minimum index in str. Print "$" (without quotes) if no character of patt is present in str.

Constraints:
1 <= T <= 105
1 <= |str|, |patt| <= 105

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
$

Explanation:
Testcase 1: e is the character which is present in given patt "geeksforgeeks" and is first found in str "set".
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str1,str2;
	    cin>>str1>>str2;
	    map<char,int>hash;
	    for(int i=0;i<str2.length();i++){
	        hash[str2[i]]=1;
	    }
	    int flag=0;
	    for(int i=0;i<str1.length();i++){
	        if(hash[str1[i]] == 1){
	            cout<<str1[i]<<endl;
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0){
	        cout<<"$"<<endl;
	    }
	}
	return 0;
}
