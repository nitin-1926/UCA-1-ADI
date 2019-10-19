#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
void remove_duplicates(string str){
        stack <char> stk;
        int n=str.length();
        char char_array[n+1];
        int count=0;
        strcpy(char_array,str.c_str());
         stk.push(char_array[0]);
        for(int i=1;i<=n;i++){
                if(char_array[i]!=stk.top())
             {
                 if(count>=2)
               {
               while(count!=0)
                   {
                        stk.pop();
                        count--;
                    }
             stk.pop();
           }
            stk.push(char_array[i]);
            count=0;
            }
                else {
                        count++;
                        stk.push(char_array[i]);
                }
        }
        stack <char> stk1;
        while(stk.empty()==false){
                stk1.push(stk.top());
                stk.pop();
        }
        while(stk1.empty()==false){
            cout<<stk1.top();
            stk1.pop();
        }
}
int main(int argc,const char *argv[]){
        string str=argv[1];
        remove_duplicates(str);
        return 0;
}
