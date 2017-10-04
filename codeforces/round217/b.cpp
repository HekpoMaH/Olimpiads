#include<bits/stdc++.h>
using namespace std;
const int nmax=109;
set<int> pl[nmax];
int n;
bool chek(int x){
   for(int i=1;i<=n;i++){
      if(x==i)continue;
      int fl=0;
      for(set<int>::iterator it=pl[i].begin();it!=pl[i].end();it++){
         if(pl[x].find(*it)==pl[x].end()){
            fl=1;
            break;
         }
      }
      if(fl==0)return false;
   }
   return true;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int m;
      cin>>m;
      for(int j=1;j<=m;j++){
         int x;
         cin>>x;
         pl[i].insert(x);
      }
   }
   for(int i=1;i<=n;i++){
      if(chek(i)){
         cout<<"YES\n";
      }
      if(!chek(i)){
         cout<<"NO\n";
      }
   }
}
