#include<bits/stdc++.h>
using namespace std;
const int nmax=300009;
int a[nmax],n,best=-1;
int stn[nmax][29],stm[nmax][29];
int logg[nmax];
const int inf=1e6+ 9;
int nod(int a,int b)
{
    if(b>a)swap(a,b);
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
int fmin(int l,int r);
int fnod(int l,int r);
bool eval(int lent)
{
    for(int i=1;i<=n-lent+1;i++)
    {
        if(fmin(i,i+lent-1)==fnod(i,i+lent-1))
        {
            return true;
        }
    }
    return false;
}
void makelogg()
{
    int lg=0;
    for(int i=1;i<=nmax;i++)
    {
        if((1<<lg)<i)lg++;
        logg[i]=lg-1;
    }
    logg[1]=0;
}
void bsparsemin()
{
    for(int i=1;i<=n;i++)stm[i][0]=a[i];
    //cout<<n<<" "<<logg[n]<<endl;
    for(int k=1;k<=logg[n];k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+(1<<k)-1<=n)
            stm[i][k]=min(stm[i][k-1],stm[i+(1<<(k-1))][k-1]);
        }
    }
}
void bsparsenod()
{
    for(int i=1;i<=n;i++)stn[i][0]=a[i];
    for(int k=1;k<=logg[n];k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i+(1<<k)-1<=n)
            stn[i][k]=nod(stn[i][k-1],stn[i+(1<<(k-1))][k-1]);
        }
    }
}
int fmin(int l,int r)
{
    return min(stm[l][logg[r-l+1]],stm[r-(1<<logg[r-l+1])+1][logg[r-l+1]]);
}
int fnod(int l,int r)
{
    return nod(stn[l][logg[r-l+1]],stn[r-(1<<logg[r-l+1])+1][logg[r-l+1]]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();makelogg();
    bsparsenod();
    bsparsemin();

    //memset(itm,31,sizeof(itm));
    //cout<<getmin(1,1,n,2,4)<<" "<<getnod(1,1,n,2,2)<<endl;

    int ll=1,rr=n;int mid;
    int ans=0;
    while(ll<=rr)
    {
        mid=(ll+rr)/2;
        if(eval(mid))ll=mid+1,ans=max(ans,mid);
        else rr=mid-1;
    }
    vector<int> out;
    for(int i=1;i<=n-ans+1;i++)
    {
        if(fmin(i,i+ans-1)==fnod(i,i+ans-1))
        {
            out.push_back(i);
        }
    }

    cout<<out.size()<<" "<<ans-1<<"\n";
    for(int i=0;i<out.size();i++)
    {
        cout<<out[i]<<" ";
    }
    cout<<"\n";
}
