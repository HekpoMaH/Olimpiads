#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
#define pb push_back
int n;
int mn=1e8;
int a[nmax];
void chek(int pos){
   vector<int> v;
   assert(v.size()==0);
   for(int i=1;i<=n;i++){
      if(i==pos)continue;
      v.pb(a[i]);
   }
   int dif=0;
   for(int i=0;i<v.size()-1;i++){
      dif=max(dif,v[i+1]-v[i]);
   }
   mn=min(mn,dif);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=2;i<n;i++){
      chek(i);
   }
   cout<<mn<<"\n";
}
