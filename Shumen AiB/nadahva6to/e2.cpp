#include<bits/stdc++.h>
using namespace std;
int n,k,x,l=-1,r=(int)1e9;
vector<pair<long long, int> >v;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   long long s=0;
   v.push_back(make_pair(s,0));
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>x;
      s+=(long long)x;
      v.push_back(make_pair(s,i));
   }
   sort(v.begin(),v.end());
   int j=0;
   for(int i=0;i<n;i++){
      while(j<n&& v[j]<make_pair(v[i].first+k,v[i].second) )++j;
      if(j<n && v[j].first==v[i].first+k && make_pair(v[j].second-v[i].second,-v[i].second) <make_pair(r-l,-l)){
         l=v[i].second;
         r=v[j].second;
      }
   }
   if(l==-1){
      cout<<-1<<"\n";
   }
   else cout<<l+1<<" "<<r<<"\n";
}
