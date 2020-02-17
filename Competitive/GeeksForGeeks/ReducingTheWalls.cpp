/*
Ishaan is trapped in a city full of walls. To escape from there, it needs to climb N walls, one after the other. He can climb a wall if its height is atmost K.
Ishaan also has a superpower. He can reduce the height of a wall H by K by using his superpower. Since he can't use this power many times, calculate the minimum number of times he has to use this power to go over all the walls.

Input : 
First line of input contains a single integer T denoting the number of test cases. The first line of each test case contains 2 space-separated integers N and K. The second line contains N space-separated integers denoting the heights of the walls.

Output : 
For each test case, print the required answer in a new line.

Constraints : 
1 <= T <= 100
1 <= N <= 250
1 <= K <= 105
1 <= H <= 109

Example : 
Input : 
3
5 5
5 3 2 6 8
6 4
2 6 4 8 1 6
4 3
2 2 2 2
Output : 
2
3
0

Explanation : 
Case 1 : 
Heights : 5 3 2 6 8
Ishaan can climb a wall with height atmost 5. So he climbs the first 3 walls easily.
Now he has to use his power to reduce the height of the 4th wall.
After using his power, heights : 5 3 2 1 8
Now to climb the last wall, he again uses his power.
Final heights : 5 3 2 1 3

Case 2 : 
Heights : 2 4 6 8 1 6
Ishaan can climb a wall with height atmost 4. So he climbs the first 2 walls easily.
Now he has to use his power to reduce the height of the 3rd wall.
After using his power, heights : 2 4 2 8 1 6
Now to climb the next wall, he again uses his power.
Heights : 2 4 2 4 1 6
He climbs the 5th wall easily.
To climb the last wall, h uses his power again.
Final Heights : 2 4 2 4 1 2

Case 3 : 
Since all the heights are already below K(=3), Ishaan can climb all the walls without using his powers.
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    int h;
	    cin>>n>>h;
	    int a[n];
	    int count=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i] > h){
	            if(a[i]%h==0){
	                count=count-1;
	            }
	            count=count+(a[i]/h);
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
