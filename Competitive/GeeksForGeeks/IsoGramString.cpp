/*
Given a string S of lowercase aplhabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Input Format:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case consist of one string in 'lowercase' only, in a separate line.

Output Format:
For each testcase, in a new line, Print 1 if string is Isogram else print 0.

Your Task:
This is a function problem. You only need to complete the function isIsogram() that takes string as parameter and returns either true or false.

Constraints:
1 <= T <= 100
1 <= |S| <= 103

Example:
Input:
2
machine
geeks
Output:
1
0

Explanation:
Testcase 2: geeks is not an isogram as 'e' appears twice. Hence we print 0.


*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool isIsogram(string s);

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        
        cout<<isIsogram(s)<<endl;
        
    }
	return 0;
}// } Driver Code Ends
//Complete this function
bool isIsogram(string s)
{
    int hash[150]={0};
    bool flag;
    flag = 1;
    
    for(int i=0;i<s.length();i++){
        if(hash[s[i]] == 1){
            flag = 0;
            break;
        }
        else{
            hash[s[i]] = 1;
        }
    }
    return flag;
}
