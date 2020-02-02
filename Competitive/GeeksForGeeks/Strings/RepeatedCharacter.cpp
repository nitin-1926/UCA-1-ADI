/*
Given a string - "str", find the repeated character present first in the string.

Example : 
Input  :  geeksforgeeks
Output :  g
          (mind that it will be g, not e.)

Input : 
The first line of input contains an integer T denoting the Test cases. Then T test cases follow. 
Second line contains the string - "str"

Output : 
repeated character present first in the string, if present
otherwise print "-1"


Input : 
3
hello
fg
geeksforgeeks

Output : 
l
-1
g
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int flag=0;
	    string s;
	    cin>>s;
	    for(int i=0;i<s.length();i++){
	        for(int j=i+1;j<s.length();j++){
	            if(s[i] == s[j]){
	                cout<<s[i]<<endl;
	                flag=1;
	                break;
	            }
	        }
	        if(flag==1){
	            break;
	        }
	    }
	    if(flag == 0){
	        cout<<-1<<endl;
	    }
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t=0;
    cin>>t;
    while(t--){
        //AASAAAN H
        string str;
        cin>>str;
        int n = str.size();
        map<char, int>mp;
        string x = "-1";
        for(int i=0; i<n; i++){
            mp[str[i]]++;
        }
        int min_ind = INT_MAX;
        // A little hint is given to maintain minimum index
        //so i need to use this hack. 
        for(int i=0; i<n; i++){
            if(mp[str[i]] >1 && i<min_ind){
                min_ind = i;
                x = str[min_ind];
            }
        }
        cout<<x<<endl;
    }
}*/
