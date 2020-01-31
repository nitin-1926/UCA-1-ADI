/*
Working with 2D arrays is quite important. Here we will do swapping of columns in a 2D array. You are given a matrix M of r rows and c columns. You need to swap the first column with the last column.

Input Format:
The first line of input contains T, the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains r and c, separated by a space. The next r lines contains c elements of the matrix, separated by spaces.

Output Format:
For each testcase, in a new line, print the modified matrix.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function interchange(int ,  int ) that take rows and columns number as parameter.

Constraints:
1 <= T <= 100
1 <= r,c <= 100

Example:
Input:
1
3 4
1 2 3 4
4 3 2 1
6 7 8 9
Output:
4 2 3 1
1 3 2 4
9 7 8 6
*/

// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

int arr[1000][1000];

void interchange(int ,int );

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++
//Complete this function
//The array arr is globally declared
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void interchange(int r,int c)
{
    //Your code here
    if(c%2==0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c/2;j++){
                swap(&arr[i][j],&arr[i][c-1-j]);
            }
        }
    }
    else{
        for(int i=0;i<r;i++){
            for(int j=0;j<(c/2)-1;j++){
                swap(&arr[i][j],&arr[i][c-1-j]);
            }
        }
    }
    
  //Printing the modified matrix
    for(int i=0;i<r;i++)
	   { 
	       for(int j=0;j<c;j++)
    	    {
    	        cout<<arr[i][j]<<" ";
    	        
    	    }
    	 cout<<endl;
	   }
}


// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    for(int i=0;i<r;i++)
	    for(int j=0;j<c;j++)
	    cin>>arr[i][j];
	    
	    
	    interchange( r, c);
	}
	return 0;
}

  // } Driver Code Ends
