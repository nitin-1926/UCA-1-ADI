// { Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class student
{
    private:
    string first_name;
    string last_name;
    
    public:
    void set_name(string f, string l)
    {
        first_name = f;
        last_name = l;
    }
       
    friend void check_name(student k);
};

    
 // } Driver Code Ends
//User function Template for C++

void check_name(student k)
{
    //Add your code here.
    string f = k.first_name;
    string l = k.last_name;
    
    int fl = f.length();
    int ll = l.length();
    int n = fl+ll;
    int hash[2000] = {0};
    int flag = 0;
    for(int i=0;i<fl;i++){
        hash[f[i]] += 1;
    }
    for(int i=0;i<ll;i++){
        hash[l[i]] -= 1;
    }
    for(int i=0;i<2000;i++){
        if(hash[i] != 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){cout<<"NOT ANAGRAM"<<endl;return;}
    cout<<"ANAGRAM"<<endl;return;
}

// { Driver Code Starts.
  
  
  
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	   
	    string f,l;
	    cin>>f>>l;
	   
	    student s1;
	    s1.set_name(f,l);
	    check_name(s1);
	    
	    
	    
	}
	return 0;
}  // } Driver Code Ends
