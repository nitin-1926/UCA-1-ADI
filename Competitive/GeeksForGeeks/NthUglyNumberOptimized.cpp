#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    long long int a[10000];
	    a[0]=1;
	    a[1]=2;
	    a[2]=3;
	    a[3]=4;
	    a[4]=5;
	    int i=2;
	    int j=1;
	    int k=1;
	    int p=5;
	    if(n<=5){
	        cout<<a[n-1]<<endl;
	    }
	    else{
	        while(p<n){
	            long long int m=min(2*a[i],min(3*a[j],5*a[k]));
	            a[p]=m;
	            if(m==2*a[i]){
	                i++;
	            }
	            if(m==3*a[j]){
	                j++;
	            }
	            if(m==5*a[k]){
	                k++;
	            }
	            p++;
	        }
	        cout<<a[n-1]<<endl;
	        
	    }
	}
	return 0;
}
