#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,a,b;
struct ll
{
    int x,y;
};
ll lines[10000];
bool cmp(ll f,ll s)
{
    if(f.y<s.y)return true;
    if(f.y>s.y)return false;
    if(f.x>s.x)return true;
    return false;
}
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a>>b;
        lines[i].x=a;lines[i].y=b;
    }
    sort(lines+1,lines+n+1,cmp);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}