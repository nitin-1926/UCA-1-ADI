/*
Given a number (greater than 2), print two prime numbers whose sum will be equal to given number, else print -1 if no such number exists.

NOTE: A solution will always exist if the number is even. Read Goldbach’s conjecture.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then print [a, b] only
and not all possible solutions.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.

Output:
Print the two prime numbers in a single line with space in between.

Constraints:
1 ≤ T ≤ 50
2 ≤ N ≤ 1000000

Example:
Input:
2
8
3
Output
3 5
-1

Explanation:
Testcase 1: two prime numbers from 1 to 8 are 3 and 5 whose sum is 8.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n/2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main() 
{
      int t;
      cin>>t;
      while(t--)
      {
          int n;
          cin>>n;
          vector <int> v;
          for(int i=2;i<n;i++)
          {
              if(prime(i))
              {
                  v.push_back(i);
              }
          }
          int l=0,r=v.size()-1;
          int f=0;
          while(l<=r)
          {
              int s=v[l]+v[r];
              if(s<n)
                l++;
              else if(s>n)
                 r--;
                 else
                 {
                     f=1;
                     if(l==r)
                     {
                         cout<<v[l]<<" "<<v[l];
                     }
                     else
                     cout<<v[l]<<" "<<v[r];break;
                 }
          }
          if(!f)cout<<"-1";
          cout<<endl;
      }
	return 0;
}
