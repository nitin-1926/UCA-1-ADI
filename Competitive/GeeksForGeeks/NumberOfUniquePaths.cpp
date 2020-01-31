/*
Given a M X N matrix with your initial position at top-left cell, find the number of possible unique paths to reach the bottom right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an two integers A and B depicting the size of the grid.

Output:
Print the number of unique paths to reach bottom-right cell from the top-left cell.

Constraints:
1 ≤ T ≤ 30
1 ≤ M ≤ 15
1 ≤ N ≤ 15

Example:
Input:
2
2 2
3 4

Output:
2
10

Example:
Testcase 1:
There are only two unique paths to reach end of the matrix of size two from starting cell of the matrix.
*/

#include <iostream>
using namespace std;
int paths(int n,int m)
{
    int i,j;
    int a[n][m];
    for(int i=0;i<n;i++){
        a[i][0]=1;
    }
    for(int i=0;i<m;i++){
        a[0][i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    return a[n-1][m-1];
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    cout<<paths(n,m);
	    cout<<endl;
	}
	return 0;
}
