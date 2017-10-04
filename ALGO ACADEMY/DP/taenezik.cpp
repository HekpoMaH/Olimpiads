#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
string words[52],swords[52],snew,snewsorted;
int n;
int dp[52],diff,inf=99999;
bool cmp(string a,string b)
{
    if(a.size()<b.size())return true;
    return false;
}
int finddif(string a,string b)
{
    int br=0;
    for(int i=0;i<a.size();i++)if(a[i]!=b[i])br++;
    return br;
}
int main()
{
    for(int i=0;i<=52;i++)dp[i]=inf;
    cin>>s;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>words[i];
    sort(words+1,words+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        swords[i]=words[i];
        sort(swords[i].begin(),swords[i].end());
    }
    
    int dbg,ck;
    for(int i=0;i<s.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            dbg=words[j].size();
            if(i-dbg>=0)
            {
                //cout<<i<<" "<<words[j].size()<<endl;
                snew=s.substr(i-words[j].size(),words[j].size());
                cout<<snew<<endl;
                snewsorted=snew;
                sort(snewsorted.begin(),snewsorted.end());
            }
        }
    }
    for(int i=0;i<s.size();i++)cout<<dp[i]<<" ";
    cout<<endl;
    if(dp[s.size()+1]==inf)cout<<-1<<endl;
    else cout<<dp[s.size()+1]<<endl;
    return 0;
}