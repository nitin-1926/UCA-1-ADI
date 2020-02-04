/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
*/
#include <iostream>
using namespace std;

int min(int a, int b,int c){
    if(a<b){
        if(a<c)
            return a;
        else{
            return c;
        }
    }
    else{
        if(b<c)
            return b;
        else
            return c;
    }
    
}
int editDistance(string str1, int l1, string str2, int l2){
    int a[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0){
                a[i][j] = j;
            }
            else if(j==0){
                a[i][j] = i;
            }
            else if(str1[i-1] == str2[j-1]){
                a[i][j] = a[i-1][j-1];
            }
            else{
                a[i][j] = min(a[i][j-1],a[i-1][j],a[i-1][j-1])+1;
            }
        }
    }
    return a[l1][l2];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int l1,l2;
	    cin>>l1>>l2;
	    string str1,str2;
	    cin>>str1>>str2;
	    cout<<editDistance(str1,l1,str2,l2)<<endl;
	}
	return 0;
}
