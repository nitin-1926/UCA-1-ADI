/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
*/

#include <iostream>
using namespace std;
#include<stack>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    stack<int>s;
	    int flag = 0;
	    for(int i=0;i<str.length();i++){
	        char ch = str[i];
	        if(ch=='['||ch=='{'||ch=='('){
	            s.push(ch);
	        }
	        if(ch==']'||ch=='}'||ch==')'){
	            if(s.empty()==true){flag=1;break;}
	            char temp = s.top();
	            s.pop();
	            if(temp=='[' && ch!=']'){flag=1;break;}
	            if(temp=='{' && ch!='}'){flag=1;break;}
	            if(temp=='(' && ch!=')'){flag=1;break;}
	        }
	    }
	    if(flag==0 && s.empty()==true){cout<<"balanced"<<endl;}
	    else{cout<<"not balanced"<<endl;}
	}
	return 0;
}
