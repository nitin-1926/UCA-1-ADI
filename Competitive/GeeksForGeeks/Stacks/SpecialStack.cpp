/*
Design a data-structure SpecialStack (using the STL of stack) that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the number of integers in a sequence. In the second line are n space separated integers of the stack.

Output Format:
For each testcase, in a new line, print the minimum integer from the stack. 

Your Task:
Since this is a function problem, you don't need to take inputs. Just complete the provided functions.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
1
5
18 19 29 15 16
Output:
15
*/

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends
/*Complete the function(s) below*/
void push(int a)
{
    s.push(a);
}

bool isFull(int n)
{
    return (s.size()==n);
}

bool isEmpty()
{
    return (s.size()==0);
}

int pop()
{
    int temp=s.top();
    s.pop();
    return temp;
}

int getMin()
{
    int min=s.top();
    while(!s.empty()){
        if(min>s.top())
            min=s.top();
        s.pop();
    }
    return min;
}
