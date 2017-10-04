#include<bits/stdc++.h>
using namespace std;
string s;
string s1,sl,sr;
int br;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='|')break;
        sl+=s[i];
        br++;
    }
    for(int i=br+1;i<s.size();i++)
    {
        sr+=s[i];
    }
    int lef=br,righ=s.size()-1-br;
    cin>>s1;
    if((lef+righ+s1.size())%2!=0||min(lef,righ)+s1.size()<max(lef,righ))
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int idx=0;
    while(sl.size()<(lef+righ+s1.size())/2)
    {
        if(idx>=s1.size()){cout<<"Impossible"<<endl;return 0;}
        sl+=s1[idx];
        idx++;
    }
    while(sr.size()<(lef+righ+s1.size())/2)
    {
        if(idx>=s1.size()){cout<<"Impossible"<<endl;return 0;}
        sr+=s1[idx];
        idx++;
    }
    cout<<sl<<"|"<<sr<<endl;
}
