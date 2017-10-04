#include <bits/stdc++.h>
using namespace std;
vector<long long>v[70];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,a[100001],b,i,j,mj=0,o=-1,vs=0,cvs=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b=a[i];
        j=0;
        while(b)
        {
            if(b%2==1)v[j].push_back(a[i]);
            j++;
            b/=2;
            mj=max(mj,j);
        }
    }
    int sz;
    for(i=0;i<mj;i++)
    {
        int x=3,x2;
        sz=v[i].size();
        if(sz==0)continue;
        x=v[i][0];
        for(j=1;j<sz;j++)
        x&=v[i][j];
        x2=1;
        if(x!=0)for(cvs=0;x%(x2*2)==0;x2*=2,cvs++);
        if(cvs>vs)o=i,vs=cvs;
    }
    sz=v[o].size();
    if(o==-1)
    {
        cout<<n<<endl;
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";
        return 0;
    }
    cout<<sz<<"\n";
    cout<<v[o][0];
    for(j=1;j<sz;j++)
    cout<<" "<<v[o][j];
}
