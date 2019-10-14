#include<iostream>
#include<stack>
using namespace std;
bool tags(string str){
    for(int i=0;i<str.length();i++){
        stack<int>stackk;
        if(str[i]=='<' && str[i+1]!='/'){
         string tag;
         while(str[i]!='>' && i<str.length()){
             tag+=str[i++];
         }
         tag+=str[i];
         stackk.push(tag);
        }
        else if(str[i]=='<'&&str[i+1]=='/'){
         string tag;
         while(str[i]!='>' && i<str.length()){
             tag+=str[i++];
         }
         tag+=str[i];
         tag.erase(remove(tag.begin(),tag.end(),'/'),tag.end());
         if(tag.compare(stackk.top())==0)
            tag.pop();
         else
            return false;
        }

 }
if(stackk.empty())
    return true;
else
    return false;
}
int main(){
 string str;
 getline(cin,str);
 if(tags(str))
    cout<<"HTml Code Valid\n";
 else
    cout<<"Sorry, Html Code Invalid\n";
return 0;
}