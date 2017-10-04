#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
const lli inf=8*1e18;
lli sum(lli k){
   return k*(k-1LL)/2LL;
}
int main(){
   lli n,m,k;
   cin>>n>>m>>k;
   vector<lli> x(m+1),y(m+1);
   for(lli i=0;i<=m;i++)cin>>y[i]>>x[i];
   lli ans=inf;
   vector<lli> vec;
   map<lli, vector<lli> >mp;
   for(lli i=0;i<=m;i++){
      vec.pb(y[i]);
      if(y[i]>1)vec.pb(y[i]-1);
      if(y[i]<n)vec.pb(y[i]+1);
      mp[y[i]].pb(x[i]);
   }
   sort(vec.begin(),vec.end());
   vec.resize(unique(vec.begin(),vec.end())-vec.begin());
   for(lli it=0;it<vec.size();it++){
      vector<lli> v=mp[vec[it]];
      v.pb(0);
      v.pb(n+1);
      sort(v.begin(),v.end());
      for(lli i=1;i<v.size();i++){
         if(v[i]-v[i-1]-1>=k){
            lli l=v[i-1]+1;
            lli r=v[i]-1;
            lli res=0;
            if(l<=x[m]&&x[m]<=r){
               lli a1=x[m]-l;
               lli a2=r-x[m];
               if(a1>a2)swap(a1,a2);
               lli opt=(k-1)/2;
               if(a1>opt){
                  a1=opt;
               }
               a2=(k-1)-a1;
               res=sum(a1+1)+sum(a2+1)+1LL*abs(y[m]-vec[it])*k;
            }
            else{
               res=sum(k)+1LL*(abs(y[m]-vec[it])+max(x[m]-r,l-x[m]))*k;
            }
            ans=min(ans,res);
         }
      }
   }
   if(ans==inf)ans=-1;
   cout<<ans<<"\n";
}
