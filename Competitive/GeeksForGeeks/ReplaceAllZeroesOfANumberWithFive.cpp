/*
You are given an integer n. You need to convert all zeroes of n to 5.

Input Format:
The first line of input contains an integer T denoting the number of test cases . 
Then T test cases follow . Each test case contains a single integer n denoting the number.

Output Format:
The output of the function will be an integer where all zero's are converted to 5 .

Your Task:
Your task is to complete the function convertFive which takes an integer n as argument and 
replaces all zeros in the number n with 5 .Your function should return the converted number .

Constraints:
1 <= T < 100
1 <= n <= 10000

Example:
Input
2
1004
121
Ouput
1554
121

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete the function 
specified, and not to write the full code.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int convertFive(int n);
 
// Driver program to test above function
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	cout<<convertFive(n)<<endl;
    }
}// } Driver Code Ends
/*you are required to complete this method*/
#include<math.h>
int convertFive(int n)
{
//Your code here
    int temp = n;
    int final=0;
    int dig = floor(log10(n) + 1);
    int num = pow(10,dig-1);
    while(num>=1){
        int x = n/num;
        x=x%10;
        if(x==0){
            x=5;
        }
        final = final*10 + x;
        
        num = num/10;
    }
    return final;
}
