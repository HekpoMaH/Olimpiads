#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > edges;
const int mod=1000000007;
int n,k,m,a,b;
int degs[1000009];
int ans;
int main()
{
    ios::sync_with_stdio(false);
    degs[0]=1;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        if(i==0)continue;
        degs[i]=2*degs[i-1]%mod;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(b-a!=1&&b-a!=k+1)
        {
            cout<<0<<endl;return 0;
        }
        if(b-a==k+1)edges.push_back(make_pair(a,b));
    }
    sort(edges.begin(),edges.end());
    m=edges.size();
    if(k==0||k>=n-1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(!(edges[i].first>=edges[0].first&&edges[i].first<=edges[0].second))
        {
            cout<<0<<endl;
            return 0;
        }
    }
    if(edges.size()==0)ans++;
    for(int i=0;i<n;i++)
    {
        int f=i+1,s=i+k+2,cnt=m;
        if(s>n||(m>0&&f>edges[0].first))break;
        if(m>0&&!(f<=edges[0].first&&edges[m-1].first<s))continue;
        if(m>0&&f==edges[0].first)cnt--;
        s=min(s,n-k);
        ans=(ans+degs[s-f-cnt-1])%mod;
    }
    cout<<ans<<endl;
}
