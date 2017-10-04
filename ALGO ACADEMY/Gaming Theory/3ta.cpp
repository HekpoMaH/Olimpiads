#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int n,m,k,l;
int t ;
void solve()
{
    cout<<"solving it"<<endl;
    cin>>n>>m>>k>>l;
    cout<<n<<" "<<m<<" "<<k<<" "<<l<<endl;
    int dist=abs(m-l);
    //if(k%2==0&&dist%2==0){cout<<"Draw\n";return ;}//mestim ne4etno dist 4etno
    if(k%2==1&&dist%2==1){cout<<"Draw\n";return ;}//obratnoto;
    vector<int> wt;
    int st;
    if(k%2==0)st=1;
    if(k%2==1)st=2;
    for(int i=st;i<=k;i+=2)wt.push_back(i);//,cout<<i<<" ";cout<<endl;
    int ans[2000009];
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=dist;i++)
    {
        for(int j=0;j<wt.size();j++)
        {
            if(i-wt[j]>=0&&ans[i-wt[j]]==0){ans[i]=1;break;}
        }
    }
    //for(int i=0;i<=dist;i++)cout<<ans[i]<<" ";cout<<endl;
    if(ans[dist]==1)cout<<"Peshlyaka\n";
    else cout<<"Goshlyaka\n";
}
int main()
{
    cin>>t;cout<<"t="<<t<<endl;
    while(t--)
    {
        cout<<"tt="<<t<<endl;
        solve();
    }
}
