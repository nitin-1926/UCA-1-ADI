#include <iostream>
#include <queue>
#include <string>
using namespace std;
void rearrange(string str){
	string str2;
	char prev=str[0];
	int k=0;
	str2[k++] = prev;
	queue <char> q;
	char current;
	for(int i=1;i<str.length();i++){
	    current=str[i];
	    if(current!=prev){
	        str2[k++] = current;
	        prev=current;
	        if(q.empty()==false){
		        char t=q.front();
		        if(prev!=t){
	                str2[k++] = t;
	                prev=t;
	                q.pop();
		        }
            }
        }
	    else{
	        q.push(str[i]);
	    }
	}
	if(q.empty()!=false){
		for(int i=0;i<k;i++){
	        cout<<str2[i];
	    }	
	}
	else{
		cout<<str;	
	}
}
int main(){
    string str;
    cin>>str;
    rearrange(str);
    return 0;
}
