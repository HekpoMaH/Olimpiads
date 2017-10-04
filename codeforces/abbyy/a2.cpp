#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using  namespace std;
long long n,k;
long long a[300009],ps[300009],mx=-1000000000000000000LL,mn,mn2,s,l;
map<long long,long long> used;
vector<long long> ans,c;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;

    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(used[a[i]]==0)used[a[i]]=i;
        ps[i]=ps[i-1];//re[i]=re[i-1];
        if(a[i]>0)ps[i]+=a[i];
        //cout<<i<<endl;
        //else re[i].push_back(i);
        //if(used[a[rs[i]=a[i]+used[a[i]];
    }
    //cout<<used[-1]<<endl;
    for(long long i=1;i<=n;i++)
    {
        if(used[a[i]]==i)continue;
        if(ps[i]-ps[used[a[i]]-1]>mx&&used[a[i]]!=i&&a[i]>=0)
        {l=1;
            //cout<<i<<" "<<used[a[i]]<<" "<<ps[i]<<" "<<ps[used[a[i]]-1]<<endl;
            mx=ps[i]-ps[used[a[i]]-1];
            mn=used[a[i]];mn2=i;
        }
    }//ans.clear();
        for(long long i=1;i<=n;i++)
        {
            if(used[a[i]]==i)continue;
            if(a[i]+a[used[a[i]]]+ps[i]-ps[used[a[i]]-1]>mx&&used[a[i]]!=i&&a[i]<0)
            {
                mx=a[i]+a[used[a[i]]]+ps[i]-ps[used[a[i]]-1];
                mn=used[a[i]];mn2=i;
            }
        }
        //cout<<mn<<" "<<mn2<<endl;
        for(long long i=1;i<mn;i++)ans.push_back(i);
        for(long long j=mn2+1;j<=n;j++)ans.push_back(j);
        for(long long i=mn+1;i<mn2;i++)if(a[i]<0)ans.push_back(i);

    sort(ans.begin(),ans.end());
    cout<<mx<<" "<<ans.size()<<endl;//cout<<a[mn]<<" "<<mn2<<endl;
    for(long long i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    if(ans.size()!=0)cout<<endl;
}

