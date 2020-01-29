/*
Given three cases :
1st case when two strings are given , print the smallest of the two strings.
2nd case when two integers are given, print the smallest of the two integers.
3rd case when two char are given , print the smallest of the two characters(lowercase).

Your task is to complete class minElement which would include a private variable say y, a constructor which would set the given value to the private variable. And a method check() which would take one parameter say x and print the min of x and y(private variable) .

Input: 
The first line will contain an integer T (number of test cases). First line of each test case will contain 1 integer c. Next line will contain two strings if c is equal to 1 or will contain two integers if c is equal to 2 or will contain two char if value of c is equal to 3.

Output: 
Print the lowest of the two values given.

Constraints: 
1 < = T < = 100
1 < = c < = 3
1<= Length of strings, integers<=103

Example:
Input:
3
1
gfg spl
2
5 9
3
p s

Output:
gfg
5
p





*/
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

template <class T>
class minElement
{
    // Complete the class.Make a private variable,constructors and method called
    // check() which takes one parameter and prints the output in new line. 
    private:
        T y;
    public:
        minElement(T x){
            y = x;
        }
        void check(T x){
            if(x<y){
                cout<<x<<endl;
            }
            else{
                cout<<y<<endl;
            }
        }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        if(c==1)
        {
            string a,b;
            cin>>a>>b;
            minElement<string>obj1(a);
            obj1.check(b);
        }
        else if(c==2)
        {
            int a,b;
            cin>>a>>b;
            minElement<int>obj2(a);
            obj2.check(b);
        }
        else
        {
            char a,b;
            cin>>a>>b;
            minElement<char>obj3(a);
            obj3.check(b);
        }
    }
}

  // } Driver Code Ends
