#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin>>n;
    cin>>s;
    int br1=0,br2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x')br1++;
        if(s[i]=='X')br2++;
    }
    int nu,nd,diff=br2-br1,o=diff/2,op=diff/2;
    //cout<<br1<<" "<<br2<<endl;
    if(op>0)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='X')s[i]='x',op--;
            if(op==0)break;
        }
    }
    if(op<0)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='x')s[i]='X',
            op++;
            if(op==0)break;
        }
    }
    cout<<abs(o)<<endl;
    cout<<s<<endl;

}
