#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using  namespace std;
long long n,k;
long long a[300009],ps[300009],mx=-1000000000000000000LL,mn,mn2,s,l,q;
map<long long,long long> used;
vector<long long> ans,c;
int comp(int st,int en)
{
    long long br=0,mn=200000,br2=0;
    //long l used[30000];
    //memset(used,0,sizeof(used));
    for(int i=st;i<=en;i++)
    {
        mn=min(mn,a[i]);
    }
    int i=st;
    while(br<en-st+1)
    {
        //cout<<i<<" "<<br<<" "<<en-st+1<<endl;
        if(a[i]==mn)br++,mn++;
        i++;
        if(i==en+1&&br<en-st+1)i=st,br2++;
    }
    return br2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==2)swap(a[x],a[y]);
        else
        {
            int be, bee;
            for(int j=1;j<=n;j++){if(a[j]==x)be=j;if(a[j]==y)bee=j;}
            if(be>bee)swap(be,bee);
            cout<<comp(be,bee)<<endl;
        }
    }
}


