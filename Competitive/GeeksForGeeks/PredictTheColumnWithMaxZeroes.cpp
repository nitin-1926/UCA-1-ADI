/*
Given a matrix(2D array) M of size N*N consisting of 0s and 1s only. The task is to find the column with maximum number of 0s.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines of input, first of which contains N and next N line contains N elements.

Output:
For each testcase, output the column with maximum number of 0s.

Constraints:
1 <= T <= 100
1 <= N <= 102
0 <= A[i][j] <= 1

User Task:
Your task is to complete the function columnWithMaxZero() which should return the column number with maximum number of zeros. If more than one column exists, print the one which comes first.

Example:
Input:
1
3
1 1 0
1 1 0
1 1 0

Output:
2

Explanation:
Testcase 1: 2nd column (0-based indexing) is having 3 zeros which is maximum among all columns.
*/

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

int M[100][100];

// Function prototype
int columnWithMaxZeros(int);


 // } Driver Code Ends
//User function Template for C++

/*Function to count zeros in each column
* N : Number of rows and columns in array
M is the matrix that is globally declared
*/
int columnWithMaxZeros(int N){
    
    // Your code here
    int sum=0;
    int k=0;
    int a[N];
    
    for(int j=0;j<N;j++){
        sum=0;
        for(int i=0;i<N;i++){
            if(M[i][j]==0){
                sum+=1;
            }
        }
        a[k++] = sum;
    }
    int max = -1;
    int index;
    for(int i=0;i<k;i++){
        if(a[i]>max){
            max=a[i];
            index=i;
        }
    }
    return index;
}

// { Driver Code Starts.

// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            cin >> M[i][j];
	        }
	    }
	    
	    cout << columnWithMaxZeros(N) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
