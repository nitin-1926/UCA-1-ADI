/*
Given an array of N distinct elementsA[ ]. The task is to find the minimum number of swaps required to sort the array. Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 104
 

User Task: Your task is to complete minSwaps() which should return number of swaps required to make the array elements sorted.

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2

Explanation:
Testcase 1: We need two swaps, swap 1 with 4 and 3 with 2 to make it sorted.
*/

// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends
/* You are required to complete this method */
void swap(int *a,int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
}
int minSwaps(int a[], int n){
    int total = 0;
    for(int i=0;i<n-1;i++){
        int j,k;
        for(j=k=i;j<n;j++){
            if(a[j] < a[k]){
                k=j;
            }
        }
        if(k!=i){
            swap(&a[k],&a[i]);
            total++;
        }
    }
    return total;
}
