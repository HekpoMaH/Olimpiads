#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,l;
vector<int> lamps;
int main(){
   cin>>n>>l;
   for(int i=1;i<=n;i++){
      int x;
      cin>>x;
      lamps.pb(x);
   }
   sort(lamps.begin(),lamps.end());
   double ans=max((double)0,(double)lamps[0]);
   ans=max(ans,(double)l-lamps[lamps.size()-1]);
   for(int i=1;i<lamps.size();i++){
      ans=max(ans,(double)(lamps[i]-lamps[i-1])/2.0);
   }
   cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<"\n";
}
