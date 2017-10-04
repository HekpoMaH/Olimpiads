#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int used[1000],mx,best=-1;
char mxc;
string base;
int main()
{
    cin>>s;
    cin>>n;memset(used,0,sizeof(used));
    for(int i=0;i<s.size();i++)
    {
        used[(int)(s[i]-'a')]++;
        //if(used[(int)s[i]]==1)base+=s[i];
    }
    int l=1,r=1000,mid,need;
    while(l<=r)
    {
        mid=(l+r)/2; need=0;
        for(int i=0;i<=25;i++)
        {
            need+=used[i]/mid;
            if(used[i]%mid!=0)need++;
        }
        if(need>n)l=mid+1;
        else r=mid-1,best=mid;
    }
    cout<<best<<endl;
    if(best!=-1)
    {
        need=0;
        for(int i=0;i<=25;i++)
        {
            int len=used[i]/best;
            if(used[i]%best!=0)len++;
            need+=len;
            for(int k=1;k<=len;k++)cout<<(char)(i+'a');
        }
        for(int i=1;i<=n-need;i++)
        cout<<'a';
        cout<<endl;
    }
}
