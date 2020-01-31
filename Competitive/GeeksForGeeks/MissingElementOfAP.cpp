/*
Find the missing element from  an ordered array A[ ], consisting of N elements representing an Arithmetic Progression (AP) .
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N, where N is the size of the array A[ ].
The second line of each test case contains N space separated integers of an Arithmetic Progression denoting elements of the array A[ ].
 

Note: The series should have a missing element in between a perfect A.P. with no missing element will not be considered.
 

Output:
Print out the missing element. 
 

Constraints:
1 <= T <= 100
2 <= N <= 10
-50 <= A[i] <=50
 

Examples :

Input:
3
3 
2 10 14 
4 
-28 -21 -7 0 
5 
9 12 15 21 24

Output : 
6
-14
18
*/

#include <iostream>
using namespace std;


int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    if(n==2){
	        cout<<(a[0]+a[1])/2<<endl;
	    }
	    else{
	        int ap = a[1]-a[0];
    	    int ap2 = a[n-1]-a[n-2];
    	    if(ap!=ap2){
    	        ap=min(ap,ap2);
    	    }
    	    for(int i=0;i<n-1;i++){
    	        if(a[i]+ap == a[i+1]){
    	            continue;
    	        }
    	        else{
    	            cout<<a[i]+ap<<endl;
    	        }
    	    }
	    }
	}
	return 0;
}
