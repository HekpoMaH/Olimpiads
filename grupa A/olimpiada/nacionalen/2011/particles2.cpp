#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
const int nmax=4*1e5+9;
lli n,nrj;
pii x[nmax],y[nmax];
lli indx=1,indy=1;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>x[i].se>>x[i].fi;
      x[i].fi*=x[i].se;
   }
   for(int i=1;i<=n;i++){
      cin>>y[i].se>>y[i].fi;
      y[i].fi*=y[i].se;
   }
   sort(x+1,x+n+1);
   sort(y+1,y+n+1);
   while(indx<=n&&indy<=n){
      if(x[indx].fi==y[indy].fi){
         nrj++;
         indx++;indy++;
      }
      else if(x[indx].fi<y[indy].fi)indx++;
      else indy++;
   }
   cout<<nrj<<"\n";
}
