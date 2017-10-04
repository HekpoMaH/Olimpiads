#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int a[100007];
int b[100007];
int mindist[100007];
int eating[100007];
int brhungry;
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int nz;
    cin>>nz>>nz;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>b[i];
        mindist[i]=1000000000;
    }
}
pair<int,int> getclosest(int ind)
{
    int l,r;
    l=0;
    r=m;
    int mid;
    while(r-l>1)
    {
        mid=(l+r)/2;
        if(b[mid]>a[ind])r=mid;
        else l=mid;
    }
    if(b[l]<a[ind])l++;
    pair<int,int> ans;
    ans.first=l-1;ans.second=l;
    return ans;
}
void dostep1(int x,int y)
{
    int dist=abs(a[x]-b[y]);
    if(dist==mindist[y]){eating[y]++;return;}
    if(dist>mindist[y]){brhungry++;return;}
    brhungry+=eating[y];
    eating[y]=1;
    mindist[y]=dist;
}
void dostep2(int x,int y,int y1)
{
    int dist=abs(a[x]-b[y]);
    int dist1=abs(a[x]-b[y1]);
    if(dist==mindist[y]){eating[y]++;return;}
    int mn;
    if(eating[y]<=eating[y1])mn=y;
    else mn=y1;
    brhungry+=eating[mn];
    eating[mn]=1;
    mindist[mn]=dist;
}
void solve()
{
    if(m==0){cout<<n<<"\n";return;}
    int i,j;
    pair<int,int> p;
    int mn=10000;
    int mn1=10000;
    for(i=0;i<n;i++)
    {
        p=getclosest(i);
        mn=10000007;
        mn1=10000007;
        if(p.first!=-1)
        {
            mn=a[i]-b[p.first];
        }
        if(p.second!=m)
        {
            mn1=b[p.second]-a[i];
        }
        if(mn==mn1)dostep2(i,p.first,p.second);
        else if(mn<mn1)dostep1(i,p.first);
        else dostep1(i,p.second);
    }
    cout<<brhungry<<"\n";
}
int main()
{
    input();solve();
}
