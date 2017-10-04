#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
const int nmax=1009;
int a[nmax];
unordered_map<int,pii> m;
int n;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         m[a[i]+a[j]]=mp(a[i],a[j]);
      }
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(m.find(-(a[i]+a[j]))!=m.end()){
            cout<<m[-(a[i]+a[j])].first<<" "<<m[-(a[i]+a[j])].second<<" "<<a[i]<<" "<<a[j]<<"\n";
            return 0;
         }
      }
   }
   cout<<"NO SOLUTION\n";
}
