#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e6+9;
const int inf=1e9;
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long lli;
int n,k;
int m;
int l[nmax],r[nmax];
int lcnt[nmax],rcnt[nmax];
pii a[nmax];
lli ans=0;
ifstream cin("monument.in");
ofstream cout("monument.out");
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   for(int i=0;i<nmax;i++){
      l[i]=inf;
      r[i]=-inf;
   }
   cin>>n>>k;
   int mny=inf;
   int mxy=-1;
   for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      a[i]=mp(x,y);
      mny=min(mny,y);
      mxy=max(mxy,y);
   }
   m=mxy-mny;
   for(int i=0;i<n;i++){
      int nxt=(i+1)%n;
      if(a[i].second!=a[nxt].second){
         int posl=min(a[i].second,a[nxt].second)-mny;
         int posr=max(a[i].second,a[nxt].second)-mny;
         for(int pos=posl;pos<posr;pos++){
            l[pos]=min(l[pos],a[i].first);
            r[pos]=max(r[pos],a[i].first);
         }
      }
   }
   for(int i=0;i<m;i++){
      lcnt[(l[i]-i%k+k)%k]++;
      rcnt[(r[i]-i%k+k)%k]++;
      ans+=(r[i]-i%k+k+k-1)/k;
      ans-=(l[i]-i%k+k)/k;
   }
   lli best=ans;
   for(int i=0;i<k;i++){
      ans+=lcnt[i];
      ans-=rcnt[(i+1)%k];
      best=min(best,ans);
   }
   cout<<best<<"\n";
}
