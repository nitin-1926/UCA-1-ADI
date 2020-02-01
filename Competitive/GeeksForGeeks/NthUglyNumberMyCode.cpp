/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. For each testcase there is one line of input that contains the number N.

Output:
Print the Nth Ugly Number.

Constraints:
1 ≤ T ≤ 104
1 ≤ N ≤ 104

Example:
Input:
2
10
4
Output:
12
4
*/
#include <iostream>
using namespace std;
#include <math.h>

int checkUgly(int n){
    int arr[n];
    int k=0;
    int p = n;
    if (n % 2 == 0)  
    {  
        arr[k++]= 2;  
    }  
    while(n%2==0){
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    { 
        if(n%i==0){
            arr[k++] = i;
        }
        while (n % i == 0)  
        {
            n = n/i;  
        }  
    }
    if (n > 2)  
        arr[k++] = n;
    
    int flag = 1;
    for(int i=0;i<k;i++){
        if(arr[i] == 2 || arr[i] == 3 || arr[i] == 5){
            continue;
        }
        else{
            flag = 0;
            return flag;
        }
    }
    return flag;
}
int findUgly(int n){
    int a[2*n];
    for(int i=0;i<6;i++){
        a[i] = i+1;
    }
    int count = 6;
    int x = 6;
    int i = 6;
    while(count<=n){
        x++;
        int l = checkUgly(x);
        if(l==1){
            a[i++] = x;
            count++;
        }
    }
    return a[n-1];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int result = findUgly(n);
	    cout<<result<<endl;
	}
	return 0;
}
