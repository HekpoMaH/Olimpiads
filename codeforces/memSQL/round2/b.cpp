#include<bits/stdc++.h>
using namespace std;
int used[50009];
string s;
long long l,f[3001][3009];
long long bc[3009][3009];
bool setted[3001][3009];
long long br=0;
void dfs(int l,int r)
{
    if(setted[l][r])return;
    setted[l][r]=true;
    if(r<l)return;
    if(l==r)
    {
        bc[l][r]=0;
        f[l][r]=1;
        return;
    }
    if(s[l]==s[r])
    {
        bc[l][r]=0;
        dfs(l+1,r-1);
        f[l][r]=f[l+1][r-1]+2;
    }
    else
    {
        dfs(l+1,r);dfs(l,r-1);
        if(f[l+1][r]>f[l][r-1])
        {
            bc[l][r]=1;
            f[l][r]=f[l+1][r];
        }
        else
        {
            bc[l][r]=2;
            f[l][r]=f[l][r-1];
        }
    }
}
void printt(int l,int r)
{
    if(r<l)return;
    if(l==r)
    {
        cout<<s[r];return;
    }
    if(bc[l][r]==0)
    {
        cout<<s[l];
        br++;
        //return;
        if(br<50)
        printt(l+1,r-1);cout<<s[r];
    }
    else if(bc[l][r]==1)
    {
        printt(l+1,r);
    }
    else printt(l,r-1);
}
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)used[s[i]-'a']++;
    for(int i=0;i<26;i++)if(used[i]>=100)
        {
            for(int j=1;j<=100;j++)cout<<(char)(i+'a');
            cout<<endl;
            return 0;
        }
    dfs(0,s.size()-1);
    printt(0,s.size()-1);
}
