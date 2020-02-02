/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Output the character in patt that is present at the minimum index in str. Print "$" (without quotes) if no character of patt is present in str.

User Task:
The task is to complete the function printMinIndexChar() which finds the character in patt that is present at minimum index in str.

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

// { Driver Code Starts

// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;

string printMinIndexChar(string, string);

// Driver program to test above
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    cout << printMinIndexChar(str, patt) << endl;
	}
	return 0;
}// } Driver Code Ends

// function to find the minimum index character
// str: string given in the input
// patt: given pattern
string printMinIndexChar(string str, string patt)
{
    string result;
    int hash[150] = {0};
    for(int i=0;i<patt.length();i++){
        hash[patt[i]] = 1;
    }
    for(int i=0;i<str.length();i++){
        if(hash[str[i]] == 1){
            result += str[i];
            return result;
        }
    }
    result += "$";
    return result;
}
