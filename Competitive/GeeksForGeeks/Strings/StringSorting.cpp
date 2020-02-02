#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t=0;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        map<int, int> mp;
        for(int i=0; i<str.size(); i++){
            mp[str[i]]++;
        }
        int j=0;
        for(auto i : mp){
            while((i.second)--)
                cout<<char(i.first);
        }
        cout<<endl;
    }
}
