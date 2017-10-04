#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
typedef long long lli;
const int inf=1e9;
lli n,m;
lli g[nmax][nmax];
lli ans=0;
lli prenum[nmax],st[nmax];
bool chek(lli x){
   memset(st,0,sizeof(st));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(g[i][j]<=x)st[j]++;
      }
   }
   for(int i=1;i<=n;i++){
      int idx=-1;
      for(int j=1;j<=n;j++){
         if(st[j]==0){
            idx=j;
            break;
         }
      }
      if(idx==-1)return false;
      st[idx]=-1;
      prenum[i]=idx;
      for(int j=1;j<=n;j++){
         if(g[idx][j]<=x)st[j]--;
      }
   }
   return true;
}
void solve(){
   lli lef=-1,righ=inf+9,mid;
   while(lef+1LL<righ){
      mid=(lef+righ)/2;
      if(chek(mid)){
         lef=mid;
      }
      else righ=mid;
   }
   if(lef>=inf)cout<<-1<<"\n";
   else cout<<lef<<"\n";
   chek(lef);
   for(int i=1;i<n;i++){
      cout<<prenum[i]<<" ";
   }
   cout<<prenum[n]<<"\n";

}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   for(int i=1;i<nmax;i++){
      for(int j=1;j<nmax;j++){
         g[i][j]=inf+1;
      }
   }
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      g[y][x]=z;
   }
   solve();
}
