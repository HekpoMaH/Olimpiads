#include<bits/stdc++.h>
using namespace std;
int used[100],n,k,l,br;
string s;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        memset(used,0,sizeof(used));
        for(int j=0;j<s.size();j++)used[s[j]-'0']++;
        l=0;
        for(int j=0;j<=k;j++)
        {
            if(used[j]==0)l=1;
        }
        //for(int j)
        if(l==0)br++;
    }
    cout<<br<<endl;
}
