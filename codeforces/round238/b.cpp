#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        char c1='.',c2='.';
        int idx1=-1,idx2=-1;//'.' means nothing
        for(int j=0;j<i;j++)
        {
            if(s[j]!='.'){c1=s[j];idx1=j;}
        }
        for(int j=i+1;j<n;j++)
        {
            if(s[j]!='.'){c2=s[j];idx2=j;break;}
        }
        if(s[i]!='.')continue;
        if(c1=='L'&&c2=='R')ans++;
        else if(c1=='L'&&c2=='.')ans++;
        else if(c1=='.'&&c2=='R')ans++;
        else if(c1=='.'&&c2=='.')ans++;
        else if(c1=='R'&&c2=='L')
        {
            if(i-idx1-1==idx2-i-1&&(i-idx1)%2==(idx2-i)%2)ans++;
        }
        //cout<<i<<" "<<c1<<" "<<c2<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
