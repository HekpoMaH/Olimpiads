#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
set<int> s;
int n;
int m;
vector<pair<int,int> > a;
int zatr[2*nmax];
void read(){
   cin>>m;
   cin>>n;
   for(int i=1;i<=n;i++){
      int x,y;
      cin>>x>>y;
      a.pb(mp(x,-i));
      a.pb(mp(y,i));
   }
}
int ans;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   sort(a.begin(),a.end());
   s.insert(0);
   for(int i=0;i<a.size();i++){
      int t=a[i].se;
      //t<0 beginning
      //t>0 end
      if(t<0){
         zatr[min(*s.rbegin(),-t)]=1;
         s.insert(-t);
      }
      else{
         ans+=(zatr[t]==0);
         s.erase(t);
      }
   }
   cout<<ans<<"\n";
}
