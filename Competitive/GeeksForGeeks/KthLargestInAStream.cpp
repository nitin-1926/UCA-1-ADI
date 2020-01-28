#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main()
 {
	int test ;
	cin>>test ;
	while(test--){
	    int k , n ;
	    cin>>k>>n ;
	    priority_queue <int, vector<int>, greater<int> > heap ;
	    while(n--){
	        int data ;
	        cin>>data ;
	        
	        if(heap.size()<k ){
	            
	            if(heap.size()<k-1)
	            cout<<-1<<" ";
	            
	            heap.push(data);
	        }else if( heap.top()<data){
	            heap.pop();
	            heap.push(data); 
	        }
	        
	        //heap.push(data); 
	        //cin>>data ;
	        if(heap.size()==k){
	            cout<<heap.top()<<" ";
	        }
	        
	    }
	    cout<<endl; 
	}
	return 0;
}
