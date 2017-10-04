#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int nmax=109;
int n,k;
int a[nmax];
vector<pair<int,int> >ans;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=k;i++){
      int mnpos=1,mxpos=1;
      for(int j=1;j<=n;j++){
         if(a[j]>a[mxpos])mxpos=j;
      }
      for(int j=1;j<=n;j++){
         if(a[j]<a[mnpos]&&mxpos!=j)mnpos=j;
      }
      if(a[mxpos]-a[mnpos]>0){
         a[mnpos]++;
         a[mxpos]--;
         ans.push_back(mp(mxpos,mnpos));
      }
   }
   int mx=-10009,mn=100009;
   for(int i=1;i<=n;i++){
      mx=max(mx,a[i]);
      mn=min(mn,a[i]);
   }
   cout<<mx-mn<<" "<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
      cout<<ans[i].first<<" "<<ans[i].second<<"\n";
   }
}
