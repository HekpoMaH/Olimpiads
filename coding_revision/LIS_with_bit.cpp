#include<bits/stdc++.h>
using namespace std;
int a[100009];
int n;
int dp[100009],pos[100009],ans,it[100009][3],mx2,cbp,a2[100009];
int bp[100009];

int get(int ps)
{
    int mx=0;
    int fenwickIndex=0;
    while(ps!=0)
    {
        if(it[ps][1]>mx)
        {
            mx=it[ps][1];
            fenwickIndex = ps;
        }
        ps-=(ps&-ps);
    }
    return fenwickIndex;
}
void update(int ps,int val, int extraField)
{
    while(ps<=n)
    {
        if(it[ps][1]<val)
        {
            it[ps][1]=val;
            it[ps][2]=extraField;
        }
        ps+=(ps&-ps);
    }
}
void outputseq(int pm)
{
    cout<<pm<<endl;
    while(pm!=0)
    {
        cout<<a2[pm]<<" ";
        pm=bp[pm];
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a2[i]=a[i],pos[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        int fenwickIndex = get(a[i]-1);
        ans=it[fenwickIndex][1];
        bp[i] = it[fenwickIndex][2];
        update(a[i],ans+1, i);
        mx2=max(ans+1,mx2);
        dp[i]=ans+1;
    }
    cout<<mx2<<endl;

    for(int i=1;i<=n;i++)
    {
        if(dp[i]==mx2)
        {
            outputseq(i);
            return 0;
        }
    }
}
