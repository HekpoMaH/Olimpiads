#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define mp make_pair
#define se second
#define fi first
#define pb push_back
lli n,a,b;
const int nmax=1e5+9;
lli sum(lli idx){
   return idx*a+(idx-1)*idx/2*b;
}
bool chek(lli gl,lli t,lli m,lli r){
   //cout<<a+(r-1LL)*b<<" "<<sum(r)-sum(gl-1)<<" "<<t<<" "<<t*m<<"\n";
   if(a+(r-1LL)*b>t)return false;
   if(sum(r)-sum(gl-1)>t*m)return false;
   //cout<<"TRUE\n";
   return true;
}
lli dv(lli gl,lli t,lli m){
   lli l=gl-1,r=(int)1e9,mid;
   while(l+1<r){
      mid=(l+r)/2;
      //cout<<mid<<" "<<chek(gl,t,m,mid)<<"\n";
      if(chek(gl,t,m,mid))l=mid;
      else r=mid;
   }
   if(l!=gl-1)return l;
   else return -1;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>a>>b>>n;
   lli l,t,m;
   for(int i=1;i<=n;i++){
      cin>>l>>t>>m;
      cout<<dv(l,t,m)<<"\n";
   }
}
