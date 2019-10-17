#include<iostream>
using namespace std;
string common(string str1,string str2)
{
    string res="";
    int x=0;
    while(x<str1.length()&&x<str2.length())
    {
        if(str1[x]!=str2[x])
            break;
        res+=str1[x];
        x++;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
        cin>>str[i];
    string result=str[0];
    int c=0;
    for(int i=1;i<n;i++)
    {
        result=common(str[i],result);
        if(result=="")
        {
            c=1;
            break;
        }
    }
    if(c==0)
        cout<<result;
    else
        cout<<"No common prefix";
        return 0;
}