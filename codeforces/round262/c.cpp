#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=2e5+9;
lli a[nmax];
int w;
int m,n;
bool chek(lli x){
   lli b[nmax],br=m;
   lli pl[nmax];
   memset(pl,0,sizeof(pl));
   for(int i=1;i<=n;i++)b[i]=a[i];
   lli cur=0;
   for(int i=1;i<=n;i++){
      cur+=pl[i];
      b[i]+=cur;
      assert(cur>=0);
      if(b[i]<x){
         if(x-b[i]>br)return false;
         pl[i+1]+=x-b[i];
         pl[i+w]-=x-b[i];
         br-=x-b[i];
         b[i]=x;
      }
   }
   return true;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>w;
   for(int i=1;i<=n;i++)cin>>a[i];
   lli l=1,r=1e14+1,mid;
   while(l+1<r){
      mid=l+(r-l)/2;
      if(chek(mid)==true)l=mid;
      else r=mid;
   }
   cout<<l<<"\n";
}
