#include<bits/stdc++.h>
using namespace std;
unsigned long long a[10000009],cntpr[10000009];
bool pr[10000009];
int n,m;
int x;
int l,r,mxx;
void gotax(int x)
{
    int d=2;
    while(x!=1)
    {
        if(x%d==0)a[d]++,x/=d;
        else d++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;a[x]++;
    }
    memset(pr,true,sizeof(pr));
    //cout<<a[2]<<" "<<a[5]<<endl;
    for(int i=2;i<=10000004;i++)
    {
        if(pr[i])for(int c=i;c<=10000004;c+=i)
        {
            pr[c]=false;
            cntpr[i]+=a[c];
        }
    }
    for(int i=1;i<=10000004;i++)
    {
        cntpr[i]+=cntpr[i-1];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        cout<<cntpr[min(r,10000004)]-cntpr[min(l-1,10000004)]<<"\n";
    }
}
