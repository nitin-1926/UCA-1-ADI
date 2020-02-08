#include<iostream>
using namespace std;
#include<string>
int main(){
    int m;
    cin>>m;
    while(m--){
        string str;
        cin>>str;

        int n = str.length();
        char arr[2*n+1];
        int k=0;
        for(int i=0;i<n;i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
                continue;
            }
            else{
                    arr[k++]='*';
                    arr[k++] = str[i];
            }
        }
        for(int i=0;i<k;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
}

