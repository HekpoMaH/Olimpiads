#include<bits/stdc++.h>
using namespace std;
int m[49];
int main()
{
    string ch[309];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ch[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ch[i].size();j++)m[ch[i][j]-'a']++;
    }
    int br=0;
    for(int i=0;i<29;i++)if(m[i]>0)br++;
    if(br>2||br==1)cout<<"NO"<<endl,exit(0);
    for(int i=1;i<n;i++)
    {
        if(ch[i][i]!=ch[i-1][i-1])cout<<"NO"<<endl,exit(0);
        if(ch[n-i-1][i]!=ch[n-i][i-1])cout<<"NO"<<endl,exit(0);
    }cout<<"YES"<<endl;
}
