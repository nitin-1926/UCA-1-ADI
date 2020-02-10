/*
Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Input Format:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output Format:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Your Task:
This is a function problem. You only need to complete the function sortByFreq that takes arr, and n as parameters and prints the sorted elements. Endline is provided by the driver code.

Constraints:
1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ Ai ≤ 60 

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.

Testcase2: The highest frequency here is 3. The element 9 has the highest frequency. So 9 9 9 comes first. Now both 2 and 5 have same frequency. So we print smaller element first.
The output is 9 9 9 2 5.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int a[1000000];

void sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    sortByFreq(a,n);
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends
//Complete this function
//The array is declared globally
void sortByFreq(int arr[],int n)
{
    //Your code here
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]] += 1;
    }
    map<int,set<int>>r;
    for(auto it = m.begin();it!=m.end();it++){
        r[it->second].insert(it->first);
    }
    map<int,set<int>>::reverse_iterator it;
    for(it = r.rbegin();it!=r.rend();it++){
        for(auto itr = it->second.begin();itr!=it->second.end();itr++){
            int j=it->first;
            while(j--){
                cout<<*itr<<" ";   
            }
        }
    }
}
