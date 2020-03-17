/*
Find and print the uncommon characters of the two given strings S1 and S2. Here uncommon character means that either the character is present in one string or it is present in other string but not in both. The strings contains only lowercase characters and can contain duplicates.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings in two subsequent lines.

Output:
For each testcase, in a new line, print the uncommon characters of the two given strings in sorted order.

Constraints:
1 <= T <= 100
1 <= |S1|, |S2| <= 105

Example:
Input:
1
characters
alphabets
Output:
bclpr
*/

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str1,str2;
	    cin>>str1>>str2;
	    map<char,int>hash;
	    map<char,int>hash1;
	    set<char>s;
	    for(int i=0;i<str1.length();i++){
	        hash[str1[i]]=1;
	    }
	    for(int j=0;j<str2.length();j++){
	        hash1[str2[j]]=1;
	    }
	    for(int i=0;i<str1.length();i++){
	        if(hash1[str1[i]]!=1){
	            s.insert(str1[i]);
	        }
	    }
	    for(int i=0;i<str2.length();i++){
	        if(hash[str2[i]]!=1){
	            s.insert(str2[i]);
            }
	    }
	    set<char>::iterator itr;
	    for(itr = s.begin();itr!=s.end();itr++){
	        cout<<*itr;
	    }
	    cout<<endl;
	}
	return 0;
}
